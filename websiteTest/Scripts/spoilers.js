document.addEventListener('DOMContentLoaded', () => {
  let xmlDoc = null;

  const dropZone = document.getElementById('dropZone');
  const fileInput = document.getElementById('xmlFileInput');
  const inspectorView = document.getElementById('inspectorView');
  
  const searchInput = document.getElementById('searchInput');
  const wothOnlyToggle = document.getElementById('wothOnlyToggle');

  // Tab Switching System
  const tabs = document.querySelectorAll('.tab');
  const tabContents = document.querySelectorAll('.tab-content');
  
  tabs.forEach(tab => {
    tab.addEventListener('click', (e) => {
        // Prevent default anchor clicks if tabs use <a> tags
        e.preventDefault();
        
        // Determine target ID from data-tab attribute, href attribute, or target attribute
        const targetId = tab.dataset.tab || tab.getAttribute('href')?.replace('#', '');
        if (!targetId) return;
        
        const targetContent = document.getElementById(targetId);
        
        if (targetContent) {
            // Clear active states across all tabs and content panels
            tabs.forEach(t => t.classList.remove('active'));
            tabContents.forEach(c => {
                c.classList.remove('active');
                c.style.display = 'none'; // Fallback force hide
                });
            // Activate clicked tab and corresponding section
            tab.classList.add('active');
            targetContent.classList.add('active');
            targetContent.style.display = 'block'; // Fallback force show
            }
        });
    });

  // Force input to accept XML extension explicitly
  if (fileInput) {
    fileInput.setAttribute('accept', '.xml, text/xml, application/xml');
  }

  // Click Trigger
  if (dropZone && fileInput) {
    dropZone.addEventListener('click', () => fileInput.click());
    
    // Drag & Drop
    dropZone.addEventListener('dragover', (e) => {
      e.preventDefault();
      e.stopPropagation();
      dropZone.classList.add('drag-over');
    });

    dropZone.addEventListener('dragleave', (e) => {
      e.preventDefault();
      e.stopPropagation();
      dropZone.classList.remove('drag-over');
    });

    dropZone.addEventListener('drop', (e) => {
      e.preventDefault();
      e.stopPropagation();
      dropZone.classList.remove('drag-over');
      
      const files = e.dataTransfer.files;
      if (files && files.length > 0) {
        parseXmlFile(files[0]);
      }
    });

    fileInput.addEventListener('change', (e) => {
      if (e.target.files && e.target.files.length > 0) {
        parseXmlFile(e.target.files[0]);
      }
    });
  }

  function parseXmlFile(file) {
    // Validate file extension loosely to prevent browser blockages
    if (!file.name.toLowerCase().endsWith('.xml')) {
      alert('Please upload a valid .xml spoiler log file.');
      return;
    }

    const reader = new FileReader();
    
    reader.onerror = () => {
      alert('Failed to read the file from your disk.');
    };

    reader.onload = (e) => {
      try {
        const rawContent = e.target.result;
        const parser = new DOMParser();
        xmlDoc = parser.parseFromString(rawContent, "text/xml");
        
        // Check for XML parsing syntax errors
        const parserError = xmlDoc.getElementsByTagName("parsererror");
        if (parserError.length > 0) {
          console.error("XML Parser Error:", parserError[0].textContent);
          throw new Error("Invalid XML formatting");
        }

        renderXmlSpoilerLog(rawContent);
      } catch (err) {
        console.error(err);
        alert('Could not parse XML spoiler log. Make sure the file isn\'t corrupted.');
      }
    };

    reader.readAsText(file);
  }

 // Add renderXmlStartingInventory() to your spoiler log rendering function
function renderXmlSpoilerLog(rawXmlText) {
  if (!xmlDoc) return;

  // Metadata Extraction
  const rootEl = xmlDoc.querySelector("spoiler-log") || xmlDoc.documentElement;
  const seed = rootEl?.getAttribute("seed") || "Custom";
  const version = rootEl?.getAttribute("version") || "v1.0.0";
  const hash = rootEl?.getAttribute("hash") || "N/A";
  
  let logic = "Glitchless";
  const logicSetting = xmlDoc.querySelector('setting[name="Logic"]');
  if (logicSetting) logic = logicSetting.textContent.trim();

  document.getElementById('metaSeed') && (document.getElementById('metaSeed').textContent = seed);
  document.getElementById('metaLogic') && (document.getElementById('metaLogic').textContent = logic);
  document.getElementById('metaVersion') && (document.getElementById('metaVersion').textContent = version);
  document.getElementById('seedHash') && (document.getElementById('seedHash').textContent = `Hash: ${hash}`);

  // Raw XML View
  const rawTarget = document.getElementById('rawXmlContent') || document.getElementById('rawJsonView');
  if (rawTarget) rawTarget.textContent = rawXmlText;

  // Render Sub-Views
  renderXmlWoth();
  renderXmlHints();
  renderXmlPlaythrough();
  renderXmlLocations();
  renderXmlStartingInventory(); // <--- Included here

  if (inspectorView) {
    inspectorView.classList.remove('hidden');
    inspectorView.scrollIntoView({ behavior: 'smooth' });
  }
}

// Render Starting Inventory Items
function renderXmlStartingInventory() {
  const container = document.getElementById('inventoryContainer');
  if (!container || !xmlDoc) return;

  container.innerHTML = '';

  const inventoryNodes = xmlDoc.querySelectorAll("starting-items > *, starting-inventory > *, start-inventory > *");

  if (inventoryNodes.length === 0) {
    container.innerHTML = '<p class="subtext" style="text-align: center; padding: 2rem;">No starting inventory specified in this spoiler log.</p>';
    return;
  }

  // Define names/tags that should display their inner text value
  const valueSpecificNodes = [
    "bomb bag",
    "bow",
    "bottle slot",
    "wallet upgrade",
    "health",
    "magic meter",
    "stick capacity",
    "nut capacity",
    "swamp skulltula tokens",
    "ocean skulltula tokens",
    "woodfall strays",
    "snowhead strays",
    "great bay strays",
    "stone tower strays",
    "gorons lullaby",
  ];

  inventoryNodes.forEach(node => {
    // 1. Get Node Name/Tag
    const rawName = node.getAttribute("name") || node.getAttribute("id") || node.tagName;
    const cleanName = rawName.replace(/_/g, ' '); // Formats "Wallet_Upgrade" to "Wallet Upgrade"
    
    // 2. Extract Value
    const textValue = node.textContent.trim();

    // 3. Check if this item should display its value
    const isValueItem = valueSpecificNodes.some(key => cleanName.toLowerCase().includes(key));
    
    // 4. Construct Display Text
    const displayText = (isValueItem && textValue) 
      ? `${cleanName}: <span class="text-purple">${textValue}</span>` 
      : cleanName;

    const card = document.createElement('div');
    card.className = 'inventory-card';
    card.innerHTML = `
      <i class="fa-solid fa-shield-halved"></i>
      <span>${displayText}</span>
    `;
    container.appendChild(card);
  });
}

  function getRegionGroup(locationName) {
    if (!locationName) return "Other Checks";
    if (locationName.startsWith("SCT") || locationName.startsWith("ECT") || locationName.startsWith("WCT") || locationName.startsWith("NCT") || locationName.startsWith("LP") || locationName.startsWith("Laundry") || 
    locationName.startsWith("SPI") ||  locationName.startsWith("Trading Post") || locationName.startsWith("Milk Bar") || locationName.startsWith("East Clock") || locationName.startsWith("Bombers' Hideout") || 
    locationName.startsWith("Bomb Shop")) return "Clock Town";
    if (locationName.startsWith("TF")) return "Termina Field";
    if (locationName.startsWith("RSS") || locationName.startsWith("SS") || locationName.startsWith("Potion Shop") || locationName.startsWith("DP") || locationName.startsWith("WF") || locationName.startsWith("SSH")) return "Southern Swamp & Woodfall";
    if (locationName.startsWith("RS") || locationName.startsWith("MV") || locationName.startsWith("TI") || locationName.startsWith("GV") || locationName.startsWith("Goron Shop") || locationName.startsWith("SH")) return "Snowhead & Mountain Village";
    if (locationName.startsWith("GBC") || locationName.startsWith("PR") || locationName.startsWith("ZC") || locationName.startsWith("ZH") || locationName.startsWith("Zora Shop") || locationName.startsWith("OSH")) return "Great Bay & Ocean";
    if (locationName.startsWith("RI") || locationName.startsWith("IC") || locationName.startsWith("IG") || locationName.startsWith("IST")) return "Ikana Canyon";
    if (locationName.startsWith("RR") || locationName.startsWith("MR")) return "Romani Ranch";
    if (locationName.startsWith("WT") || locationName.startsWith("WF SF") || locationName.includes("Oath") || locationName.includes("Princess")) return "Woodfall Temple";
    if (locationName.startsWith("ST")) return "Snowhead Temple";
    if (locationName.startsWith("GBT")) return "Great Bay Temple";
    if (locationName.startsWith("STT")) return "Stone Tower Temple";
    if (locationName.startsWith("PF")) return "Pirate's Fortress";
    if (locationName.startsWith("BTW") || locationName.startsWith("Ikana Castle") || locationName.startsWith("Secret Shrine")) return "Ikana Canyon Dungeons";
    if (locationName.includes("Moon")) return "The Moon";
    if (locationName.includes("Starting") || locationName.includes("of Time") || locationName.startsWith("Deku Mask") || locationName.includes("Healing") || locationName.includes("Notebook")) return "Clock Tower";
    return "Other Checks";
  }

  function renderXmlLocations() {
    const container = document.getElementById('locationsContainer');
    if (!container || !xmlDoc) return;
    container.innerHTML = '';

    const query = searchInput ? searchInput.value.toLowerCase().trim() : '';
    const wothOnly = wothOnlyToggle ? wothOnlyToggle.checked : false;

    const wothLocations = new Set();
    xmlDoc.querySelectorAll("way-of-the-hero-locations > location").forEach(el => {
      const name = el.getAttribute("name");
      if (name) wothLocations.add(name);
    });

    const allLocationNodes = xmlDoc.querySelectorAll("all-locations > location");
    const grouped = {};

    allLocationNodes.forEach(node => {
      const locationName = node.getAttribute("name") || "Unknown Location";
      const itemName = node.textContent.trim() || "Empty";
      const isWoth = wothLocations.has(locationName);
      const regionName = getRegionGroup(locationName);

      const matchesQuery = locationName.toLowerCase().includes(query) || 
                           itemName.toLowerCase().includes(query) || 
                           regionName.toLowerCase().includes(query);

      if (matchesQuery && (!wothOnly || isWoth)) {
        if (!grouped[regionName]) grouped[regionName] = [];
        grouped[regionName].push({ location: locationName, item: itemName, isWoth });
      }
    });

    for (const [regionName, rows] of Object.entries(grouped)) {
      if (rows.length === 0) continue;

      const regionCard = document.createElement('div');
      regionCard.className = 'region-block';

      let tableHtml = `
        <h4 class="region-title"><i class="fa-solid fa-map"></i> ${regionName}</h4>
        <table class="spoiler-table">
          <thead>
            <tr>
              <th>Location</th>
              <th>Item Placed</th>
              <th style="width: 100px;">Tag</th>
            </tr>
          </thead>
          <tbody>
      `;

      rows.forEach(row => {
        tableHtml += `
          <tr>
            <td>${row.location}</td>
            <td class="item-name">${row.item}</td>
            <td>${row.isWoth ? '<span class="badge badge-woth">WOTH</span>' : '<span class="badge badge-junk">Check</span>'}</td>
          </tr>
        `;
      });

      tableHtml += '</tbody></table>';
      regionCard.innerHTML = tableHtml;
      container.appendChild(regionCard);
    }

    if (container.children.length === 0) {
      container.innerHTML = '<p class="subtext" style="text-align: center; padding: 2rem;">No matching checks found for your search filters.</p>';
    }
  }

  function renderXmlWoth() {
    const container = document.getElementById('wothContainer');
    if (!container || !xmlDoc) return;
    container.innerHTML = '';

    const wothNodes = xmlDoc.querySelectorAll("way-of-the-hero-locations > location");
    wothNodes.forEach(node => {
      const location = node.getAttribute("name") || "Unknown Location";
      const item = node.textContent.trim();

      const card = document.createElement('div');
      card.className = 'woth-card';
      card.innerHTML = `
        <div class="woth-item"><i class="fa-solid fa-crown text-purple"></i> ${item}</div>
        <div class="woth-location">${location}</div>
      `;
      container.appendChild(card);
    });
  }

  function renderXmlHints() {
    const container = document.getElementById('hintsContainer');
    if (!container || !xmlDoc) return;
    container.innerHTML = '';

    const hintNodes = xmlDoc.querySelectorAll("hints > hint");
    hintNodes.forEach(node => {
      const stoneName = node.getAttribute("location") || "Gossip Stone";
      const hintText = node.textContent.trim().replace(/#([^#]+)#/g, '<span class="text-purple">$1</span>');

      const card = document.createElement('div');
      card.className = 'hint-card';
      card.innerHTML = `
        <strong><i class="fa-solid fa-comment"></i> ${stoneName}</strong>
        <p class="hint-quote">"${hintText}"</p>
      `;
      container.appendChild(card);
    });
  }

  function renderXmlPlaythrough() {
    const container = document.getElementById('playthroughContainer');
    if (!container || !xmlDoc) return;
    container.innerHTML = '';

    const sphereNodes = xmlDoc.querySelectorAll("playthrough > sphere");
    sphereNodes.forEach(sphere => {
      const level = sphere.getAttribute("level") || "Sphere";
      const locations = sphere.querySelectorAll("location");

      const sphereCard = document.createElement('div');
      sphereCard.className = 'sphere-block';
      
      let listItems = "";
      locations.forEach(loc => {
        const locName = loc.getAttribute("name");
        const itemName = loc.textContent.trim();
        listItems += `<li><i class="fa-solid fa-angle-right text-purple"></i> <strong>${locName}</strong>: ${itemName}</li>`;
      });

      sphereCard.innerHTML = `
        <h4 class="sphere-title">Sphere ${level}</h4>
        <ul class="sphere-list">${listItems}</ul>
      `;
      container.appendChild(sphereCard);
    });
  }

  if (searchInput) searchInput.addEventListener('input', renderXmlLocations);
  if (wothOnlyToggle) wothOnlyToggle.addEventListener('change', renderXmlLocations);
});
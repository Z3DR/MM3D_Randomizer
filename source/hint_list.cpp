#include "hint_list.hpp"
//#include "custom_messages.hpp"

#include <array>

//using namespace CustomMessages;

static std::array<HintText, KEY_ENUM_MAX> hintTable;

void HintTable_Init() {
    /*--------------------------
    |       GENERAL TEXT       |
    --------------------------*/
    hintTable[NONE]            = HintText::Exclude({Text{"No Hint",                     "INDICE MANQUANT",              "",                             "Kein Hinweis"}});
    hintTable[PREFIX]          = HintText::Exclude({Text{"They say that ",              "Selon moi, ",                  "Según dicen, ",                "Man erzählt sich, "}});
    hintTable[WAY_OF_THE_HERO] = HintText::Exclude({Text{" is on the way of the hero.", " est sur le chemin du héros.", " está en la senda del héroe.", " verlaufe der Weg des Helden."}});
    hintTable[PLUNDERING]      = HintText::Exclude({Text{"plundering ",                 "explorer ",                    "inspeccionar ",                "zu plündern "}});
    hintTable[FOOLISH]         = HintText::Exclude({Text{" is a foolish choice.",       " est futile.",                 " es una mala decisión.",       " sei eine närrische Wahl."}});
    hintTable[CAN_BE_FOUND_AT] = HintText::Exclude({Text{"can be found at",             "se trouve dans",               "se encuentra en",              "findet man beim"}});
    hintTable[HOARDS]          = HintText::Exclude({Text{"hoards",                      "recèle",                       "atesora",                      "hortet"}});

    //hintTable[ITEM] = HintText::Item({Text{"English", "French", "Spanish"}});
    /*--------------------------
    |        ITEM HINTS        |
    --------------------------*/
    hintTable[KOKIRI_SWORD] = HintText::Item({
            //obscure
            Text{"a forest blade", "une lame sylvestre", "acero del bosque", "eine Klinge aus dem Wald"}
        },  //clear
            Text{"the Kokiri Sword", "l'épée Kokiri", "la Espada Kokiri", "das Kokiri-Schwert"}
    );
    hintTable[RAZOR_SWORD] = HintText::Item({
            //obscure
            Text{"a sharp blade", "une lame aiguisée", "acero tajante", "eine scharfe Klinge"}
        },  //clear
            Text{"the Razor Sword", "la lame rasoir", "la Espada Afilada", "das Elfenschwert"}
    );
    hintTable[GILDED_SWORD] = HintText::Item({
            //obscure
            Text{"a very sharp blade", "une lame aiguisée deux fois", "acero súper tajante", "eine überaus scharfe Klinge"}
        },  //clear
            Text{"the Gilded Sword", "la lame dorée", "la Espada de Esmeril", "die Schmirgelklinge"}
    );
    hintTable[GREAT_FAIRYS_SWORD] = HintText::Item({
            //obscure
            Text{"A powerful fairy blade", "une lame féerique", "el poderoso acero de las hadas", "eine mächtige Feenklinge"}
        },  //clear
            Text{"the Great Fairy's Sword", "l'épée de la grande fée", "la Espada de la Gran Hada", "das Feenschwert", "", "la grande épée des fées", ""}
    );
    hintTable[HEROS_SHIELD] = HintText::Item({
            //obscure
            Text{"a basic shield", "un bouclier basique", "un blasón básico", "ein einfacher Schild"}
        },  //clear
            Text{"a Hero's Shield", "le bouclier du Héros", "el Escudo del Héroe", "einen Heroenschild"}
    );
    hintTable[MIRROR_SHIELD] = HintText::Item({
            //obscure
            Text{"a reflective shield", "un bouclier réfléchissant", "un blasón lustroso", "ein spiegelnder Schild"}
        },  //clear
            Text{"the Mirror Shield", "le bouclier miroir", "el Escudo Espejo", "den Spiegelschild"}
    );
    hintTable[DEKU_STICK] = HintText::Item({
            //obscure
            Text{"a flammable weapon", "une arme inflammable", "un arma flamable", "eine brennbare Waffe"}
        },  //clear
            Text{"a Deku Stick", "un bâton mojo", "un palo Deku", "einen Deku-Stab"}
    );
    hintTable[LAND_TITLE] = HintText::Item({
            //obscure
            Text{"a property deal", "un accord immobilier", "una escritura de propiedad", "ein Grundstücksvertrag"}
        },  //clear
            Text{"a Land Title Deed", "un titre de terre", "una Escritura de propiedad de la Ciudad", "eine Land-Urkunde"}
    );
    hintTable[SWAMP_TITLE] = HintText::Item({
            //obscure
            Text{"a property deal", "un accord immobilier", "una escritura de propiedad", "ein Grundstücksvertrag"}
        },  //clear
            Text{"a Swamp Title Deed", "un titre de marais", "una Escritura de propiedad del Pantano", "eine Sumpf-Urkunde"}
    );
    hintTable[MOUNTAIN_TITLE] = HintText::Item({
            //obscure
            Text{"a property deal", "un accord immobilier", "una escritura de propiedad", "ein Grundstücksvertrag"}
        },  //clear
            Text{"a Mountain Title Deed", "un titre de montagne", "una Escritura de propiedad de la Montañaa", "eine Berg-Urkunde"}
    );
    hintTable[OCEAN_TITLE] = HintText::Item({
            //obscure
            Text{"a property deal", "un accord immobilier", "una escritura de propiedad", "ein Grundstücksvertrag"}
        },  //clear
            Text{"an Ocean Title Deed", "un titre d'océan", "una Escritura de propiedad del Océano", "eine Meer-Urkunde"}
    );
    hintTable[BOMBERS_NOTEBOOK] = HintText::Item({
            //obscure
            Text{"a handy notepad", "un cahier pratique", "una útil libreta", "ein praktisches Notizbuch"}
        },  //clear
            Text{"the Bombers' Notebook", "le carnet des Bombers", "el Cuaderno de los Bomber", "das Notizbuch der Bomber", "", "le journal des Bombers", ""}
    );
    hintTable[ROOM_KEY] = HintText::Item({
            //obscure
            Text{"a hotel door opener", "un croche-porte hôtelier", "una llave de hotel", "ein Türöffner für ein Hotelzimmer"}
        },  //clear
            Text{"a Room Key", "une clé de chambre", "una Llave del cuarto", "einen Zimmerschlüssel"}
    );
    hintTable[LETTER_KAFEI] = HintText::Item({
            //obscure
            Text{"a lover's letter", "une lettre de dulcinée", "una carta de un amante", "ein Liebesbrief"}
        },  //clear
            Text{"the Letter to Kafei", "la lettre pour Kafei", "la Carta a Kafei", "den Brief an Kafei"}
    );
    hintTable[PENDANT_MEMORIES] = HintText::Item({
            //obscure
            Text{"a cherished necklace", "un collier chéri", "un preciado collar", "eine geliebte Halskette"}
        },  //clear
            Text{"the Pendant of Memories", "le pendentif des amoureux", "el Colgante de recuerdos", "den Glücksbringer"}
    );
    hintTable[LETTER_MAMA] = HintText::Item({
            //obscure
            Text{"A special delivery", "une livraison spéciale", "una entrega especial", "eine besondere Zustellung"}
        },  //clear
            Text{"the Letter to Mama", "la lettre express pour Maman", "la Entrega especial a mamá", "die Eilpost an Mama", "", "la lettre express pour maman", ""}
    );
    hintTable[MOONS_TEAR] = HintText::Item({
            //obscure
            Text{"a lunar teardrop", "un suintement lunaire", "una gota astral", "eine Träne des Mondes"}
        },  //clear
            Text{"a Moon's Tear", "une larme de lune", "la Lágrima de luna", "eine Mondträne"}
    );
    hintTable[SPIN_ATTACK] = HintText::Item({
            //obscure
            Text{"a magic attack", "un cercle agrandi", "un ataque mágico", "ein magischer Angriff"}
        },  //clear
            Text{"the mastered Spin Attack", "l'attaque circulaire perfectionnée", "el Ataque giratorio", "die Wirbelattacke"}
    );
    hintTable[LENS_OF_TRUTH] = HintText::Item({
            //obscure
            Text{"a lie detector", "un perce-mensonge", "un detector de mentiras", "ein Lügendetektor"}
        },  //clear
            Text{"the Lens of Truth", "la loupe de vérité", "la Lupa de la Verdad", "das Auge der Wahrheit", "", "le monocle de vérité", ""}
    );
    hintTable[HEROS_BOW] = HintText::Item({
            //obscure
            Text{"a bow", "un bâton affublé d'une corde", "un lanzador de dardos", "ein Bogen"}
        },  //clear
            Text{"the Hero's Bow", "l'arc du Héros", "el Arco del héroe", "den Heroenbogen"}
    );
    hintTable[FIRE_ARROWS] = HintText::Item({
            //obscure
            Text{"the power of fire", "la pyromanie", "el poder del fuego", "die Macht des Feuers"}
        },  //clear
            Text{"the Fire Arrow", "la flèche de feu", "la Flecha de fuego", "die Feuerpfeile"}
    );
    hintTable[ICE_ARROWS] = HintText::Item({
            //obscure
            Text{"the power of ice", "une pompe à chaleur", "el poder del hielo", "die Macht des Eises"}
        },  //clear
            Text{"the Ice Arrow", "la flèche de glace", "la Flecha de hielo", "die Eispfeile"}
    );
    hintTable[LIGHT_ARROWS] = HintText::Item({
            //obscure
            Text{"the power of light", "la lumière", "el poder de la luz", "die Macht des Lichts"}
        },  //clear
            Text{"the Light Arrow", "la flèche de lumière", "la Flecha de luz", "die Lichtpfeile"}
    );
    hintTable[HOOKSHOT] = HintText::Item({
            //obscure
            Text{"a chain and grapple", "une force de traction", "una cadena con pico", "eine Kette mit Enterhaken"}
        },  //clear
            Text{"the Hookshot", "le grappin", "el Gancho", "den Fanghaken"}
    );
    hintTable[MAGIC_BEAN] = HintText::Item({
            //obscure
            Text{"a plant seed", "un plancher en devenir", "una semilla peculiar", "ein Pflanzensamen"}
        },  //clear
            Text{"a Magic Bean", "un haricot magique", "una habichuela mágica", "eine Wundererbse"}
    );
    hintTable[MAGIC_BEAN_PACK] = HintText::Item({
            //obscure
            Text{"multiple plant seeds", "un sac de munitions de jardin", "varias semillas peculiares", "mehrere Pflanzensamen"}
        },  //clear
            Text{"a pack of Magic Beans", "un paquet de haricots magiques", "un lote de habichuelas mágicas", "ein Paket an Wundererbsen"}
    );
    hintTable[DOUBLE_DEFENSE] = HintText::Item({
            //obscure
            Text{"magical defence", "la peau dure", "defensa mágica", "magische Verteidigung"}
        },  //clear
            Text{"Double Defense", "la résistance double", "Poder defensivo doble", "Verstärkten Rüstungsschutz"}
    );
    hintTable[OCARINA_OF_TIME] = HintText::Item({
            //obscure
            Text{"a musical instrument", "un instrument de musique", "", "ein Musikinstrument"}
        },  //clear
            Text{"the Ocarina of Time", "l'ocarina du temps", "", "die Okarina der Zeit"}
    );
    hintTable[PICTOGRAPH_BOX] = HintText::Item({
            //obscure
            Text{"a capture device", "une chambre obscure", "un dispositivo de capturas", "ein Aufnahmegerät"}
        },  //clear
            Text{"the Picto Box", "la boîte à image", "la Caja Luminográfica", "die Foto-Box"}
    );
    hintTable[POWDER_KEG] = HintText::Item({
            //obscure
            Text{"an explosive barrel", "un baril explosif", "un barril explosivo", "ein explosives Fass"}
        },  //clear
            Text{"a Powder Keg", "un baril de poudre", "el Barril de Pólvora", "ein Pulverfass"}
    );
    hintTable[KEATON_MASK] = HintText::Item({
            //obscure
            Text{"a popular mask", "un masque populaire", "una máscara popular", "eine beliebte Maske"}
        },  //clear
            Text{"the Keaton Mask", "le masque de keaton", "la Máscara keaton", "die Fuchs-Maske", "", "le masque de renard", ""}
    );
    hintTable[BUNNY_HOOD] = HintText::Item({
            //obscure
            Text{"the ears of the wild", "des zoulies noreilles toutes duveteuses", "las orejas salvajes", "die Ohren der Wildnis"}
        },  //clear
            Text{"the Bunny Hood", "la capuchon de lapin", "la Capucha de conejo", "die Hasenohren", "", "le masque de lapin", ""}
    );
    hintTable[GORON_MASK] = HintText::Item({
            //obscure
            Text{"a mountain spirit", "une âme montagnarde", "un espíritu de la montaña", "ein Bergesgeist"}
        },  //clear
            Text{"the Goron Mask", "le masque goron", "la Máscara Goron", "die Goronen-Haut"}
    );
    hintTable[ZORA_MASK] = HintText::Item({
            //obscure
            Text{"an ocean spirit", "une âme musicienne", "un espíritu del océano", "ein Geist des Meeres"}
        },  //clear
            Text{"the Zora Mask", "le masque zora", "la Máscara Zora", "die Zora-Schuppen"}
    );
    hintTable[DEKU_MASK] = HintText::Item({
            //obscure
            Text{"a forest spirit", "une âme sylvestre", "un espíritu del bosque", "ein Waldgeist"}
        },  //clear
            Text{"the Deku Mask", "le masque mojo", "la Máscara Deku", "die Deku-Schale"}
    );
    hintTable[POSTMANS_HAT] = HintText::Item({
            //obscure
            Text{"a hard worker's hat", "l'uniforme d'un homme pressé", "el gorro de un trabajador dedicado", "die Mütze eines fleißigen Arbeiters"}
        },  //clear
            Text{"the Postman's Hat", "la casquette du facteur", "la Gorra de cartero", "die Mütze des Postboten"}
    );
    hintTable[ALL_NIGHT_MASK] = HintText::Item({
            //obscure
            Text{"insomnia", "un crise d'insomnie", "el insomnio", "Schlaflosigkeit"}
        },  //clear
            Text{"the All-Night Mask", "le masque de la nuit blanche", "la Máscara para trasnochar", "die Maske der Nacht"}
    );
    hintTable[BLAST_MASK] = HintText::Item({
            //obscure
            Text{"a dangerous mask", "un masque dangereux", "una máscara peligrosa", "eine gefährliche Maske"}
        },  //clear
            Text{"the Blast Mask", "le masque explosif", "la Máscara explosiva", "die Ka-Bumm-Maske", "", "le masque d'explosion", ""}
    );
    hintTable[STONE_MASK] = HintText::Item({
            //obscure
            Text{"inconspicousness", "la discrétion", "discreción", "Unauffälligkeit"}
        },  //clear
            Text{"the Stone Mask", "le masque de pierre", "la Máscara de piedra", "die Fels-Maske", "", "le masque de la pierre", ""}
    );
    hintTable[GREAT_FAIRYS_MASK] = HintText::Item({
            //obscure
            Text{"a friend of fairies", "un aimant à fées", "la amistad de las hadas", "eine Freundin der Feen"}
        },  //clear
            Text{"the Great Fairy's Mask", "le masque de la grande fée", "la Máscara de la Gran Hada", "die Feen-Maske", "", "le masque des grandes fées", ""}
    );
    hintTable[BREMEN_MASK] = HintText::Item({
            //obscure
            Text{"a bird's mask", "un bec de piaf", "una máscara aviar", "die Maske eines Vogels"}
        },  //clear
            Text{"the Bremen Mask", "le masque de Brême", "la Máscara de Bremen", "die Bremer Maske"}
    );
    hintTable[DON_GEROS_MASK] = HintText::Item({
            //obscure
            Text{"a conductor's mask", "un masque de chef d'orchestre", "la máscara de un director", "die Maske eines Dirigenten"}
        },  //clear
            Text{"Don Gero's Mask", "le masque de Don Gero", "la Máscara de Don Gero", "Don Geros Maske"}
    );
    hintTable[MASK_OF_SCENTS] = HintText::Item({
            //obscure
            Text{"a pig's mask", "un nez sensible", "el olor a victoria", "die Maske eines Schweins"}
        },  //clear
            Text{"the Mask of Scents", "le masque des parfums", "la Máscara de aromas", "die Maske der Düfte"}
    );
    hintTable[ROMANIS_MASK] = HintText::Item({
            //obscure
            Text{"a cow's mask", "une carte de membre", "una prueba de madurez", "die Maske einer Kuh"}
        },  //clear
            Text{"Romani's Mask", "le masque Romani", "la Máscara de Romani", "Romanis Maske"}
    );
    hintTable[CIRCUS_LEADERS_MASK] = HintText::Item({
            //obscure
            Text{"a mask of sadness", "un masque dégoulinant", "un símbolo de melancolía", "eine Maske der Trauer"}
        },  //clear
            Text{"the Troupe Leader's Mask", "le masque du chef de la troupe", "la Máscara del jefe de la compañía", "die Maske des Zirkusdirektors"}
    );
    hintTable[KAFEIS_MASK] = HintText::Item({
            //obscure
            Text{"the mask of a missing one", "un portrait robot", "la cara de alguien extraviado", "die Maske eines Vermissten"}
        },  //clear
            Text{"Kafei's Mask", "le masque de Kafei", "la Máscara de Kafei", "Kafeis Maske"}
    );
    hintTable[COUPLES_MASK] = HintText::Item({
            //obscure
            Text{"the mark of a couple", "un serment d'amour", "la marca de una pareja", "das Zeichen eines Paares"}
        },  //clear
            Text{"the Couple's Mask", "le masque des amoureux", "la Máscara de los novios", "die Maske der Liebenden"}
    );
    hintTable[KAMAROS_MASK] = HintText::Item({
            //obscure
            Text{"dance moves", "un cours de danse", "unos buenos pasos de baile", "Tanzschritte"}
        },  //clear
            Text{"Kamaro's Mask", "le masque de Kamaro", "la Máscara de Kamaro", "Kamaros Maske"}
    );
    hintTable[GIBDOS_MASK] = HintText::Item({
            //obscure
            Text{"a mask of monsters", "un visage hideux", "una fachada monstruosa", "eine Maske der Monster"}
        },  //clear
            Text{"the Gibdo Mask", "le masque de gibdo", "la Máscara de Gibdo", "die Gibdo-Maske"}
    );
    hintTable[GAROS_MASK] = HintText::Item({
            //obscure
            Text{"the mask of spies", "une cagoule d'espion", "el símbolo de espionaje", "die Maske der Spione"}
        },  //clear
            Text{"Garo's Mask", "la cagoule garo", "la Máscara de Garo", "die Garo-Maske"}
    );
    hintTable[CAPTAINS_HAT] = HintText::Item({
            //obscure
            Text{"a commanding presence", "l'autorité sur une armée", "una presencia imponente", "eine gebieterische Erscheinung"}
        },  //clear
            Text{"the Captain's Hat", "le heaume du capitaine", "la Casco del capitán", "den Helm des Hauptmanns"}
    );
    hintTable[GIANTS_MASK] = HintText::Item({
            //obscure
            Text{"a growth spurt", "une poussée de croissance", "un súbito crecimiento", "ein plötzlicher Wachstumsschub"}
        },  //clear
            Text{"the Giant's Mask", "le masque du géant", "la Máscara del gigante", "die Maske des Giganten"}
    );
    hintTable[FIERCE_DEITY_MASK] = HintText::Item({
            //obscure
            Text{"the wrath of a god", "une colère divine", "la ira divina", "der Zorn eines Gottes"}
        },  //clear
            Text{"the Fierce Deity's Mask", "le masque du mauvais génie", "la Máscara de la Fiera Deidad", "das Gesicht der grimmigen Gottheit", "", "le masque du Dieu Démon", ""}
    );
    hintTable[MASK_OF_TRUTH] = HintText::Item({
            //obscure
            Text{"a piercing gaze", "un masque interprète", "una mirada penetrante", "ein durchdringender Blick"}
        },  //clear
            Text{"the Mask of Truth", "le masque de vérité", "la Máscara de la verdad", "die Maske der Wahrheit"}
    );
    hintTable[FISHING_PASS] = HintText::Item({
            //obscure
            Text{"a fishing pass", "un papier sans utilité", "un cupón de pesca", "ein Angelschein"}
        },  //clear
            Text{"a Fishing Pass", "un billet de pêche", "una entrada de la zona de pesca", "einen Angel-Pass", "", "un ticket de pêche", ""}
    );
    hintTable[ICE_TRAP] = HintText::Item({
            //obscure
            Text{"a frosty surprise", "un coup de froid", "una gélida sorpresa", "eine frostige Überraschung"}
        },  //clear
            Text{"an Ice Trap", "un piège de glace", "una trampa de hielo", "eine Eisfalle"}
    );
    hintTable[ZORA_EGG] = HintText::Item({
            //obscure
            Text{"a zora egg", "une progéniture dérobée", "un huevo Zora", "ein Zora-Ei"}
        },  //clear
            Text{"a Zora Egg", "un œuf de Zora", "un Huevo Zora", "ein Zora-Ei"}
    );
//SKULLTULA TOKENS
    hintTable[SWAMP_SKULLTULA_TOKEN] = HintText::Item({
            //obscure
            Text{"a golden token", "une fraction de malédiction", "un símbolo dorado", "ein goldenes Wappen"}
        },  //clear
            Text{"a Swamp Skulltula Token", "une âme de skulltula d'or des marais", "un símbolo de Skulltula del Pantano", "Sumpf-Symbol einer goldenen Skulltula"}
    );
    hintTable[OCEANSIDE_SKULLTULA_TOKEN] = HintText::Item({
            //obscure
            Text{"a golden token", "une fraction de nettoyage", "un símbolo dorado", "ein goldenes Wappen"}
        },  //clear
            Text{"an Oceanside Skulltula Token", "une âme de skulltula d'or de la côte", "un símbolo de Skulltula del Océano", "Meer-Symbol einer goldenen Skulltula"}
    );
//Stray Fairies
    hintTable[CT_STRAY_FAIRY] = HintText::Item({
            //obscure
            Text{"a lost fairy", "un fragment d'être", "una hada perdida", "eine verlorene Fee"}
        },  //clear
            Text{"the Clock Town Stray Fairy", "la fée égarée de Cadranbourg", "la hada extraviada de la Ciudad", "eine verirrte Fee aus Unruh-Stadt", "", "la fée égarée de Bourg-Clocher", ""}
    );
    hintTable[WF_STRAY_FAIRY] = HintText::Item({
            //obscure
            Text{"a lost fairy", "un fragment d'être", "una hada perdida", "eine verlorene Fee"}
        },  //clear
            Text{"a Woodfall Stray Fairy", "une fée égarée du temple de Boisé-les-Cascades", "una hada extraviada del Bosque Catarata", "eine verirrte Fee aus dem Dämmerwald", "", "une fée égarée du temple de Bois-Cascade", ""}
    );
    hintTable[SH_STRAY_FAIRY] = HintText::Item({
            //obscure
            Text{"a lost fairy", "un fragment d'être", "una hada perdida", "eine verlorene Fee"}
        },  //clear
            Text{"a Snowhead Stray Fairy", "une fée égarée du temple du Pic des neiges", "una hada extraviada del Pico Nevado", "eine verirrte Fee vom Pic-Hibernia", "", "une fée égarée du temple du pic des Neiges", ""}
    );
    hintTable[GBT_STRAY_FAIRY] = HintText::Item({
            //obscure
            Text{"a lost fairy", "un fragment d'être", "una hada perdida", "eine verlorene Fee"}
        },  //clear
            Text{"a Great Bay Stray Fairy", "une fée égarée du temple de la Grande Baie", "una hada extraviada de la Gran Bahía", "eine verirrte Fee aus der Schädelbucht"}
    );
    hintTable[ST_STRAY_FAIRY] = HintText::Item({
            //obscure
            Text{"a lost fairy", "un fragment d'être", "una hada perdida", "eine verlorene Fee"}
        },  //clear
            Text{"a Stone Tower Stray Fairy", "une fée égarée du temple de la forteresse de pierre", "una hada extraviada de la Torre de Piedra", "eine verirrte Fee aus dem Felsenturm"}
    );
//PROGRESSIVE ITEMS (unused currently)
    hintTable[PROGRESSIVE_SWORD] = HintText::Item({
            //obscure
            Text{"a progressive sword", "un aiguisage", "una espada progresiva", "ein fortschreitendes Schwert"}
        },  //clear
            Text{"a progressive sword", "une lame progressive", "una espada progresiva", "ein Schwert-Upgrade"}
    );
    hintTable[PROGRESSIVE_BOMB_BAG] = HintText::Item({
            //obscure
            Text{"a progressive bomb bag", "une poche poudreuse", "un saco de bombas progresivo", "ein wachsender Bombenbeutel"}
        },  //clear
            Text{"a progressive bomb bag", "un sac de bombes progressif", "un saco de bombas progresivo", "ein Bombentaschen-Upgrade"}
    );
    hintTable[PROGRESSIVE_BOW] = HintText::Item({
            //obscure
            Text{"a progressive bow", "une capacité de tir accrue", "un arco progresivo", "ein wachsender Bogen"}
        },  //clear
            Text{"a progressive quiver", "un carquois progressif", "un carcaj progresivo", "ein Köcher-Upgrade"}
    );
    hintTable[PROGRESSIVE_WALLET] = HintText::Item({
            //obscure
            Text{"a progressive wallet", "du talent pour le économies", "una bolsa progresiva", "ein wachsender Geldbeutel"}
        },  //clear
            Text{"a progressive wallet", "une bourse progressive", "una bolsa de rupias progresiva", "ein Geldbörsen-Upgrade"}
    );
    hintTable[PROGRESSIVE_MAGIC_METER] = HintText::Item({
            //obscure
            Text{"progressive magic meter", "de l'endurance sorcière", "poder mágico progresivo", "wachsende Magiekraft"}
        },  //clear
            Text{"a progressive magic power", "une amélioration d'énergie magique", "un poder mágico progresivo", "ein Magie-Upgrade"}
    );
    hintTable[PROGRESSIVE_LULLABY] = HintText::Item({
            //obscure
            Text{"a progressive lullaby", "une fraction de mélodie", "una canción de cuna progresiva", ""}
        },  //clear
            Text{"a progressive lullaby", "une berceuse progressive", "una canción de cuna progresiva", ""}
    );
    //PROGRESSIVE_BOMBCHUS
//BOTTLE ITEMS
    hintTable[EMPTY_BOTTLE] = HintText::Item({
            //obscure
            Text{"a glass container", "un récipient étanche", "un contenedor de cristal", "ein gläsernes Gefäß"}
        },  //clear
            Text{"an Empty Bottle", "un flacon vide", "una botella vacía", "eine leere Flasche"}
    );
    hintTable[EMPTY_BOTTLE1] = HintText::Item({
            //obscure
            Text{"a glass container", "un récipient étanche", "un contenedor de cristal", "ein gläsernes Gefäß"}
        },  //clear
            Text{"an Empty Bottle", "un flacon vide", "una botella vacía", "eine leere Flasche"}
    );
    hintTable[EMPTY_BOTTLE2] = HintText::Item({
            //obscure
            Text{"a glass container", "un récipient étanche", "un contenedor de cristal", "ein gläsernes Gefäß"}
        },  //clear
            Text{"an Empty Bottle", "un flacon vide", "una botella vacía", "eine leere Flasche"}
    );
    hintTable[BOTTLE_WITH_MILK] = HintText::Item({
            //obscure
            Text{"a dairy product", "une double dose de calcium", "un producto lácteo", "ein Milchprodukt"}
        },  //clear
            Text{"a Milk Bottle", "un flacon de lait", "una botella de leche", "eine Flasche Milch"}
    );
    hintTable[BOTTLE_WITH_RED_POTION] = HintText::Item({
            //obscure
            Text{"a vessel of health", "la santé en bouteille", "un brebaje vital", "ein Gefäß voller Gesundheit"}
        },  //clear
            Text{"a Red Potion Bottle", "un flacon de potion rouge", "una botella de poción roja", "eine Flasche mit rotem Elixier"}
    );
    hintTable[BOTTLE_WITH_GREEN_POTION] = HintText::Item({
            //obscure
            Text{"a magic potion", "de la magie à boire", "un brebaje mágico", "ein magischer Trank"}
        },  //clear
            Text{"a Green Potion Bottle", "un flacon de potion verte", "una botella de poción verde", "eine Flasche mit grünem Elixier"}
    );
    hintTable[BOTTLE_WITH_BLUE_POTION] = HintText::Item({
            //obscure
            Text{"a blue drink", "une boisson fongique", "un brebaje cerúleo", "ein blaues Getränk"}
        },  //clear
            Text{"a Blue Potion Bottle", "un flacon de potion bleue", "una botella de poción azul", "eine Flasche mit blauem Elixier"}
    );
    hintTable[BOTTLE_WITH_FAIRY] = HintText::Item({
            //obscure
            Text{"a fairy", "un farfadet", "una hada", "eine Fee"}
        },  //clear
            Text{"a Fairy Bottle", "une fée en flacon", "una botella con hada", "eine Flasche mit einer kleine Fee"}
    );
    hintTable[BOTTLE_WITH_FISH] = HintText::Item({
            //obscure
            Text{"something fresh", "l'éclat d'argent au fond de l'eau", "algo fresco", "etwas Frisches"}
        },  //clear
            Text{"a Fish Bottle", "un poisson en flacon", "una botella con pez", "eine Flasche mit einem Fisch"}
    );
    hintTable[CHATEAU_ROMANI] = HintText::Item({
            //obscure
            Text{"an adult beverage", "un breuvage adulte", "un trago para adultos", "ein Getränk für Erwachsene"}
        },  //clear
            Text{"a Chateau Romani Bottle", "un flacon de Cuvée Romani", "una botella de Reserva Romani", "eine Flasche mit Chateau Romani"}
    );
    hintTable[BOTTLE_WITH_BUGS] = HintText::Item({
            //obscure
            Text{"an insect", "un fouisseur", "un insecto", "ein Insekt"}
        },  //clear
            Text{"a Bug Bottle", "un insecte en flacon", "una botella con insecto", "eine Flasche mit Käfern"}
    );
    hintTable[BOTTLE_WITH_POE] = HintText::Item({
            //obscure
            Text{"a captured spirit", "une hantise violette", "un espíritu apresado", "ein gefangener Geist"}
        },  //clear
            Text{"a Poe Bottle", "un esprit en flacon", "una botella con Poe", "eine Flasche mit einem Irrlicht"}
    );
    hintTable[BOTTLE_WITH_BIG_POE] = HintText::Item({
            //obscure
            Text{"a large captured spirit", "une flamme issue de trois", "un gran espíritu apresado", "ein großer gefangener Geist"}
        },  //clear
            Text{"a Big Poe Bottle", "un grand esprit en flacon", "una botella con un Gran Poe", "eine Flasche mit einem Nachtschwärmer", "", "une âme en flacon", ""}
    );
    hintTable[BOTTLE_WITH_HOT_SPRING_WATER] = HintText::Item({
            //obscure
            Text{"a hot liquid", "un liquide chaud", "un líquido hirviente", "eine heiße Flüssigkeit"}
        },  //clear
            Text{"a Hot Spring Water Bottle", "de l'eau de source chaude en flacon", "una botella con agua caliente de manantial", "eine Flasche mit heißem Quellwasser"}
    );
    hintTable[BOTTLE_WITH_SPRING_WATER] = HintText::Item({
            //obscure
            Text{"a fresh drink", "un petit arrosage", "un líquido fresco", "ein frisches Getränk"}
        },  //clear
            Text{"a Spring Water Bottle", "de l'eau de source en flacon", "una botella con agua de manantial", "eine Flasche mit Quellwasser"}
    );
    hintTable[DEKU_PRINCESS] = HintText::Item({
            //obscure
            Text{"a princess", "du sang royal", "una princesa", "eine Prinzessin"}
        },  //clear
            Text{"a Deku Princess Bottle", "la princesse mojo en flacon", "una botella con la Princesa Deku", "eine Flasche mit der Deku-Prinzessin"}
    );
    hintTable[GOLD_DUST] = HintText::Item({
            //obscure
            Text{"a gleaming powder", "une poudre scintillante", "un polvo brillante", "ein glänzendes Pulver"}
        },  //clear
            Text{"a Gold Dust Bottle", "de la poudre d'or en flacon", "una botella con polvo dorado", "eine Flasche mit Goldstaub"}
    );
    hintTable[BOTTLE_WITH_ZORA_EGG] = HintText::Item({
            //obscure
            Text{"a lost child", "une progéniture dérobée", "un renacuajo perdido", "ein verlorenes Kind"}
        },  //clear
            Text{"a Zora Egg Bottle", "un œuf de Zora en flacon", "una botella con un huevo Zora", "eine Flasche mit einem Zora-Ei"}
    );
    hintTable[SEAHORSE] = HintText::Item({
            //obscure
            Text{"a sea creature", "une queue enroulée", "una criatura del océano", "ein Meeresgeschöpf"}
        },  //clear
            Text{"a Seahorse Bottle", "un hippocampe en flacon", "una botella con el caballo de mar", "eine Flasche mit einem Seepferdchen"}
    );
    hintTable[BOTTLE_WITH_MUSHROOM] = HintText::Item({
            //obscure
            Text{"a strange fungus", "du mycélium", "un hongo raro", "ein seltsamer Pilz"}
        },  //clear
            Text{"a Magic Mushroom Bottle", "un champignon magique en flacon", "una botella con champiñón mágico", "eine Flasche mit einem magischen Pilz"}
    );
    hintTable[BOTTLE_WITH_MYSTERY_MILK] = HintText::Item({
            //obscure
            Text{"a strange drink", "un remède maison", "una bebida sospechosa", "ein seltsames Getränk"}
        },  //clear
            Text{"a Mystery Milk Bottle", "du lait mystère en flacon", "una botella de leche sospechosa", "eine Flasche mit verdächtiger Milch", "", "du lait suspect en flacon", ""}
    );
//UPGRADABLE ITEMS
    hintTable[LARGE_QUIVER]         = HintText::Item({Text{"a ranged weapon", "un grand tube", "un arma de largo alcance", "eine Fernwaffe"}});
    hintTable[LARGEST_QUIVER]       = HintText::Item({Text{"a ranged weapon", "un énorme tube", "un arma de largo alcance", "eine Fernwaffe"}});
    hintTable[BOMB_BAG]             = HintText::Item({Text{"a vessel of explosives", "une besace pyrotechnique", "un contenedor de explosivos", "ein Gefäß für Sprengstoff"}});
    hintTable[BIG_BOMB_BAG]         = HintText::Item({Text{"a vessel of explosives", "une besace pyrotechnique", "un contenedor de explosivos", "ein Gefäß für Sprengstoff"}});
    hintTable[BIGGEST_BOMB_BAG]     = HintText::Item({Text{"a vessel of explosives", "une besace pyrotechnique", "un contenedor de explosivos", "ein Gefäß für Sprengstoff"}});
    hintTable[ADULT_WALLET]         = HintText::Item({Text{"a coin purse", "une tirelire", "una cartera", "ein Geldbeutel"}});
    hintTable[GIANT_WALLET]         = HintText::Item({Text{"a coin purse", "une tirelire", "una cartera", "ein Geldbeutel"}});
    hintTable[MAGIC_POWER]          = HintText::Item({Text{"magic power", "une barre verte", "poder mágico", "magische Kraft"}});
    hintTable[EXTENDED_MAGIC_POWER] = HintText::Item({Text{"magic power", "une barre verte", "poder mágico", "magische Kraft"}});
//SONGS
    hintTable[SONG_OF_TIME] = HintText::Item({
            //obscure
            Text{"song of time", "une boucle temporelle", "una canción temporal", "das Lied der Zeit"}
        },  //clear
            Text{"the Song of Time", "le Chant du temps", "la canción del tiempo", "die Hymne der Zeit"}
    );
    hintTable[SONG_OF_STORMS] = HintText::Item({
            //obscure
            Text{"stormy weather", "un temps de chien", "clima torrencial", "stürmisches Wetter"}
        },  //clear
            Text{"the Song of Storms", "le Chant des tempêtes", "la canción de la tormenta", "die Hymne des Sturms"}
    );
    hintTable[SONG_OF_HEALING] = HintText::Item({
            //obscure
            Text{"a soothing melody", "le repos des âmes", "una canción calmante", "eine besänftigende Melodie"}
        },  //clear
            Text{"the Song of Healing", "le Chant de l'apaisement", "la canción de curación", "das Lied der Befreiung"}
    );
    hintTable[SONG_OF_SOARING] = HintText::Item({
            //obscure
            Text{"white wings", "une paire d'ailes", "alas blancas", "weiße Schwingen"}
        },  //clear
            Text{"the Song of Soaring", "le Chant de l'envol", "la canción de vuelo", "das Lied der Schwingen"}
    );
    //hintTable[SONG_OF_DOUBLE_TIME] = HintText::Item({
    //        //obscure
    //        Text{"double time", "une réduction des attentes", "tiempo acelerado", "doppelte Zeit"}
    //    },  //clear
    //        Text{"the Song of Double Time", "le Chant du temps accéléré", "la canción de doble tiempo", "das Thema der Zeit im Wind"}
    //);
    //hintTable[INVERTED_SONG_OF_TIME] = HintText::Item({
    //        //obscure
    //        Text{"slowed time", "un timing assoupli", "tiempo ralentizado", "verlangsamte Zeit"}
    //    },  //clear
    //        Text{"the Inverted Song of Time", "le Chant du temps inversé", "la canción del tiempo invertida", "die Ballade des Kronos"}
    //);
    hintTable[EPONAS_SONG] = HintText::Item({
            //obscure
            Text{"a horses song", "l'appel d'une partenaire", "una canción equina", "das Lied eines Pferdes"}
        },  //clear
            Text{"Epona's Song", "le Chant d'Épona", "la canción de Epona", "Eponas Lied", "", "le Chant d'Epona", ""}
    );
    hintTable[SONATA_OF_AWAKENING] = HintText::Item({
            //obscure
            Text{"a royal song", "un chant royal", "una canción de realeza", "ein königliches Lied"}
        },  //clear
            Text{"the Sonata of Awakening", "la Sonate de l'éveil", "la sonata del despertar", "die Sonate des Erwachens"}
    );
    hintTable[LULLABY_INTRO] = HintText::Item({
            //obscure
            Text{"a sleepy melody intro", "une mélodie incomplète", "una introducción al sueño", "der Anfang eines Schlafliedes"}
        },  //clear
            Text{"the Lullaby Intro", "l'intro de la Berceuse", "la introducción de la nana", "das Schlummerlied-Intro"}
    );
    hintTable[GORONS_LULLABY] = HintText::Item({
            //obscure
            Text{"a sleepy melody", "le repos du géant", "sueño profundo", "ein Schlaflied"}
        },  //clear
            Text{"the Goron's Lullaby", "la Berceuse des Gorons", "la nana goron", "das Goronische Schlummerlied"}
    );
    hintTable[NEW_WAVE_BOSSA_NOVA] = HintText::Item({
            //obscure
            Text{"a song of newborns", "un chant de nourrissons", "canción para nacimientos", "ein Lied für Neugeborene"}
        },  //clear
            Text{"the New Wave Bossa Nova", "la Bossa-nova des flots", "la bossanova de las olas", "den Bossa Nova der Kaskaden"}
    );
    hintTable[ELEGY_OF_EMPTINESS] = HintText::Item({
            //obscure
            Text{"empty shells", "un soldat sans cœur", "caparazones huecos", "leere Hüllen"}
        },  //clear
            Text{"the Elegy of Emptiness", "l'Hymne du vide", "la elegía al vacío", "die Elegie des leeren Herzens"}
    );
    hintTable[OATH_TO_ORDER] = HintText::Item({
            //obscure
            Text{"a song of giants", "un rendez-vous au carnaval", "una plegaria a los gigantes", "ein Lied der Riesen"}
        },  //clear
            Text{"the Oath to Order", "l'Ode de l'appel", "la oda al orden", "den Gesang des Himmels"}
    );
//PIECES OF HEART
    hintTable[PIECE_OF_HEART] = HintText::Item({
            //obscure
            Text{"a segment of health", "un segment de vie", "un segmento de vida", "ein Stück Lebenskraft"}
        },  //clear
            Text{"a Piece of Heart", "un fragment de cœur", "una pieza de corazón", "ein Herzteil"}
    );
    hintTable[HEART_CONTAINER] = HintText::Item({
            //obscure
            Text{"a new heart", "un cœur tout neuf", "un nuevo corazón", "ein neues Herz"}
        },  //clear
            Text{"a Heart Container", "un quart de cœur", "un contenedor de corazón", "einen Herzcontainer", "", "un réceptacle de cœur", ""}
    );
//MAPS
    //hintTable[MAP] = HintText::Item({
    //        //obscure
    //        Text{"a paper guide", "un guide en papier", "un papiro guía", "ein Wegweiser aus Papier"}
    //    },  //clear
    //        Text{"a Map", "une carte", "un mapa", "eine Karte"}
    //);
    hintTable[WOODFALL_TEMPLE_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía", "ein Wegweiser aus Papier"}
        },  //clear
            Text{"the Woodfall Temple Map", "la carte du temple de Boisé-les-Cascades", "el mapa del Templo del Bosque Catarata", "die Karte des Dämmerwald-Tempels", "", "la carte du temple de Bois-Cascade", ""}
    );
    hintTable[SNOWHEAD_TEMPLE_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía", "ein Wegweiser aus Papier"}
        },  //clear
            Text{"the Snowhead Temple Map", "la carte du temple du Pic des neiges", "el mapa del Templo del Pico Nevado", "die Karte des Pic-Hibernia-Tempels", "", "la carte du temple du pic des Neiges", ""}
    );
    hintTable[GBT_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía", "ein Wegweiser aus Papier"}
        },  //clear
            Text{"the Great Bay Temple Map", "la carte du temple de la Grande Baie", "el mapa del Templo de la Gran Bahía", "die Karte des Schädelbucht-Tempels"}
    );
    hintTable[STONE_TOWER_TEMPLE_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía", "ein Wegweiser aus Papier"}
        },  //clear
            Text{"the Stone Tower Temple Map", "la carte du temple de la forteresse de pierre", "el mapa del Templo de la Torre de Piedra", "die Karte des Felsenturm-Tempels"}
    );
    hintTable[CLOCK_TOWN_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía", "ein Wegweiser aus Papier"}
        },  //clear
            Text{"the Clock Town Map", "la carte de Cadranbourg", "el mapa de la Ciudad Reloj", "die Karte von Unruh-Stadt", "", "la carte de Bourg-Clocher", ""}
    );
    hintTable[WOODFALL_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía", "ein Wegweiser aus Papier"}
        },  //clear
            Text{"the Woodfall Map", "la carte de Boisé-les-Cascades", "el mapa del Bosque Catarata", "die Karte von Dämmerwald", "", "la carte de Bois-Cascade", ""}
    );
    hintTable[SNOWHEAD_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía", "ein Wegweiser aus Papier"}
        },  //clear
            Text{"the Snowhead Map", "la carte du Pic des neiges", "el mapa del Pico Nevado", "die Karte von Pic-Hibernia", "", "la carte du pic des Neiges", ""}
    );
    hintTable[GREAT_BAY_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía", "ein Wegweiser aus Papier"}
        },  //clear
            Text{"the Great Bay Map", "la carte de la Grande Baie", "el mapa de la Gran Bahía", "die Karte der Schädelbucht"}
    );
    hintTable[STONE_TOWER_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía", "ein Wegweiser aus Papier"}
        },  //clear
            Text{"the Stone Tower Map", "la carte de la forteresse de pierre", "el mapa de la Torre de Piedra", "die Karte vom Felsenturm"}
    );
    hintTable[ROMANI_RANCH_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía", "ein Wegweiser aus Papier"}
        },  //clear
            Text{"the Romani Ranch Map", "la carte du ranch Romani", "el mapa del Rancho Romani", "die Karte der Romani-Farm"}
    );
//COMPASSES
    //hintTable[COMPASS] = HintText::Item({
    //        //obscure
    //        Text{"a magnetic needle", "une aiguille magnétique", "una aguja imantada", "eine magnetische Nadel"}
    //    },  //clear
    //        Text{"a Compass", "une boussole", "una brújula", "einen Kompass"}
    //);
    hintTable[WOODFALL_TEMPLE_COMPASS] = HintText::Item({
            //obscure
            Text{"a magnetic needle", "une aiguille magnétique", "una aguja imantada", "eine magnetische Nadel"}
        },  //clear
            Text{"the Woodfall Temple Compass", "la boussole du temple de Boisé-les-Cascades", "la brújula del Templo del Bosque Catarata", "den Kompass des Dämmerwald-Tempels", "", "la boussole du temple de Bois-Cascade", ""}
    );
    hintTable[SNOWHEAD_TEMPLE_COMPASS] = HintText::Item({
            //obscure
            Text{"a magnetic needle", "une aiguille magnétique", "una aguja imantada", "eine magnetische Nadel"}
        },  //clear
            Text{"the Snowhead Temple Compass", "la boussole du temple du Pic des neiges", "la brújula del Templo del Pico Nevado", "den Kompass des Pic-Hibernia-Tempels", "", "la boussole du temple du pic des Neiges", ""}
    );
    hintTable[GBT_COMPASS] = HintText::Item({
            //obscure
            Text{"a magnetic needle", "une aiguille magnétique", "una aguja imantada", "eine magnetische Nadel"}
        },  //clear
            Text{"the Great Bay Temple Compass", "la boussole du temple de la Grande Baie", "la brújula del Templo de la Gran Bahía", "den Kompass des Schädelbucht-Tempels"}
    );
    hintTable[STONE_TOWER_TEMPLE_COMPASS] = HintText::Item({
            //obscure
            Text{"a magnetic needle", "une aiguille magnétique", "una aguja imantada", "eine magnetische Nadel"}
        },  //clear
            Text{"the Stone Tower Temple Compass", "la boussole du temple de la forteresse de pierre", "la brújula del Templo de la Torre de Piedra", "den Kompass des Felsenturm-Tempels"}
    );
//BOSSKEYS
    //hintTable[BOSS_KEY] = HintText::Item({
    //        //obscure
    //        Text{"an important key", "une clé importante", "una llave importante", "ein wichtiger Schlüssel"}
    //    },  //clear
    //        Text{"a Boss Key", "une grande clé", "una llave del jefe", "einen Großen Schlüssel"}
    //);
    hintTable[WOODFALL_TEMPLE_BOSS_KEY] = HintText::Item({
            //obscure
            Text{"an important key", "une clé importante", "una llave importante", "ein wichtiger Schlüssel"}
        },  //clear
            Text{"the Woodfall Temple Boss Key", "la grande clé du temple de Boisé-les-Cascades", "la llave del jefe del Templo del Bosque Catarata", "den Großen Schlüssel des Dämmerwald-Tempels", "", "la grande clé du temple de Bois-Cascade", ""}
    );
    hintTable[SNOWHEAD_TEMPLE_BOSS_KEY] = HintText::Item({
            //obscure
            Text{"an important key", "une clé importante", "una llave importante", "ein wichtiger Schlüssel"}
        },  //clear
            Text{"the Snowhead Temple Boss Key", "la grande clé du temple du Pic des neiges", "la llave del jefe del Templo del Pico Nevado", "den Großen Schlüssel des Pic-Hibernia-Tempels", "", "la grande clé du temple du pic des Neiges", ""}
    );
    hintTable[GBT_BOSS_KEY] = HintText::Item({
            //obscure
            Text{"an important key", "une clé importante", "una llave importante", "ein wichtiger Schlüssel"}
        },  //clear
            Text{"the Great Bay Temple Boss Key", "la grande clé du temple de la Grande Baie", "la llave del jefe del Templo de la Gran Bahía", "den Großen Schlüssel des Schädelbucht-Tempels"}
    );
    hintTable[STONE_TOWER_TEMPLE_BOSS_KEY] = HintText::Item({
            //obscure
            Text{"an important key", "une clé importante", "una llave importante", "ein wichtiger Schlüssel"}
        },  //clear
            Text{"the Stone Tower Temple Boss Key", "la grande clé du temple de la forteresse de pierre", "la llave del jefe del Templo de la Torre de Piedra", "den Großen Schlüssel des Felsenturm-Tempels"}
    );
//SMALLKEYS
    //hintTable[SMALL_KEY] = HintText::Item({
    //        //obscure
    //        Text{"a useful key", "une clé pratique", "una llave útil", "ein nützlicher Schlüssel"}
    //    },  //clear
    //        Text{"a Small Key", "une petite clé", "una llave pequeña", "einen Kleinen Schlüssel"}
    //);
    hintTable[WOODFALL_TEMPLE_SMALL_KEY] = HintText::Item({
            //obscure
            Text{"swampy small key", "une clé marécageuse", "una llave pantanosa", "ein sumpfiger Schlüssel"}
        },  //clear
            Text{"the Woodfall Temple Small Key", "la petite clé du temple de Boisé-les-Cascades", "la llave pequeña del Templo del Bosque Catarata", "den Kleinen Schlüssel des Dämmerwald-Tempels", "", "la petite clé du temple de Bois-Cascade", ""}
    );
    hintTable[SNOWHEAD_TEMPLE_SMALL_KEY] = HintText::Item({
            //obscure
            Text{"icy small key", "une clé glacée", "una llave helada", "ein eisiger Schlüssel"}
        },  //clear
            Text{"a Snowhead Temple Small Key", "une petite clé du temple du Pic des neiges", "una llave pequeña del Templo del Pico Nevado", "einen Kleinen Schlüssel des Pic-Hibernia-Tempels", "", "une petite clé du temple du pic des Neiges", ""}
    );
    hintTable[GBT_SMALL_KEY] = HintText::Item({
            //obscure
            Text{"ocean small key", "une clé marine", "una llave húmeda", "ein feuchter Schlüssel"}
        },  //clear
            Text{"the Great Bay Temple Small Key", "la petite clé du temple de la Grande Baie", "la llave pequeña del Templo de la Gran Bahía", "den Kleinen Schlüssel des Schädelbucht-Tempels"}
    );
    hintTable[STONE_TOWER_TEMPLE_SMALL_KEY] = HintText::Item({
            //obscure
            Text{"rocky small key", "une clé rocheuse", "una llave rocosa", "ein steinerner Schlüssel"}
        },  //clear
            Text{"a Stone Tower Temple Small Key", "une petite clé du temple de la forteresse de pierre", "una llave pequeña del Templo de la Torre de Piedra", "einen Kleinen Schlüssel des Felsenturm-Tempels"}
    );
//DUNGEON REWARDS
    hintTable[ODOLWAS_REMAINS] = HintText::Item({
            //obscure
            Text{"a boss's remains", "un sceau de géant", "los restos de un jefe", "die Überreste eines Bosses"}
        },  //clear
            Text{"Odolwa's Remains", "les restes d'Odolwa", "los Restos de Odolwa", "Odolwas Vermächtnis"}
    );
    hintTable[GOHTS_REMAINS] = HintText::Item({
            //obscure
            Text{"a boss's remains", "un sceau de géant", "los restos de un jefe", "die Überreste eines Bosses"}
        },  //clear
            Text{"Goht's Remains", "les restes de Rhork", "los Restos de Goht", "Gohts Vermächtnis"}
    );
    hintTable[GYORGS_REMAINS] = HintText::Item({
            //obscure
            Text{"a boss's remains", "un sceau de géant", "los restos de un jefe", "die Überreste eines Bosses"}
        },  //clear
            Text{"Gyorg's Remains", "les restes de Gyorg", "los Restos de Gyorg", "Gyorgs Vermächtnis"}
    );
    hintTable[TWINMOLDS_REMAINS] = HintText::Item({
            //obscure
            Text{"a boss's remains", "un sceau de géant", "los restos de un jefe", "die Überreste eines Bosses"}
        },  //clear
            Text{"Twinmold's Remains", "les restes de Skorn", "los Restos de Twinmold", "Twinmolds Vermächtnis"}
    );

    /*-----------------------
    |    REFILL ITEMS       |
    -----------------------*/
    hintTable[RECOVERY_HEART] = HintText::Item({
            //obscure
            Text{"Recovery Heart", "un petit soin", "un pequeño corazón", "ein Herz zur Genesung"}
        },  //clear
            Text{"a Recovery Heart", "un cœur de vie", "un corazón", "ein Herz"}
    );
    hintTable[GREEN_RUPEE] = HintText::Item({
            //obscure
            Text{"Green rupee", "le début de la richesse", "una gema verdeante", "ein grüner Rubin"}
        },  //clear
            Text{"a Green Rupee", "un rubis vert", "una rupia verde", "einen grünen Rubin"}
    );
    hintTable[BLUE_RUPEE] = HintText::Item({
            //obscure
            Text{"Blue rupee", "une richesse azurée", "una gema cerúlea", "ein blauer Rubin"}
        },  //clear
            Text{"a Blue Rupee", "un rubis bleu", "una rupia azul", "einen blauen Rubin"}
    );
    hintTable[RED_RUPEE] = HintText::Item({
            //obscure
            Text{"Red rupee", "une richesse écarlate", "una gema carmesí", "ein roter Rubin"}
        },  //clear
            Text{"a Red Rupee", "un rubis rouge", "una rupia roja", "einen roten Rubin"}
    );
    hintTable[PURPLE_RUPEE] = HintText::Item({
            //obscure
            Text{"Purple rupee", "une richesse violacée", "una gema cárdena", "ein violetter Rubin"}
        },  //clear
            Text{"a Purple Rupee", "un rubis mauve", "una rupia púrpura", "einen violetten Rubin", "", "un rubis violet", ""}
    );
    hintTable[SILVER_RUPEE] = HintText::Item({
            //obscure
            Text{"Silver rupee", "une richesse scintillante", "una gema argéntea", "ein silberner Rubin"}
        },  //clear
            Text{"a Silver Rupee", "un rubis argenté", "una rupia plateada", "einen silbernen Rubin"}
    );
    hintTable[HUGE_RUPEE] = HintText::Item({
            //obscure
            Text{"Huge rupee", "une richesse écrasante", "una gema enorme", "ein riesiger Rubin"}
        },  //clear
            Text{"a Huge Rupee", "un énorme rubis", "una rupia enorme", "einen goldenen Rubin"}
    );
    hintTable[DEKU_NUTS_5] = HintText::Item({
            //obscure
            Text{"5 nuts", "un paquet de flashs", "5 nueces", "5 Nüsse"}
        },  //clear
            Text{"Deku Nuts (5 pieces)", "une demi-dizaine de noix mojos", "Nueces deku (5)", "5 Deku-Nüsse", "", "une demi-dizaine de noix mojo", ""}
    );
    hintTable[DEKU_NUTS_10] = HintText::Item({
            //obscure
            Text{"10 nuts", "un paquet de flashs", "10 nueces", "10 Nüsse"}
        },  //clear
            Text{"Deku Nuts (10 pieces)", "une dizaine de noix mojos", "Nueces deku (10)", "10 Deku-Nüsse", "", "une dizaine de noix mojo", ""}
    );
    hintTable[BOMBS_5] = HintText::Item({
            //obscure
            Text{"5 explosive orbs", "un paquet d'explosifs", "5 explosiones", "5 explosive Kugeln"}
        },  //clear
            Text{"Bombs (5 pieces)", "une demi-dizaine de bombes", "Bombas (5)", "5 Bomben"}
    );
    hintTable[BOMBS_10] = HintText::Item({
            //obscure
            Text{"10 explosive orbs", "un paquet d'explosifs", "10 explosiones", "10 explosive Kugeln"}
        },  //clear
            Text{"Bombs (10 pieces)", "une dizaine de bombes", "Bombas (10)", "10 Bomben"}
    );
    hintTable[BOMBS_20] = HintText::Item({
            //obscure
            Text{"20 explosive orbs", "un paquet d'explosifs", "20 explosiones", "20 explosive Kugeln"}
        },  //clear
            Text{"Bombs (20 pieces)", "une vingtaine de bombes", "Bombas (20)", "20 Bomben"}
    );
    hintTable[BOMBCHU_5] = HintText::Item({
            //obscure
            Text{"5 explosive mice", "un paquet d'explosifs", "5 ratones explosivos", "5 explosive Mäuse"}
        },  //clear
            Text{"Bombchu (5 pieces)", "une demi-dizaine de bombchu", "Bombchus (5)", "5 Krabbelminen", "", "une demi-dizaine de missiles teigneux", ""}
    );
    hintTable[BOMBCHU_10] = HintText::Item({
            //obscure
            Text{"10 explosive mice", "un paquet d'explosifs", "10 ratones explosivos", "10 explosive Mäuse"}
        },  //clear
            Text{"Bombchu (10 pieces)", "une dizaine de bombchu", "Bombchus (10)", "10 Krabbelminen", "", "une dizaine de missiles teigneux", ""}
    );
    hintTable[BOMBCHU_20] = HintText::Item({
            //obscure
            Text{"20 explosive mice", "un paquet d'explosifs", "20 ratones explosivos", "20 explosive Mäuse"}
        },  //clear
            Text{"Bombchu (20 pieces)", "une vingtaine de bombchu", "Bombchus (20)", "20 Krabbelminen", "", "une vingtaine de missiles teigneux", ""}
    );
    hintTable[ARROWS_10] = HintText::Item({
            //obscure
            Text{"10 projectile sticks", "un paquet d'aiguilles", "10 palos proyectiles", "10 spitze Stäbe"}
        },  //clear
            Text{"Arrow (10 pieces)", "une dizaine de flèches", "Flechas (10)", "10 Pfeile"}
    );
    hintTable[ARROWS_30] = HintText::Item({
            //obscure
            Text{"30 projectile sticks", "un paquet d'aiguilles", "30 palos proyectiles", "30 spitze Stäbe"}
        },  //clear
            Text{"Arrow (30 pieces)", "une trentaine de flèches", "Flechas (30)", "30 Pfeile"}
    );
    hintTable[ARROWS_40] = HintText::Item({
            //obscure
            Text{"40 projectile sticks", "un paquet d'aiguilles", "40 palos proyectiles", "40 spitze Stäbe"}
        },  //clear
            Text{"Arrow (40 pieces)", "une quarantaine de flèches", "Flechas (40)", "40 Pfeile"}
    );
    hintTable[ARROWS_50] = HintText::Item({
            //obscure
            Text{"50 projectile sticks", "un paquet d'aiguilles", "50 palos proyectiles", "50 spitze Stäbe"}
        },  //clear
            Text{"Arrow (50 pieces)", "une cinquantaine de flèches", "Flechas (50)", "50 Pfeile"}
    );
    hintTable[BLUE_POTION_REFILL] = HintText::Item({
            //obscure
            Text{"Blue Potion Refill", "une dose de bleu", "un relleno de Poción Azul", "eine Nachfüllung des blauen Trankes"}
        },  //clear
            Text{"some Blue Potion", "de la potion bleue", "un relleno de Poción Azul", "ein blaues Elixier"}
    );
    hintTable[GREEN_POTION_REFILL] = HintText::Item({
            //obscure
            Text{"Green Potion Refill", "une dose de vert", "un relleno de Poción Verde", "eine Nachfüllung des grünen Trankes"}
        },  //clear
            Text{"some Green Potion", "de la potion verte", "un relleno de Poción Verde", "ein grünes Elixier"}
    );
    hintTable[RED_POTION_REFILL] = HintText::Item({
            //obscure
            Text{"Red Potion Refill", "une dose de rouge", "un relleno de Poción Roja", "eine Nachfüllung des roten Trankes"}
        },  //clear
            Text{"some Red Potion", "de la potion rouge", "un relleno de Poción Roja", "ein rotes Elixier"}
    );
    hintTable[BOMBCHU_DROP] = HintText::Item({
            //obscure
            Text{"explosive mice", "un paquet d'explosifs", "un ratón explosivo", "explosive Mäuse"}
        },  //clear
            Text{"some Bombchu", "un paquet de bombchu", "algunos Bombchus", "einige Krabbelminen", "", "un paquet de missiles teigneux", ""}
    );
    hintTable[DEKU_STICK_1] = HintText::Item({
            //obscure
            Text{"1 stick", "une branche", "una rama", "1 Stock"}
        },  //clear
            Text{"a Deku Stick", "un bâton mojo", "un palo Deku", "einen Deku-Stab"}
    );

    /*----------------
    |   SHOP ITEMS   |
    ----------------*/
    hintTable[BUY_ARROWS_10]        = HintText::Item({Text{"Buy 10 Arrows", "Acheter: Flèches (10)", "Comprar 10 flechas", "Kaufe 10 Pfeile"}});
    hintTable[BUY_ARROWS_30]        = HintText::Item({Text{"Buy 30 Arrows", "Acheter: Flèches (30)", "Comprar 30 flechas", "Kaufe 30 Pfeile"}});
    hintTable[BUY_BLUE_POTION]      = HintText::Item({Text{"Buy Blue Potion", "Acheter: Potion bleue", "Comprar poción azul", "Kaufe ein Blaues Elixier"}});
    hintTable[BUY_BOMBCHU_10]       = HintText::Item({Text{"Buy 10 Bombchu", "Acheter: Bombchu (10)", "Comprar 10 bombchus", "Kaufe 10 Krabbelminen"}});
    hintTable[BUY_BOMBS_10]         = HintText::Item({Text{"Buy 10 Bombs", "Acheter: Bombes (10)", "Comprar 10 bombas", "Kaufe 10 Bomben"}});
    hintTable[BUY_DEKU_NUT_10]      = HintText::Item({Text{"Buy 10 Deku Nuts", "Acheter: Noix Mojos (10)", "Comprar 10 nueces Deku", "Kaufe 10 Deku-Nüsse"}});
    hintTable[BUY_DEKU_STICK_1]     = HintText::Item({Text{"Buy 1 Deku Stick", "Acheter: Bâton Mojo (1)", "Comprar 1 palo Deku", "Kaufe einen Deku-Stab"}});
    hintTable[BUY_FAIRYS_SPIRIT]    = HintText::Item({Text{"Buy Fairy", "Acheter: Fée", "Comprar hada", "Kaufe eine kleine Fee"}});
    hintTable[BUY_GREEN_POTION]     = HintText::Item({Text{"Buy Green Potion", "Acheter: Potion verte", "Comprar poción verde", "Kaufe ein Grünes Elixier"}});
    hintTable[BUY_HEROS_SHIELD]     = HintText::Item({Text{"Buy Hero Shield", "Acheter: Bouclier du Héros", "Comprar el escudo del héroe", "Kaufe einen Heroenschild"}});
    hintTable[BUY_MAGIC_BEAN]       = HintText::Item({Text{"Buy Magic Bean", "Acheter: Haricot Magique", "Comprar habichuela mágica", "Kaufe eine Wundererbse"}});
    hintTable[BUY_RED_POTION]       = HintText::Item({Text{"Buy Red Potion", "Acheter: Potion rouge", "Comprar poción roja", "Kaufe ein Rotes Elixier"}});

    /*-----------------------
    |  SOMETIMES HINT TEXT  |
    -----------------------*/
//Clock Tower
    hintTable[CLOCK_TOWER_OCARINA_OF_TIME] = HintText::Sometimes({
            //obscure
            Text{"a #musical instrument# is", "l'#instrument qui t'a été volé# est", "Un instrumento musical", "Ein #musikalisches Instrument# ist"}
        },  //clear
            Text{"#Skull Kid# has", "#Skull Kid# détient", "Skull Kid tiene", "das #Horror-Kid# hat"}
    );
    hintTable[CLOCK_TOWER_SONG_OF_TIME] = HintText::Sometimes({
            //obscure
            Text{"a #timeless song# is", "le #souvenir de la princesse# est", "", "ein #zeitloses Lied# ist"}
        },  //clear
            Text{"the #Song of Time# is", "le #Chant du temps# est", "", "die #Hymne der Zeit# ist"}
    );
    hintTable[HMS_DEKU_MASK] = HintText::Sometimes({
            //obscure
            Text{"a #forest curse removed# rewards", "#lever une malédiction sylvestre# crée", "remover la maldición del bosque otorga", "ein #entfernter Waldfluch# entlohnt"}
        },  //clear
            Text{"the #Happy Mask Salesman# has", "le #vendeur de masques# a", "el vendedor de máscaras tiene", "der #fröhliche Maskenhändler# hat"}
    );
    hintTable[HMS_SONG_OF_HEALING] = HintText::Sometimes({
            //obscure
            Text{"a #masked man's melody# teaches", "la #foire aux masques# enseigne", "la melodía del hombre enmascarado enseña", "die #Melodie eines maskierten Mannes# lehrt"}
        },  //clear
            Text{"the #Happy Mask Salesman# has", "le #vendeur de masques# a", "el vendedor de máscaras tiene", "der #fröhliche Maskenhändler# hat"}
    );
    hintTable[HMS_BOMBERS_NOTEBOOK] = HintText::Sometimes({
            //obscure
            Text{"a #masked man's gift# rewards", "la #foire aux masque# offre", "el hombre enmascarado otorga", "das #Geschenk eines maskierten Mannes# entlohnt"}
        },  //clear
            Text{"the #Happy Mask Salesman# has", "le #vendeur de masques# a", "el vendedor de máscaras tiene", "der #fröhliche Maskenhändler# hat"}
    );
    hintTable[HMS_STARTING_SWORD] = HintText::Sometimes({
            //obscure
            Text{"a #new file# yields", "une #nouvelle partie# procure", "una nueva partida otorga", "eine #neue Datei# trägt"}
        },  //clear
            Text{"#you already have#", "#tu as déjà#", "tu ya tienes", "#du hast bereits#"}
    );
    hintTable[HMS_STARTING_SHIELD] = HintText::Sometimes({
            //obscure
            Text{"a #new file# yields", "une #nouvelle partie# procure", "una nueva partida otorga", "eine #neue Datei# trägt"}
        },  //clear
            Text{"#you already have#", "#tu as déjà#", "tu ya tienes", "#du hast bereits#"}
    );
    //PRE_CLOCK_TOWN_CHEST
//Deku Palace
    hintTable[DEKU_PALACE_BEAN_SELLER] = HintText::Sometimes({
            //obscure
            Text{"a #gorging merchant# sells", "un #marchand goulu# vend", "el mercader enterrado vende", "ein #schlemmender Händler# verkauft"}
        },  //clear
            Text{"the #Bean Seller beneath Deku Palace# has", "le #vendeur de haricots du palais mojo# a", "el vendedor de habichuelas bajo el Palacio Deku tiene", "der #Wundererbsenverkäufer unter dem Deku-Palast# hat"}
    );
    hintTable[DEKU_PALACE_WEST_GARDEN] = HintText::Sometimes({
            //obscure
            Text{"the #home of scrubs# contains", "l'#habitat des pestes# contient", "el hogar de los matorrales contiene", "die #Heimat der Laubkerle# enthält"}
        },  //clear
            Text{"#Deku Palace's west gardens# contain", "le #jardin ouest du palais mojo# contient", "el jardín oeste del Palacio Deku tiene", "der #westliche Garten vom Deku-Palast# hat"}
    );
    hintTable[DEKU_PALACE_BUTLER_RACE] = HintText::Sometimes({
            //obscure
            Text{"the #royal servant# rewards", "le #servant royal# offre", "el sirviente real recompensa con", "der #königliche Diener# entlohnt"}
        },  //clear
            Text{"the #Deku Butler# has", "le #chancelier mojo# a", "el Mayordomo Deku tiene", "der #Deku-Butler# hat"}
    );
    hintTable[DEKU_PALACE_BEAN_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #merchant's cave# contains", "la #grotte d'un marchand# contient", "la cueva del mercader contiene", "die #Höhle eines Händlers# enthält"}
        },  //clear
            Text{"the #chest beneath Deku Palace# contains", "le #coffre sous le palais mojo# contient", "el cofre bajo el Palacio Deku contiene", "die #Truhe unter dem Deku-Palast# enthält"}
    );
    hintTable[DEKU_PALACE_IMPRISONED_MONKEY] = HintText::Sometimes({
            //obscure
            Text{"a #false imprisonment# teaches", "un #détenu innocent# enseigne", "un falso aprisionamiento enseña", "ein #zu Unrecht Gefangener# lehrt"}
        },  //clear
            Text{"the #imprisoned monkey# has", "le #singe emprisonné# a", "el mono aprisionado tiene", "der #eingesperrte Affe# hat"}
    );
//East Clock Town
    hintTable[E_CLOCK_TOWN_AROMA_IN_BAR] = HintText::Sometimes({
            //obscure
            Text{"an #important lady# rewards", "un #rapport fructueux# confère", "una señora importante recompensa con", "eine #wichtige Dame# entlohnt"}
        },  //clear
            Text{"#Madame Aroma's reward for the letter# is", "contre la #lettre express, madame Aroma# donne", "la recompensa de Madame Aroma por la carta es", "die #Belohnung von Madame Aroma für den Brief# ist"}
    );
    hintTable[E_CLOCK_TOWN_ARCHERY_1] = HintText::Sometimes({
            //obscure
            Text{"a #town activity# rewards", "un #habile abattage d'octoroks# octroie", "una actividad en la ciudad recompensa con", "eine #Stadtaktivität# entlohnt"}
        },  //clear
            Text{"the #Town Shooting Gallery's# reward is", "un des #prix du stand de tir de la ville# est", "la primer recompensa de la Galería de tiro de la Ciudad es", "die Belohnung der #Schießbude in Unruh-Stadt# ist"}
    );
    hintTable[E_CLOCK_TOWN_ARCHERY_2] = HintText::Sometimes({
            //obscure
            Text{"a #town activity# rewards", "un #parfait abattage d'octoroks# octroie", "una actividad en la ciudad recompensa con", "eine #Stadtaktivität# entlohnt"}
        },  //clear
            Text{"the #Town Shooting Gallery's# reward is", "un des #prix du stand de tir de la ville# est", "la segunda recompensa de la Galería de tiro de la Ciudad es", "die Belohnung der #Schießbude in Unruh-Stadt# ist"}
    );
    hintTable[E_CLOCK_TOWN_MAYOR] = HintText::Sometimes({
            //obscure
            Text{"a #town leader# rewards", "un #homme d'état# offre", "el líder de la ciudad recompensa con", "ein #Stadtleiter# entlohnt"}
        },  //clear
            Text{"#Mayor Dotour# has", "le #maire Dotour# a", "el Alcalde Dotour tiene", "#Bürgermeister Dotour# hat"}
    );
    hintTable[E_CLOCK_TOWN_HONEY_DARLING_3DAYS] = HintText::Sometimes({
            //obscure
            Text{"a #lovers game# rewards", "un #jeu d'amants# offre", "un juego de amantes recompensa con", "ein #Spiel der Verliebten# entlohnt"}
        },  //clear
            Text{"#Honey and Darling's Shop's reward# is", "le #prix ultime de l’arcade des amoureux# est", "la recompensa final de los juegos de Honey y Darling es", "die Belohnung vom #Spielecenter Liebling und Schätzchen# ist", "", "le #prix ultime du manège des amoureux# est", ""}
    );
    hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_GORON] = HintText::Sometimes({
            //obscure
            Text{"a #treasure game# rewards", "un #jeu trésorier# offre", "un juego del tesoro recompensa con", "ein #Schatzspiel# entlohnt"}
        },  //clear
            Text{"the #Treasure Chest Game's reward for Gorons# is", "le #prix pour gorons de Coffre au trésor# est", "la recompensa para Gorons en el juego del Cofre del Tesoro es", "die Belohnung beim #Truhenspiel für Goronen# ist", "", "le #prix pour gorons de la chasse au trésors# est", ""}
    );
    hintTable[E_CLOCK_TOWN_POSTMAN_FREEDOM] = HintText::Sometimes({
            //obscure
            Text{"a #delivery person# rewards", "un #ex-livreur# offre", "un repartidor recompensa con", "eine #liefernde Person# entlohnt"}
        },  //clear
            Text{"the #postman's final reward# is", "la #récompense finale du facteur# est", "la recompensa final del cartero es", "die #letzte Belohnung des Postboten# ist"}
    );
    hintTable[E_CLOCK_TOWN_GORMAN] = HintText::Sometimes({
            //obscure
            Text{"a #miserable leader# rewards", "un #homme ivre# offre", "un líder miserable otorga", "ein #miserabler Direktor# entlohnt"}
        },  //clear
            Text{"#Gorman's reward at the Milk Bar# is", "la #récompense de Gorman au bar laitier# est", "la recompensa de Gorman en el Bar Lácteo es", "die #Belohnung von Gorman in der Milchbar# ist"}
    );
    hintTable[E_CLOCK_TOWN_AROMA_IN_OFFICE] = HintText::Sometimes({
            //obscure
            Text{"an #important lady# rewards", "une #affectation détective# confie", "una señora importante recompensa con", "eine #wichtige Dame# entlohnt"}
        },  //clear
            Text{"#Madame Aroma, at her office#, gives", "#madame Aroma, dans son bureau#, donne", "Madame Aroma, en su oficina, da", "#Madame Aroma in ihrem Büro# gibt"}
    );
    hintTable[BOMBERS_HIDEOUT_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #secret hideout# contains", "un #recoin de repaire# recèle", "un escondite secreto contiene", "ein #Geheimversteck# enthält"}
        },  //clear
            Text{"the #chest in the Bombers' Hideout# contains", "le #coffre dans le repaire des Bombers# contient", "el cofre en el escondite de los Bombers es", "die #Truhe im Versteck der Bomber# enthält"}
    );
    hintTable[E_CLOCK_TOWN_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #shop roof# contains", "un #toit d'entreprise# contient", "el techo de una tienda contiene", "ein #Dach eines Ladens# enthält"}
        },  //clear
            Text{"the #chest in East Clock Town# contains", "le #coffre dans l'est de Cadranbourg# contient", "el cofre en el Este de la Ciudad Reloj contiene", "die #Truhe in Ost-Unruh-Stadt# enthält", "", "le #coffre dans l'est de Bourg-Clocher# contient", ""}
    );
    hintTable[E_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({
            //obscure
            Text{"a #correspondence box# contains", "un #boîte à correspondances# contient", "una caja de correspondencia contiene", "eine #Korrespondenzkiste# enthält"}
        },  //clear
            Text{"the #postbox# contains", "la #boîte aux lettres# contient", "el buzón contiene", "der #Briefkasten# enthält"}
    );
    //hintTable[E_CLOCK_TOWN_MILK_BAR_CHATEAU] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "un #spécialiste laitier# vend", "un lugar de copas vende", "ein #exklusives Getränk# entlohnt"}
    //    },  //clear
    //        Text{"the #Milk Bar# sells", "le #bar laitier# vend", "el Bar Lácteo vende", "die #Milchbar# verkauft"}
    //);
    //hintTable[E_CLOCK_TOWN_MILK_BAR_MILK] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "un #spécialiste laitier# vend", "un lugar de copas vende", "ein #Getränk# entlohnt"}
    //    },  //clear
    //        Text{"the #Milk Bar# sells", "le #bar laitier# vend", "el Bar Lácteo vende", "die #Milchbar# verkauft"}
    //);
    hintTable[GORMAN_TRACK_MYSTERY_MILK_QUEST] = HintText::Sometimes({
            //obscure
            Text{"an #upset stomach cure# rewards", "#soigner un mal de ventre# produit", "la cura a un mal estomacal recompensa con", "die #Heilung eines verstimmten Magens# entlohnt"}
        },  //clear
            Text{"the #Gorman Brothers cheer up their brother# with", "le #\"lait guérit-tout\" des frères Gorman# est en fait", "Los hermanos Gorman animan a su hermano con", "die #Gorman-Brüder muntern ihren Bruder auf# mit", "", "le #\"lait de cuite\" des frères Gorman# est en fait", ""}
    );
    //hintTable[E_CLOCK_TOWN_HONEY_DARLING_ANY_DAY] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "un #jeu d'amants# offre quotidiennement", "un juego de amantes recompensa con", "ein #tägliches Spiel der Verliebten# entlohnt"}
    //    },  //clear
    //        Text{"#Honey and Darling's Shop's daily reward# is", "le #prix quotidien de l’arcade des amoureux# est", "la recompensa diaria en el juego de Honey y Darling es", "die tägliche Belohnung vom #Spielecenter Liebling und Schätzchen# ist", "", "le #prix quotidien du manège des amoureux# est", ""}
    //);
    //hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_HUMAN] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "une #partie à 20 rubis# offre", "un juego del tesoro recompensa con", "ein #Menschenschatzspiel# entlohnt"}
    //    },  //clear
    //        Text{"the #Treasure Chest Game's reward for Hylians# is", "le #prix pour humains du Coffre au trésor# est", "la recompensa para Hylianos en el juego del Cofre del Tesoro es", "die Belohnung beim #Truhenspiel für Hylianer# ist", "", "le #prix pour humains de la chasse au trésors# est", ""}
    //);
    //hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_ZORA] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "une #partie à 10 rubis# offre", "un juego del tesoro recompensa con", "ein #Zora-Schatzspiel# entlohnt"}
    //    },  //clear
    //        Text{"the #Treasure Chest Game's reward for Zoras# is", "le #prix pour zoras du Coffre au trésor# est", "la recompensa para Zoras en el juego del Cofre del Tesoro es", "die Belohnung beim #Truhenspiel für Zoras# ist", "", "le #prix pour zoras de la chasse au trésors# est", ""}
    //);
    //hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_DEKU] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "une #partie à 5 rubis# offre", "un juego del tesoro recompensa con", "ein #Deku-Schatzspiel# entlohnt"}
    //    },  //clear
    //        Text{"the #Treasure Chest Game's reward for Dekus# is", "le #prix pour pestes mojo du Coffre au trésor# est", "la recompensa para Dekus en el juego del Cofre del Tesoro es", "die Belohnung beim #Truhenspiel für Dekus# ist", "", "le #prix pour pestes mojo de la chasse au trésors# est", ""}
    //);
//Goron Village
    hintTable[GORON_VILLAGE_POWDER_KEG_CHALLENGE] = HintText::Sometimes({
            //obscure
            Text{"a #large goron# rewards", "un #grand goron# confie", "un enorme goron recompensa con", "ein #großer Gorone# entlohnt"}
        },  //clear
            Text{"the #oversized Goron# has", "le #grand goron qui vend des barils de poudre# a", "el enorme Goron en la cueva tiene", "der #übergroße Gorone# hat"}
    );
    hintTable[GORON_VILLAGE_SCRUB_PURCHASE] = HintText::Sometimes({
            //obscure
            Text{"a #northern merchant# sells", "un #marchand septentrional# vend", "un mercader en el norte vende", "ein #nördlicher Händler# verkauft"}
        },  //clear
            Text{"the #Goron Village Business Scrub# sells", "la #peste marchande du village goron# vend", "el Mercader Deku en la Aldea Goron vende", "der #Deku-Händler im Goronendorf# verkauft"}
    );
    hintTable[GORON_VILLAGE_LENS_OF_TRUTH_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #lonely peak# contains", "un #pic esseulé# contient", "una cumbre solitaria contiene", "ein #einsamer Gipfel# enthält"}
        },  //clear
            Text{"the #chest inside Goron Village's Lone Peak Shrine# contains", "le #coffre dans le sanctuaire reculé du village goron# contient", "el ccofre dentro de la cueva en la Aldea Goron contiene", "die #Truhe im einsamen Gipfel-Schrein# enthält"}
    );
    hintTable[GORON_VILLAGE_SCRUB_TRADE] = HintText::Sometimes({
            //obscure
            Text{"a #northern merchant# trades", "un #marchand septentrional# échange", "un mercader en el norte intercambia por", "ein #nördlicher Händler# tauscht"}
        },  //clear
            Text{"Business Scrubs #trade for the Swamp Title Deed#", "une peste marchande #échange un titre de marais# contre", "el Mercader Deku intercambia la propiedad del Pantano por", "Deku-Händler #tauschen gegen die Sumpf-Urkunde#"}
    );
    hintTable[GORON_VILLAGE_LEDGE] = HintText::Sometimes({
            //obscure
            Text{"a #cold ledge# contains", "Un #rebord froid# recèle", "una cornisa fría contiene", "eine #kalte Kante# enthält"}
        },  //clear
            Text{"the #Goron Village Deku Flower# leads to", "la #fleur mojo du village goron# mène à", "la Flor Deku en la Aldea Goron resguarda", "die #Deku-Blume im Goronendorf# führt zu"}
    );
    hintTable[GORON_VILLAGE_POWDER_KEG_CHALLENGE_SPRING] = HintText::Sometimes({
            //obscure
            Text{"a #large goron# rewards", "un #grand goron# confie", "un enorme goron recompensa con", "ein #großer Gorone# entlohnt"}
        },  //clear
            Text{"the #oversized Goron# has", "le #grand goron qui vends des barils de poudre# a", "el enorme Goron en la cueva tiene", "der #übergroße Gorone# hat"}
    );
    hintTable[GORON_VILLAGE_SCRUB_PURCHASE_SPRING] = HintText::Sometimes({
            //obscure
            Text{"a #northern merchant# sells", "un #marchand septentrional# vend", "un mercader en el norte vende", "ein #nördlicher Händler# verkauft"}
        },  //clear
            Text{"the #Goron Village Business Scrub# sells", "la #peste marchande du village goron# vend", "el Mercader Deku en la Aldea Goron vende", "der #Deku-Händler im Goronendorf# verkauft"}
    );
    hintTable[GORON_VILLAGE_SCRUB_TRADE_SPRING] = HintText::Sometimes({
            //obscure
            Text{"a #northern merchant# trades", "un #marchand septentrional# échange", "un mercader en el norte intercambia por", "ein #nördlicher Händler# tauscht"}
        },  //clear
            Text{"Business Scrubs #trade for the Swamp Title Deed#", "une peste marchande #échange un titre de marais# contre", "el Mercader Deku intercambia la propiedad del Pantano por", "Deku-Händler #tauschen gegen die Sumpf-Urkunde#"}
    );
    hintTable[GORON_VILLAGE_LEDGE_SPRING] = HintText::Sometimes({
            //obscure
            Text{"a #cold ledge# contains", "un #rebord froid# recèle", "una cornisa fría contiene", "eine #kalte Kante# enthält"}
        },  //clear
            Text{"the #Goron Village Deku Flower# leads to", "la #fleur mojo du village goron# mène à", "la Flor Deku en la Aldea Goron resguarda", "die #Deku-Blume im Goronendorf# führt zu"}
    );
    hintTable[GORON_VILLAGE_GORON_LULLABY] = HintText::Sometimes({
            //obscure
            Text{"a #lonely child# teaches", "un #enfant délaissé# enseigne", "un niño solitario enseña", "ein #einsames Kind# lehrt"}
        },  //clear
            Text{"the #crying baby Goron# has", "le #bébé goron qui pleure# a", "el Goron bebé llorón tiene", "das #weinende Goronen-Baby# hat"}
    );
    hintTable[LENS_CAVE_RED_RUPEE] = HintText::Sometimes({
            //obscure
            Text{"a #lonely peak# contains", "un #pic esseulé# contient", "una cumbre solitaria contiene", "ein #einsamer Gipfel# enthält"}
        },  //clear
            Text{"the #buried chest inside Goron Village's Lone Peak Shrine# contains", "le #coffre enseveli du sanctuaire reculé du village goron# contient", "el cofre enterrado en la cueva de la Aldea Goron contiene", "die #vergrabene Truhe im einsamen Gipfel-Schrein# enthält"}
    );
    hintTable[LENS_CAVE_PURPLE_RUPEE] = HintText::Sometimes({
            //obscure
            Text{"a #lonely peak# contains", "un #pic esseulé# contient", "una cumbre solitaria contiene", "ein #einsamer Gipfel# enthält"}
        },  //clear
            Text{"the #hidden chest inside Goron Village's Lone Peak Shrine# contains", "le #coffre invisible du sanctuaire reculé du village goron# contient", "el cofre oculto en la cueva de la Aldea Goron contiene", "die #versteckte Truhe im einsamen Gipfel-Schrein# enthält"}
    );
    hintTable[GORON_SHOP_ITEM_1] = HintText::Sometimes({
            //obscure
            Text{"a #goron shop# sells", "une #boutique minière# vend", "una tienda Goron vende", "ein #Goronenladen# verkauft"}
        },  //clear
            Text{"the #Goron Shop# sells", "la #boutique goron# vend", "la tienda Goron vende", "der #Goronen-Laden# verkauft"}
    );
    hintTable[GORON_SHOP_ITEM_2] = HintText::Sometimes({
            //obscure
            Text{"a #goron shop# sells", "une #boutique minière# vend", "una tienda Goron vende", "ein #Goronenladen# verkauft"}
        },  //clear
            Text{"the #Goron Shop# sells", "la #boutique goron# vend", "la tienda Goron vende", "der #Goronen-Laden# verkauft"}
    );
    hintTable[GORON_SHOP_ITEM_3] = HintText::Sometimes({
            //obscure
            Text{"a #goron shop# sells", "une #boutique minière# vend", "una tienda Goron vende", "ein #Goronenladen# verkauft"}
        },  //clear
            Text{"the #Goron Shop# sells", "la #boutique goron# vend", "la tienda Goron vende", "der #Goronen-Laden# verkauft"}
    );
//Great Bay Coast
    hintTable[GBC_OCEAN_SPIDER_DAY1] = HintText::Sometimes({
            //obscure
            Text{"a #new ocean home owner# rewards", "un #emménagement côtier# octroie", "un nuevo dueño de una casa en el océano recompensa con", "Der #Besitzer eines Meereshauses# entlohnt"}
        },  //clear
            Text{"#cleaning the Oceanside Spider House on the first day# awards", "#vaincre les araîgnées de la maison de la côte# donne", "limpiar la casa de las arañas de la playa en el primer día otorga", "das #Säubern des Spinnenhauses am Ozean am ersten Tag# bringt"}
    );
    //hintTable[GBC_OCEAN_SPIDER_DAY2] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "une récompense #indisponible en 3D# est", "un nuevo dueño de una casa en el océano recompensa con", "Der #Besitzer eines Meereshauses# entlohnt"}
    //    },  //clear
    //        Text{"#cleaning the Oceanside Spider House on the second day# awards", "#vaincre les araîgnées de la maison de la côte au 2ème jour# donne", "limpiar la casa de las arañas de la playa en el segundo día otorga", "das #Säubern des Spinnenhauses am Ozean am zweiten Tag# bringt"}
    //);
    //hintTable[GBC_OCEAN_SPIDER_DAY3] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "une récompense #indisponible en 3D# est", "un nuevo dueño de una casa en el océano recompensa con", "Der #Besitzer eines Meereshauses# entlohnt"}
    //    },  //clear
    //        Text{"#cleaning the Oceanside Spider House on the final day# awards", "#vaincre les araîgnées de la maison de la côte au dernier jour# donne", "limpiar la casa de las arañas de la playa en el último día otorga", "das #Säubern des Spinnenhauses am Ozean am letzten Tag# bringt"}
    //);
    hintTable[GBC_FISHERMAN_GAME] = HintText::Sometimes({
            //obscure
            Text{"an #ocean game# rewards", "un #jeu bondissant# offre", "un juego en el océano recompensa con", "ein #Meeresspiel# entlohnt"}
        },  //clear
            Text{"the #Fisherman's Jumping Game's reward# is", "le #prix de jeu de sauts du pêcheur# est", "la recompensa del juego de saltos del pescador es", "die Belohnung beim #Sprungspiel des Fischers# ist"}
    );
    hintTable[GBC_OCEAN_SPIDER_CHEST] = HintText::Sometimes({
            //obscure
            Text{"the #colored masks# contain", "les #masques colorés# protègent", "las máscaras de colores contienen", "die #bunten Masken# enthalten"}
        },  //clear
            Text{"the #Oceanside Spider House chest# contains", "le #coffre de la maison des araignées de la côte# contient", "el cofre en la casa de las arañas de la playa contiene", "die #Truhe im Spinnenhaus am Ozean# enthält"}
    );
    hintTable[GBC_LAB_FISH] = HintText::Sometimes({
            //obscure
            Text{"#feeding the fish# rewards", "une #croissance ichtyenne# dévoile", "alimentar a los peces recompensa con", "ein #satter Fisch# entlohnt"}
        },  //clear
            Text{"the #Marine Research Lab's fish# have", "les #poissons du labo de recherche océanique# ont", "los peces en el Laboratorio de Investigación Marina tienen", "die #Fische im Maritimen Forschungslabor# haben"}
    );
    hintTable[GBC_LEDGE] = HintText::Sometimes({
            //obscure
            Text{"an #ocean ledge# contains", "un #rebord côtier# recèle", "una cornisa en el océano contiene", "eine #Meereskante# entlohnt"}
        },  //clear
            Text{"the #alcove at Great Bay Coast# contains", "la #falaise de la côte de la Grande Baie# recèle", "la cornisa en la Costa de la Gran Bahía tiene", "der #Felsvorsprung an der Küste der Schädelbucht# enthält"}
    );
    hintTable[GBC_MIKAU] = HintText::Sometimes({
            //obscure
            Text{"a #healed spirit# rewards", "l'#apaisement d'un guitariste# crée", "un espíritu curado recompensa con", "ein #geheilter Geist# entlohnt"}
        },  //clear
            Text{"#Mikau# has", "#Mikau# a", "Mikau tiene", "#Mikau# hat"}
    );
    hintTable[GBC_BABY_ZORAS] = HintText::Sometimes({
            //obscure
            Text{"the #pirates' loot# teaches", "le #butin des pirates# enseigne", "el botín de los piratas enseña", "die #Piratenbeute# lehrt"}
        },  //clear
            Text{"the #baby Zoras# have", "les #bébés zoras# ont", "los bebés Zora tienen", "die #Zora-Babys# haben"}
    );
    hintTable[GBC_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"an #ocean cave# contains", "un #trou côtier# contient", "una cueva en el océano contiene", "eine #Meereshöhle# enthält"}
        },  //clear
            Text{"the #Great Bay Coast grotto# contains", "le #trou de la Grande Baie# contient", "la gruta en la Costa de la Gran Bahía contiene", "die #Erdhöhle an der Küste der Schädelbucht# enthält"}
    );
    hintTable[GBC_GROTTO_COW1] = HintText::Sometimes({
            //obscure
            Text{"a #lost creature# gives", "un #ruminant côtier# prodigue", "una criatura perdida da", "ein #verirrtes Wesen# übergibt"}
        },  //clear
            Text{"the #cows beneath Great Bay Coast# have", "les #vaches sous la Grande Baie# ont", "las vacas en la Costa de la Gran Bahía tienen", "die #Kühe unter der Küste der Schädelbucht# haben"}
    );
    hintTable[GBC_GROTTO_COW2] = HintText::Sometimes({
            //obscure
            Text{"a #lost creature# gives", "un #ruminant côtier# prodigue", "una criatura perdida da", "ein #verirrtes Wesen# übergibt"}
        },  //clear
            Text{"the #cows beneath Great Bay Coast# have", "les #vaches sous la Grande Baie# ont", "las vacas en la Costa de la Gran Bahía tienen", "die #Kühe unter der Küste der Schädelbucht# haben"}
    );
    hintTable[GBC_FISHERMAN_PHOTO] = HintText::Sometimes({
            //obscure
            Text{"a #fisherman# rewards", "un #pêcheur# échange", "un pescador recompensa con", "ein #Fischer# entlohnt"}
        },  //clear
            Text{"the #fisherman# trades for a picture", "le #pêcheur# échange un cliché contre", "el pescador intercambia una luminografía por", "der #Fischer# tauscht gegen ein Foto"}
    );
    hintTable[TINGLE_GBC_GB] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende", "ein #Kartenzeichner# verkauft"}
        },  //clear
            Text{"#Tingle sells near the ocean#", "#près de l'océan, Tingle# vend", "Tingle en el océano vende", "#Tingle verkauft in der Nähe des Ozeans#"}
    );
    hintTable[TINGLE_GBC_ST] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende", "ein #Kartenzeichner# verkauft"}
        },  //clear
            Text{"#Tingle sells near the ocean#", "#près de l'océan, Tingle# vend", "Tingle en el océano vende", "#Tingle verkauft in der Nähe des Ozeans#"}
    );
//Ikana Canyon
    hintTable[IKANA_CANYON_GREAT_FAIRY] = HintText::Sometimes({
            //obscure
            Text{"the #fairy of kindness# rewards", "la #fée de la bonté# prodigue", "la hada de la bondad recompensa con", "die #gute Fee# entlohnt"}
        },  //clear
            Text{"the #Ikana Canyon Great Fairy# has", "la #grande fée de la vallée d'Ikana# a", "la Gran Hada en el Cañón de Ikana tiene", "die #Große Fee im Ikana-Canyon# hat"}
    );
    hintTable[IKANA_CANYON_POE_HUT_HP] = HintText::Sometimes({
            //obscure
            Text{"a #game of ghosts# rewards", "une #arène spectrale# remet", "un juego de fantasmas recompensa con", "ein #Geisterspiel# entlohnt"}
        },  //clear
            Text{"#defeating the Poe Sisters# awards", "le #prix de la hutte des fantômes# est", "derrotar a las hermanas Poe otorga", "das #Besiegen der Irrlicht-Schwestern# bringt"}
    );
    hintTable[IKANA_CANYON_LEDGE] = HintText::Sometimes({
            //obscure
            Text{"a #canyon ledge# contains", "un #rebord de vallée# recèle", "una repisa en el cañón contiene", "eine #Canyonkante# enthält"}
        },  //clear
            Text{"the #Ikana Canyon Deku Flower# leads to", "la #fleur mojo de la vallée d'Ikana# mène à", "la Flor Deku en el Cañón de Ikana resguarda", "die #Deku-Blume im Ikana-Canyon# führt zu"}
    );
    hintTable[IKANA_CANYON_PAMELAS_FATHER] = HintText::Sometimes({
            //obscure
            Text{"a #lost father# rewards", "un #chercheur est maudit par#", "un padre absorto recompensa con", "ein #verlorener Vater# entlohnt"}
        },  //clear
            Text{"#Pamela's father# has", "le #chercheur de fées, alias père de Pamela#, a", "el padre de Pamela tiene", "#Pamelas Vater# hat"}
    );
    hintTable[IKANA_CANYON_SECRET_SHRINE_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #waterfall cave# contains", "une #trou de cascade# contient", "una cueva en la cascada contiene", "eine #Wasserfallhöhle# enthält"}
        },  //clear
            Text{"the #Ikana Canyon grotto behind the waterfall# contains", "le #trou derrière la cascade de la vallée d'Ikana# contient ", "la gruta detrás de la cascada en el Cañón de Ikana contiene", "die #Erdhöhle hinter dem Wasserfall im Ikana-Canyon# enthält"}
    );
    hintTable[IKANA_CANYON_SCRUB_TRADE] = HintText::Sometimes({
            //obscure
            Text{"an #eastern merchant# trades", "un #marchand oriental# échange", "un mercader del este intercambia por", "ein #östlicher Händler# tauscht"}
        },  //clear
            Text{"Business Scrubs #trade for the Ocean Title Deed#", "une peste marchande #échange un titre d'océan# contre", "el Mercader Deku intercambia la propiedad del Océano por", "Deku-Händler #tauschen gegen die Meer-Urkunde#"}
    );
    hintTable[IKANA_CANYON_SCRUB_PURCHASE] = HintText::Sometimes({
            //obscure
            Text{"an #eastern merchant# sells", "un #marchand oriental# vend", "un mercader del este vende", "ein #östlicher Händler# verkauft"}
        },  //clear
            Text{"the #Ikana Canyon Business Scrub# sells", "la #peste marchande de la vallée d'Ikana# vend", "el Mercader Deku en el Cañón de Ikana vende", "der #Deku-Händler im Ikana-Canyon# verkauft"}
    );
    hintTable[TINGLE_IKANA_CANYON_ST] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende", "ein #Kartenzeichner# verkauft"}
        },  //clear
            Text{"#Tingle sells at the canyon#", "à #Ikana, Tingle# vend", "Tingle en el cañón vende", "#Tingle verkauft im Canyon#"}
    );
    hintTable[TINGLE_IKANA_CANYON_CT] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende", "ein #Kartenzeichner# verkauft"}
        },  //clear
            Text{"#Tingle sells at the canyon#", "à #Ikana, Tingle# vend", "Tingle en el cañón vende", "#Tingle verkauft im Canyon#"}
    );
//Ikana Graveyard
    hintTable[IKANA_GRAVEYARD_DAMPE_DIGGING] = HintText::Sometimes({
            //obscure
            Text{"a #fearful basement# contains", "#déterrer trois flammes# révèle", "un sótano aterrorizante contiene", "ein #spukender Keller# enthält"}
        },  //clear
            Text{"the #Ikana Graveyard's third grave# contains", "la #troisième tombe du cimetière d'Ikana# contient", "la tercera tumba del cementerio de Ikana contiene", "das #dritte Grab auf dem Friedhof von Ikana# enthält"}
    );
    hintTable[IKANA_GRAVEYARD_IRON_KNUCKLE_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #hollow ground# contains", "une #tombe illusoire# contient", "un suelo hueco contiene", "ein #ausgehüllter Boden# enthält"}
        },  //clear
            Text{"the #Ikana Graveyard's second grave# contains", "la #deuxième tombe du cimetière d'Ikana# contient", "la segunda tumba del cementerio de Ikana contiene", "das #zweite Grab auf dem Friedhof von Ikana# enthält"}
    );
    hintTable[IKANA_GRAVEYARD_CAPTAIN_KEETA_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #skeletal leader# rewards", "un #squelette roupilleur# protège", "un líder esquelético recompensa con", "ein #knochiger Hauptmann# entlohnt"}
        },  //clear
            Text{"#Captain Keeta's prize# is", "le prix de #Crâne de Pierre# est", "el regalo del capitán Keeta es", "der #Preis von Hauptmann Keeta# ist"}
    );
    hintTable[IKANA_GRAVEYARD_DAY_ONE_GRAVE_TABLET] = HintText::Sometimes({
            //obscure
            Text{"a #hollow ground# teaches", "#la requête du compositeur# octroie", "un suelo hueco enseña", "ein #ausgehüllter Boden# lehrt"}
        },  //clear
            Text{"the #Ikana Graveyard's first grave's Iron Knuckle# protects", "le #hache-viande de la première tombe du cimetière d'Ikana# protège", "el Nudillo de Hierro en la primera tumba del cementerio protege", "der #Eisenprinz im ersten Grab auf dem Friedhof von Ikana# beschützt"}
    );
    hintTable[IKANA_GRAVEYARD_DAY_ONE_GRAVE_BATS] = HintText::Sometimes({
            //obscure
            Text{"a #cloud of bats# contains", "une #nuée de chauve-souris# protège", "un grupo de murciélagos contiene", "ein #Fledermausschwarm# enthält"}
        },  //clear
            Text{"the #Ikana Graveyard's first grave's chest# contains", "le #coffre de la première tombe du cimetière d'Ikana# protège", "el cofre en la primera tumba del cementerio de Ikana contiene", "die #Truhe im ersten Grab auf dem Friedhof von Ikana# enthält"}
    );
    hintTable[IKANA_GRAVEYARD_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #circled cave# contains", "une #grotte encerclée# contient", "una cueva rodeada contiene", "eine #umkreiste Höhle# enthält"}
        },  //clear
            Text{"the #Ikana Graveyard grotto# contains", "le #trou secret du cimetière d'Ikana# contient", "la gruta en el cementerio de Ikana contiene", "die #Erdhöhle auf dem Friedhof von Ikana# enthält"}
    );
//Laundry Pool
    hintTable[LAUNDRY_POOL_KAFEI] = HintText::Sometimes({
            //obscure
            Text{"a #posted letter# rewards", "#rencontrer un disparu# octroie", "una carta enviada recompensa con", "ein #gesendeter Brief# enthält"}
        },  //clear
            Text{"#Kafei, at the Laundry Pool#, entrusts", "au #lavoir, Kafei# confie", "Kafei te encomienda en el lavadero con", "#Kafei am Waschplatz# übergibt"}
    );
    hintTable[LAUNDRY_POOL_CURIOSITY_SHOP_MAN_ONE] = HintText::Sometimes({
            //obscure
            Text{"a #shady dealer# rewards", "un #commerçant suspect# confie", "un comerciante sospechoso recompensa con", "eine #zwielichtige Gestalt# entlohnt"}
        },  //clear
            Text{"the #man from the Curiosity Shop# entrusts", "le #gérant du bazar# confie", "el encargado de la Tienda de curiosidades te confía con", "der #Mann aus dem Kuriositätenladen# übergibt"}
    );
    hintTable[LAUNDRY_POOL_CURIOSITY_SHOP_MAN_TWO] = HintText::Sometimes({
            //obscure
            Text{"a #shady dealer# rewards", "un #commerçant suspect# confie", "un comerciante sospechoso recompensa con", "eine #zwielichtige Gestalt# entlohnt"}
        },  //clear
            Text{"the #man from the Curiosity Shop# entrusts", "le #gérant du bazar# confie", "el encargado de la Tienda de curiosidades te confía con", "der #Mann aus dem Kuriositätenladen# übergibt"}
    );
    hintTable[LAUNDRY_POOL_GURU_GURU] = HintText::Sometimes({
            //obscure
            Text{"a #musician# gives", "un #musicien ambulant# délègue", "un músico da", "ein #Musiker# entlohnt"}
        },  //clear
            Text{"#Guru-Guru# has", "#Guru-Guru, le musicien voyageur#, a", "Guru-Guru tiene", "#Guru-Guru# hat"}
    );
    hintTable[LAUNDRY_POOL_SF] = HintText::Sometimes({
            //obscure
            Text{"a #lost fairy# is", "une #fée orange# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Laundry Pool Stray Fairy# is", "la #fée égarée de Cadranbourg# est", "la Hada Extraviada del Lavadero es", "die #Verirrte Fee am Waschplatz# ist", "", "la #fée égarée de Bourg-Clocher# est", ""}
    );
//Milk Road
    hintTable[MILK_ROAD_GORMAN_RACE] = HintText::Sometimes({
            //obscure
            Text{"a #sporting event# rewards", "un #pari hippique# octroie", "un evento deportivo recompensa con", "eine #Sportveranstaltung# entlohnt"}
        },  //clear
            Text{"#racing the Gorman Brothers# awards", "#battre les frères Gorman à la course# donne", "derrotar a los hermanos Gorman en la carrera otorga", "ein #Rennen gegen die Gorman-Brüder# bringt"}
    );
    hintTable[MILK_ROAD_GORMAN_MILK_BUY] = HintText::Sometimes({
            //obscure
            Text{"a #dodgy seller# sells", "un #duo suspect# vend", "un vendedor tramposo vende", "ein #zwielichtiger Farmer# verkauft"}
        },  //clear
            Text{"the #Gorman Brothers# sell", "les #frères Gorman# vendent", "los hermanos Gorman venden", "die #Gorman-Brüder# verkaufen"}
    );
    hintTable[MILK_ROAD_KEATON_QUIZ] = HintText::Sometimes({
            //obscure
            Text{"a #mysterious fox# rewards", "un #mystérieux goupil# offre", "un zorro misterioso recompensa con", "ein #geheimnisvoller Fuchs# entlohnt"}
        },  //clear
            Text{"#Keaton# has", "les #keatons# ont", "Keaton tiene", "#Keaton# hat", "", "le #renard qui se cache dans les herbes# a", ""}
    );
    hintTable[TINGLE_MILK_ROAD_RR] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende", "ein #Kartenzeichner# verkauft"}
        },  //clear
            Text{"#Tingle sells near the ranch#", "sur la #route du lait, Tingle# vend", "Tingle cerca del rancho vende", "#Tingle verkauft nahe der Ranch#"}
    );
    hintTable[TINGLE_MILK_ROAD_GB] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende", "ein #Kartenzeichner# verkauft"}
        },  //clear
            Text{"#Tingle sells near the ranch#", "sur la #route du lait, Tingle# vend", "Tingle cerca del rancho vende", "#Tingle verkauft nahe der Ranch#"}
    );
//Mountain Village
    hintTable[MOUNTAIN_VILLAGE_SMITH_DAY_ONE] = HintText::Sometimes({
            //obscure
            Text{"a #mountain smith# crafts", "un #achat acéré# octroie", "un herrero en la montaña forja", "ein #Bergschmied# schmiedet"}
        },  //clear
            Text{"the Mountain #Smithy sells for 100 rupees#", "pour #100 rubis, les forgerons# forgeront", "el herrero por 100 rupias forja", "die #Schmiede in der Bergsiedlung verkauft für 100 Rubine#"}
    );
    hintTable[MOUNTAIN_VILLAGE_SMITH_DAY_TWO] = HintText::Sometimes({
            //obscure
            Text{"a #mountain smith# crafts", "#échanger de l'or# octroie", "un herrero en la montaña forja", "ein #Bergschmied# schmiedet"}
        },  //clear
            Text{"the Mountain #Smithy trades for Gold Dust#", "pour de la #poudre d'or, les forgerons# forgeront", "el herrero con el polvo de oro forja", "die #Schmiede in der Bergsiedlung tauscht Goldstaub# gegen"}
    );
    hintTable[MOUNTAIN_VILLAGE_FROG_CHOIR] = HintText::Sometimes({
            //obscure
            Text{"a #frog choir# rewards", "une #chorale coassante# offre", "un coro de ranas recompensa con", "ein #froschiger Chor# entlohnt"}
        },  //clear
            Text{"the #Frog Choir# has", "la #chorale des grenouilles# a", "el Coro de Ranas tiene", "der #Frosch-Chor# hat"}
    );
    hintTable[MOUNTAIN_VILLAGE_KEATON_QUIZ] = HintText::Sometimes({
            //obscure
            Text{"a #mysterious fox# rewards", "un #mystérieux goupil# offre", "un zorro misterioso recompensa con", "ein #geheimnisvoller Fuchs# entlohnt"}
        },  //clear
            Text{"#Keaton# has", "les #keatons# ont", "Keaton tiene", "#Keaton# hat", "", "le #renard qui se cache dans les herbes# a", ""}
    );
    hintTable[MOUNTAIN_VILLAGE_DARMANI] = HintText::Sometimes({
            //obscure
            Text{"a #mountain spirit# rewards", "un #esprit montagnard# offre", "un espíritu en la montaña recompensa con", "ein #Berggeist# entlohnt"}
        },  //clear
            Text{"#Darmani# has", "#Darmani# a", "Darmani entrega", "#Darmani# hat"}
    );
    hintTable[MOUNTAIN_VILLAGE_HUNGRY_GORON] = HintText::Sometimes({
            //obscure
            Text{"a #hungry goron# rewards", "un #goron affamé# a", "un goron hambriento recompensa con", "ein #hungriger Gorone# entlohnt"}
        },  //clear
            Text{"the #hungry Goron# has", "le #goron affamé# a", "el Goron hambriento tiene", "der #hungrige Gorone# hat"}
    );
    hintTable[MOUNTAIN_WATERFALL_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #springtime waterfall# contains", "une #chute d'eau printanière# contient", "una cascada en primavera contiene", "ein #Wasserfall im Frühling# entlohnt"}
        },  //clear
            Text{"the #springtime Mountain Village chest# contains", "le #coffre derrière la cascade dégelée au village dans la montagne# contient", "el cofre en el Pueblo de la Montaña en primavera contiene", "die #Truhe im Frühling in der Bergsiedlung# enthält"}
    );
    hintTable[MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #springtime cave# contains", "une #grotte printanière# contient", "una cueva en primavera contiene", "eine #Höhle im Frühling# entlohnt"}
        },  //clear
            Text{"the #springtime Mountain Village grotto# contains", "le #trou dévoilé au printemps au village dans la montagne# contient", "la gruta en el Pueblo de la Montaña en primavera contiene", "die #Erdhöhle im Frühling in der Bergsiedlung# enthält"}
    );
//N Clock Town
    hintTable[N_CLOCK_TOWN_GREAT_FAIRY_DEKU] = HintText::Sometimes({
            //obscure
            Text{"the #fairy of magic# rewards", "la #fée des enchantements# prodigue", "la hada de la magia recompensa con", "die #magische Fee# entlohnt"}
        },  //clear
            Text{"the #Clock Town Great Fairy grants to a Deku#", "#montrer le masque mojo à la grande fée de Cadranbourg# octroie", "la hada de la magia recompensa con", "die #Große Fee von Unruh-Stadt verleiht einem Deku#", "", "#montrer le masque mojo à la grande fée de Bourg-Clocher# octroie", ""}
    );
    //hintTable[N_CLOCK_TOWN_BOMBERS_HIDE_SEEK] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "une récompense #indisponible en 3D# est", "un juego de escondidas recompensa con", "ein #Versteckspiel# entlohnt"}
    //    },  //clear
    //        Text{"the #Bombers' hide-and-seek's reward# is", "#réussir l'épreuve des Bombers# fait gagner", "la recompensa del juego de escondidas de los Bombers es", "die #Belohnung fürs Versteckspiel der Bomber# ist"}
    //);
    hintTable[N_CLOCK_TOWN_KEATON_QUIZ] = HintText::Sometimes({
            //obscure
            Text{"a #mysterious fox# rewards", "un #mystérieux goupil# offre", "un zorro misterioso recompensa con", "ein #geheimnisvoller Fuchs# entlohnt"}
        },  //clear
            Text{"#Keaton# has", "les #keatons# ont", "Keaton tiene", "#Keaton# hat", "", "le #renard qui se cache dans les herbes# a", ""}
    );
    hintTable[N_CLOCK_TOWN_DEKU_PLAYGROUND_3DAYS] = HintText::Sometimes({
            //obscure
            Text{"a #game for scrubs# rewards", "un #pro en vol plané# reçoit", "un campo de juegos para matorrales recompensa con", "ein #Spiel für Laubkerle# entlohnt"}
        },  //clear
            Text{"the #Deku Playground's reward# is", "#gagner trois jours de suite à l'aire de jeu des pestes mojo# donne", "la recompensa final del campo de juegos Deku es", "die #Belohnung auf dem Deku-Spielplatz# ist"}
    );
    hintTable[N_CLOCK_TOWN_TREE] = HintText::Sometimes({
            //obscure
            Text{"a #town playground# contains", "une #aire de jeu citadine# recèle", "un campo de juegos contiene", "ein #städtischer Spielplatz# enthählt"}
        },  //clear
            Text{"the #North Clock Town tree# has", "l'#arbre à Cadranbourg-Nord# a", "el árbol en el Norte de la Ciudad Reloj tiene", "der #Baum im Norden von Unruh-Stadt# hat", "", "l'#arbre au nord de Bourg-Clocher# a", ""}
    );
    hintTable[N_CLOCK_TOWN_OLD_LADY] = HintText::Sometimes({
            //obscure
            Text{"an #old lady's struggle# rewards", "#aider une aînée# octroie", "el forcejeo de una anciana recompensa con", "die #Mühen einer alten Dame# entlohnen"}
        },  //clear
            Text{"the #old lady from the Bomb Shop# has", "la #vieille femme de la boutique de bombes# a", "la anciana de la tienda de bombas tiene", "die #Vereitelung von Sakons Raub# entlohnt"}
    );
    hintTable[N_CLOCK_TOWN_GREAT_FAIRY_HUMAN] = HintText::Sometimes({
            //obscure
            Text{"the #fairy of magic# rewards", "la #fée des enchantements# prodigue", "la hada de la magia recompensa con", "die #magische Fee# entlohnt"}
        },  //clear
            Text{"the #Clock Town Great Fairy grants to a Hylian#", "la #grande fée de Cadranbourg# donne à quiconque", "la gran hada en la Ciudad le otorga a un Hyliano", "die #Große Fee von Unruh-Stadt verleiht einem Hylianer#", "", "la #grande fée de Bourg-Clocher# donne à quiconque", ""}
    );
    hintTable[TINGLE_N_CLOCK_TOWN_CT] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende", "ein #Kartenzeichner# entlohnt"}
        },  //clear
            Text{"#Tingle sells in Clock Town#", "à #Cadranbourg, Tingle# vend", "Tingle en Ciudad Reloj vende", "#Tingle verkauft in Unruh-Stadt#", "", "à #Bourg-Clocher, Tingle# vend", ""}
    );
    hintTable[TINGLE_N_CLOCK_TOWN_WF] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende", "ein #Kartenzeichner# entlohnt"}
        },  //clear
            Text{"#Tingle sells in Clock Town#", "à #Cadranbourg, Tingle# vend", "Tingle en Ciudad Reloj vende", "#Tingle verkauft in Unruh-Stadt#", "", "à #Bourg-Clocher, Tingle# vend", ""}
    );
    hintTable[N_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({
            //obscure
            Text{"a #correspondence box# contains", "un #boîte a correspondances# contient", "una caja de correspondencia contiene", "eine #Korrespondenzkiste# entlohnt"}
        },  //clear
            Text{"the #postbox# contains", "la #boîte aux lettres# contient", "el buzón contiene", "der #Briefkasten# enthält"}
    );
    //hintTable[N_CLOCK_TOWN_DEKU_PLAYGROUND_ADAY] = HintText::Sometimes({
    //        //obscure
    //        Text{"a #game for scrubs' daily reward# is", "un #jeu pour pestes# offre quotidiennement", "un juego para matorrales contiene", "ein #Spiel für Laubkerle# entlohnt"}
    //    },  //clear
    //        Text{"the #Deku Playground's daily reward# is", "la #récompense quotidienne de l'aire de jeu des pestes mojo# est", "la recompensa diaria del campo de juegos Deku es", "die tägliche #Belohnung auf dem Deku-Spielplatz# ist"}
    //);
//Road to Snowhead
    hintTable[ROAD_TO_SNOWHEAD_PILLAR] = HintText::Sometimes({
            //obscure
            Text{"a #cold platform# contains", "une #plateforme froide# recèle", "una plataforma fría contiene", "eine #kalte Plattform# enthält"}
        },  //clear
            Text{"the #pillar on the road to Snowhead# has", "le #pilier lointain sur la route du Pic des neiges# recèle", "el pilar en el camino al Pico Nevado tiene", "die #Säule auf dem Weg zum Pic Hibernia# hat", "", "le #pilier lointain sur la route du pic des Neiges# recèle", ""}
    );
    hintTable[ROAD_TO_SNOWHEAD_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #snowy cave# contains", "une #grotte assaillie de neige# contient", "una cueva nevada contiene", "eine #verschneite Höhle# enthält"}
        },  //clear
            Text{"the #grotto near Snowhead# contains", "le #trou près du Pic des neiges# contient", "la gruta cerca del Pico Nevado contiene", "die #Erdhöhle nahe dem Pic Hibernia# enthält", "", "le #trou près du pic des Neiges# contient", ""}
    );
//Pinnacle Rock
    hintTable[PINNACLE_ROCK_SEAHORSES] = HintText::Sometimes({
            //obscure
            Text{"a #fishy reunion# rewards", "une #réunion de poissons# octroie", "una reunión acuática recompensa con", "eine #fischige Wiedervereinigung# enthält"}
        },  //clear
            Text{"the #seahorses# have", "les #hippocampes# ont", "los caballos marinos tienen", "die #Seepferdchen# haben"}
    );
    hintTable[PINNACLE_ROCK_UPPER_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #marine trench# contains", "une #tranchée marine# contient", "una fosa marina contiene", "ein #Graben im Meer# enthält"}
        },  //clear
            Text{"a #chest in Pinnacle Rock# contains", "un #coffre du Pic de pierre# contient", "el cofre superior en la Roca Pináculo contiene", "eine #Truhe am Nadelfelsen# enthält", "", "un #coffre du puits de pierre# contient", ""}
    );
    hintTable[PINNACLE_ROCK_LOWER_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #marine trench# contains", "une #tranchée marine# contient", "una fosa marina contiene", "ein #Graben im Meer# enthält"}
        },  //clear
            Text{"a #chest in Pinnacle Rock# contains", "un #coffre du Pic de pierre# contient", "el cofre inferior en la Roca Pináculo contiene", "eine #Truhe am Nadelfelsen# enthält", "", "un #coffre du puits de pierre# contient", ""}
    );
    hintTable[PINNACLE_ROCK_ZORA_EGG1] = HintText::Sometimes({
            //obscure
            Text{"in a #marine trench# rests", "une #tranchée marine# héberge", "en una fosa marina espera", "in einem #Graben im Meer# ruht"}
        },  //clear
            Text{"#bottling a Zora Egg in Pinnacle Rock# makes", "embouteiller un #œuf de Zora au Pic de pierre# donne", "embotellar un Huevo Zora en Roca Pináculo da", "das #Zora-Ei am Nadelfelsen in eine Flasche zu stecken# bewirkt", "", "embouteiller un #œuf de Zora au puits de pierre# donne", ""}
    );
    hintTable[PINNACLE_ROCK_ZORA_EGG2] = HintText::Sometimes({
            //obscure
            Text{"in a #marine trench# rests", "une #tranchée marine# héberge", "en una fosa marina espera", "in einem #Graben im Meer# ruht"}
        },  //clear
            Text{"#bottling a Zora Egg in Pinnacle Rock# makes", "embouteiller un #œuf de Zora au Pic de pierre# donne", "embotellar un Huevo Zora en Roca Pináculo da", "das #Zora-Ei am Nadelfelsen in eine Flasche zu stecken# bewirkt", "", "embouteiller un #œuf de Zora au puits de pierre# donne", ""}
    );
    hintTable[PINNACLE_ROCK_ZORA_EGG3] = HintText::Sometimes({
            //obscure
            Text{"in a #marine trench# rests", "une #tranchée marine# héberge", "en una fosa marina espera", "in einem #Graben im Meer# ruht"}
        },  //clear
            Text{"#bottling a Zora Egg in Pinnacle Rock# makes", "embouteiller un #œuf de Zora au Pic de pierre# donne", "embotellar un Huevo Zora en Roca Pináculo da", "das #Zora-Ei am Nadelfelsen in eine Flasche zu stecken# bewirkt", "", "embouteiller un #œuf de Zora au puits de pierre# donne", ""}
    );
//Road to Ikana
    hintTable[ROAD_TO_IKANA_PILLAR_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #high chest# contains", "un #coffre haut-placé# contient", "un cofre en lo alto contiene", "eine #hochgelegene Truhe# enthält"}
        },  //clear
            Text{"the #chest on the road to Ikana# contains", "le #coffre perché sur la route d'Ikana# contient", "el cofre sobre el pilar en el camino a Ikana contiene", "die #Truhe auf dem Weg nach Ikana# enthält"}
    );
    hintTable[ROAD_TO_IKANA_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #blocked cave# contains", "une #grotte bouchée# contient", "una cueva obstruida contiene", "eine #blockierte Höhle# enthält"}
        },  //clear
            Text{"the #grotto on the road to Ikana# contains", "le #trou bouché sur la route d'Ikana# contient", "la gruta en el camino a Ikana contiene", "die #Erdhöhle auf dem Weg nach Ikana# enthält"}
    );
//Road to Southern Swamp
    hintTable[ROAD_TO_SS_ARCHERY_1] = HintText::Sometimes({
            //obscure
            Text{"a #swamp game# rewards", "#si tu vises bien comme il faut#, tu gagnes", "un juego en el pantano recompensa con", "ein #Sumpfspiel# entlohnt", "", "#s'tu vises bien correc'#, tu gagnes", ""}
        },  //clear
            Text{"the #Swamp Shooting Gallery's reward# is", "un #des prix du kiosque de tir des marais# est", "la primer recompensa de la Galería de tiro del Pantano es", "die Belohnung der #Schießbude im Sumpf# ist", "", "un #des prix du stand de tir des marais# est", ""}
    );
    hintTable[ROAD_TO_SS_ARCHERY_2] = HintText::Sometimes({
            //obscure
            Text{"a #swamp game# rewards", "#si tu vises bien comme il faut#, tu gagnes", "un juego en el pantano recompensa con", "ein #Sumpfspiel# entlohnt", "", "#s'tu vises bien correc'#, tu gagnes", ""}
        },  //clear
            Text{"the #Swamp Shooting Gallery's reward# is", "un #des prix du kiosque de tir des marais# est", "la segunda recompensa de la Galería de tiro del Pantano es", "die Belohnung der #Schießbude im Sumpf# ist", "", "un #des prix du stand de tir des marais# est", ""}
    );
    hintTable[ROAD_TO_SS_TREE] = HintText::Sometimes({
            //obscure
            Text{"a #batty tree# contains", "un #arbre saigneur# recèle", "un árbol repleto de alas negras tiene", "ein #flatternder Baum# enthält"}
        },  //clear
            Text{"the #tree on the road to Southern Swamp# contains", "l'#arbre sur la route des marais du Sud# abrite", "el árbol en el camino al Pantano del Sur tiene", "der #Baum auf dem Sumpfweg# enthält"}
    );
    hintTable[ROAD_TO_SWAMP_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #southern cave# contains", "une #grotte australe# contient", "una cueva en el sur contiene", "eine #südliche Höhle# enthält"}
        },  //clear
            Text{"the #grotto on the road to Southern Swamp# contains", "le #trou sur la route des marais du Sud# contient", "la gruta en el camino al Pantano del Sur contiene", "die #Erdhöhle auf dem Sumpfweg# enthält"}
    );
    hintTable[TINGLE_ROAD_TO_SS_WF] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende", "ein #Kartenzeichner# entlohnt"}
        },  //clear
            Text{"#Tingle sells near the swamp#", "sur la #route des marais du Sud, Tingle# vend", "Tingle cerca del pantano vende", "#Tingle verkauft nahe dem Sumpf#"}
    );
    hintTable[TINGLE_ROAD_TO_SS_SH] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende", "ein #Kartenzeichner# entlohnt"}
        },  //clear
            Text{"#Tingle sells near the swamp#", "sur la #route des marais du Sud, Tingle# vend", "Tingle cerca del pantano vende", "#Tingle verkauft nahe dem Sumpf#"}
    );
//Romani Ranch
    hintTable[ROMANI_RANCH_ALIEN_DEFENSE] = HintText::Sometimes({
            //obscure
            Text{"a #ranch invasion# rewards", "une #invasion de ranch# octroie", "una invasión al rancho recompensa con", "eine #Ranch-Invasion# entlohnt"}
        },  //clear
            Text{"#warding off the aliens# awards", "repousser les #fantômes au ranch# donne", "repeler a los alienígenas otorga", "das #Abwehren der Außerirdischen# bringt"}
    );
    hintTable[ROMANI_RANCH_DOG_RACE] = HintText::Sometimes({
            //obscure
            Text{"a #sporting event# rewards", "bien comprendre #les chien-chiens# octroie", "un evento deportivo recompensa con", "eine #sportliche Aktivität# entlohnt"}
        },  //clear
            Text{"the #Doggy Racetrack's reward# is", "le #prix spécial de la course pour chiens# est", "la recompensa del canódromo es", "die Belohnung auf der #Hunderennbahn# ist"}
    );
    hintTable[ROMANI_RANCH_GROG] = HintText::Sometimes({
            //obscure
            Text{"a #chicken lover# rewards", "un #amateur de cocottes# offre", "un amante de las gallinas recompensa con", "ein #Hühner-Fan# entlohnt"}
        },  //clear
            Text{"#Grog# has", "le #fanatique de cocottes, Grog#, a", "Grog tiene", "#Grog# hat"}
    );
    hintTable[ROMANI_RANCH_CREMIA_ESCORT] = HintText::Sometimes({
            //obscure
            Text{"an #older sister# rewards", "une #grande sœur# détient", "una hermana mayor recompensa con", "eine #ältere Schwester# entlohnt"}
        },  //clear
            Text{"#Cremia# has", "la #gérante du ranch, Cremia#, a", "Cremia tiene", "#Cremia# hat"}
    );
    hintTable[ROMANI_RANCH_ROMANIS_GAME] = HintText::Sometimes({
            //obscure
            Text{"an #equine reunion# teaches", "une #réunion équestre# enseigne", "una reunión equina recompensa con", "eine #Wiedervereinigung mit einem Fohlen# lehrt"}
        },  //clear
            Text{"#Romani's shooting game's reward# is", "le #prix pour l'entraînement de tir de Romani# est", "la recompensa del juego de tiro de Romani es", "die Belohnung bei #Romanis Schießspiel# ist"}
    );
    hintTable[ROMANI_RANCH_COW_1] = HintText::Sometimes({
            //obscure
            Text{"a #lost creature# gives", "#leur cible# prodigue", "una criatura perdida da", "ein #verirrtes Wesen# übergibt"}
        },  //clear
            Text{"the #Romani Ranch cows# have", "une #vache du ranch Romani# a", "las vacas del rancho Romani tienen", "die #Kühe auf der Romani-Ranch# haben"}
    );
    hintTable[ROMANI_RANCH_COW_2] = HintText::Sometimes({
            //obscure
            Text{"a #lost creature# gives", "#leur cible# prodigue", "una criatura perdida da", "ein #verirrtes Wesen# übergibt"}
        },  //clear
            Text{"the #Romani Ranch cows# have", "une #vache du ranch Romani# a", "las vacas del rancho Romani tienen", "die #Kühe auf der Romani-Ranch# haben"}
    );
    // hintTable[ROMANI_RANCH_COW_3] = HintText::Sometimes({
    //         //obscure
    //         Text{"a #lost creature# gives", "#leur cible# prodigue", "una criatura perdida da", "ein #verirrtes Wesen# übergibt"}
    //     },  //clear
    //         Text{"the #Romani Ranch cows# have", "une #vache du ranch Romani# a", "las vacas del rancho Romani tienen", "die #Kühe auf der Romani-Ranch# haben"}
    // );
    hintTable[DOGGY_RACETRACK_ROOF_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #day at the races# contains", "les #courses sont surplombées# par", "un día en las carreras contiene", "ein #Tag an den Wettläufen# enthält"}
        },  //clear
            Text{"the #Doggy Racetrack chest# contains", "le #coffre de la course pour chiens# contient", "el cofre en el canódromo contiene", "die #Truhe auf der Hunderennbahn# enthält"}
    );
//S Clock Town
    hintTable[S_CLOCK_TOWN_SCRUB_TRADE] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# trades", "un #marchant citadin# échange", "un mercader en la ciudad intercambia por", "ein #Stadthändler# tauscht"}
        },  //clear
            Text{"Business Scrubs #trade for the Moon's Tear#", "une peste marchande #échange une larme de lune# contre", "el Mercader Deku intercambia la Lágrima de la luna por", "Deku-Händler #tauschen gegen die Mondträne#"}
    );
    hintTable[S_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({
            //obscure
            Text{"a #correspondence box# contains", "un #boîte a correspondances# contient", "una caja de correspondencia contiene", "eine #Korrespondenzkiste# entlohnt"}
        },  //clear
            Text{"the #postbox# contains", "la #boîte aux lettres# contient", "el buzón contiene", "der #Briefkasten# enthält"}
    );
    hintTable[S_CLOCK_TOWN_CLOCK_TOWER_ENTRANCE] = HintText::Sometimes({
            //obscure
            Text{"the #tower doors# contain", "un #balcon ponctuel# recèle", "las puertas de la torre contienen", "die #Türen zum Turm# enthalten"}
        },  //clear
            Text{"the #Clock Tower's balcony# contains", "la #balcon de la tour du cadran# contient", "el balcón de la Torre del Reloj tiene", "der #Balkon des Uhrturms# birgt", "", "la #balcon de la tour du clocher# contient", ""}
    );
    hintTable[S_CLOCK_TOWN_STRAW_ROOF_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #straw roof# contains", "un #toit de paille# recèle", "un techo de paja contiene", "ein #Strohdach# enthält"}
        },  //clear
            Text{"a #South Clock Town chest# contains", "le #coffre près du toit de paille à Cadranbourg-Sud# contient", "el cofre en el Sur de la Ciudad Reloj contiene", "eine #Truhe im Süden von Unruh-Stadt# enthält", "", "le #coffre près du toit de paille au sud de Bourg-clocher# contient", ""}
    );
    hintTable[S_CLOCK_TOWN_FINAL_DAY_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #carnival tower# contains", "le #labeur des charpentiers# révèlent", "la torre del carnaval contiene", "ein #Karnivalturm# enthält"}
        },  //clear
            Text{"a #South Clock Town chest# contains", "le #coffre sur la tour de charpentiers à Cadranbourg-Sud# contient", "el cofre sobre la torre en el Sur de la Ciudad Reloj contiene", "eine #Truhe im Süden von Unruh-Stadt# enthält", "", "le #coffre sur la tour de charpentiers au sud de Bourg-clocher# contient", ""}
    );
    hintTable[S_CLOCK_TOWN_BANK_REWARD_1] = HintText::Sometimes({
            //obscure
            Text{"a #keeper of wealth# rewards", "un #début d'épargne# confère", "un guardián de riquezas recompensa con", "ein #Bewahrer der Reichtümer# entlohnt"}
        },  //clear
            Text{"with #200 rupees in the bank#, one gets", "en #épargnant 200 rubis#, on reçoit", "depositar 200 rupias en el banco otorga", "mit #200 Rubinen auf der Bank# erhält man"}
    );
    hintTable[S_CLOCK_TOWN_BANK_REWARD_2] = HintText::Sometimes({
            //obscure
            Text{"#interest# rewards", "#accumuler quatre chiffres# confère", "una comisión recompensa con", "#Zinsen# entlohnen"}
        },  //clear
            Text{"with #1000 rupees in the bank#, one gets", "en #épargnant 1000 rubis#, on reçoit", "depositar 1000 rupias en el banco otorga", "mit #500 Rubinen auf der Bank# erhält man"}
    );
    hintTable[S_CLOCK_TOWN_BANK_REWARD_3] = HintText::Sometimes({
            //obscure
            Text{"#being rich# rewards", "le #plafond de la fortune# confère", "ser rico recompensa con", "#wohlhabend sein# entlohnt"}
        },  //clear
            Text{"with #5000 rupees in the bank#, one gets", "en #épargnant 5000 rubis# on reçoit", "depositar 5000 rupias en el banco otorga", "mit #1000 Rubinen auf der Bank# erhält man"}
    );
//Snowhead
    hintTable[SNOWHEAD_GREAT_FAIRY] = HintText::Sometimes({
            //obscure
            Text{"the #fairy of power# rewards", "la #fée de la force# prodigue", "la hada del poder recompensa con", "die #kräftige Fee# entlohnt"}
        },  //clear
            Text{"the #Snowhead Great Fairy# has", "la #grande fée du Pic des neiges# a", "la hada del Pico Nevado tiene", "die #Große Fee am Pic Hibernia# hat", "", "la #grande fée du pic des Neiges# a", ""}
    );
//Southern Swamp
    hintTable[SOUTHERN_SWAMP_MUSIC_STATUE] = HintText::Exclude({
            //obscure
            Text{"a #guiding owl# teaches", "un #sage hibou# enseigne", "", "eine #geleitende Eule# lehrt"}
        },  //clear
            Text{"the #Southern Swamp entrance's carved stone# teaches", "la #stèle à l'entrée du marais du Sud# enseigne", "", "die #Notengravur am Eingang der Sümpfe des Vergessens# lehrt"}
    );
    hintTable[SOUTHERN_SWAMP_KOUME] = HintText::Sometimes({
            //obscure
            Text{"a #witch# rewards", "une #sorcière soignée# octroie", "una bruja recompensa con", "eine #Hexe# entlohnt"}
        },  //clear
            Text{"#Koume's reward# is a cruise and", "Koumé #offre à son sauveur# une croisière et", "la recompensa de Koume es un viaje en bote y", "die #Belohnung von Koume# ist eine Bootsfahrt und", "", "Koume #offre à son sauveur# une croisière et", ""}
    );
    hintTable[SOUTHERN_SWAMP_KOTAKE] = HintText::Sometimes({
            //obscure
            Text{"a #sleeping witch# rewards", "une #sorcière somnolente# confie", "una bruja durmiente recompensa con", "eine #schlafende Hexe# entlohnt"}
        },  //clear
            Text{"#Kotake# entrusts", "Kotaké confie #à celui qui trouvera Koumé#", "Kotake te confía con", "#Kotake# übergibt", "", "Kotake confie #à celui qui trouvera Koume#", ""}
    );
    hintTable[SOUTHERN_SWAMP_KOTAKE_IN_WOODS] = HintText::Sometimes({
            //obscure
            Text{"a #witch# rewards", "une #sorcière inquiète# confie", "una bruja recompensa con", "eine #Hexe# entlohnt"}
        },  //clear
            Text{"#Kotake# entrusts", "Kotaké confie #à celui qui trouvera Koumé#", "Kotake te confía con", "#Kotake# übergibt", "", "Kotake confie #à celui qui trouvera Koume#", ""}
    );
    hintTable[SOUTHERN_SWAMP_SCRUB_TRADE] = HintText::Sometimes({
            //obscure
            Text{"a #southern merchant# trades", "un #marchand austral# vend", "un mercader del sur intercambia por", "ein #südlicher Händler# tauscht"}
        },  //clear
            Text{"Business Scrubs #trade for the Town Title Deed#", "une peste marchande #échange un titre de terre# contre", "el Mercader Deku intercambia la propiedad de la Ciudad por", "Deku-Händler #tauschen gegen die Land-Urkunde#"}
    );
    hintTable[SOUTHERN_SWAMP_PICTOGRAPH_WINNER] = HintText::Sometimes({
            //obscure
            Text{"a #swamp game# rewards", "gagner un #concours marécageux# octroie", "un juego del pantano recompensa con", "ein #Sumpfspiel# entlohnt"}
        },  //clear
            Text{"the #Pictograph Contest's first prize# is", "le #premier prix du concours de photos# est", "el primer premio del Concurso de Luminografías es", "der #erste Preis beim Foto-Wettbewerb# ist"}
    );
    hintTable[SOUTHERN_SWAMP_BOAT_ARCHERY] = HintText::Sometimes({
            //obscure
            Text{"a #swamp game# rewards", "#frôler un balai habilement# octroie", "un juego del pantano recompensa con", "ein #Sumpfspiel# entlohnt"}
        },  //clear
            Text{"#scoring 20 points at Koume's game# awards", "marquer 20 points à la #croisière aux cible de Koumé# fait gagner", "hacer 20 puntos en el juego de Koume otorga", "das #Erreichen von 20 Punkten bei Koumes Spiel# bringt", "", "marquer 20 points à la #croisière aux cible de Koume# fait gagner", ""}
    );
    hintTable[SWAMP_TOURIST_CENTER_ROOF] = HintText::Sometimes({
            //obscure
            Text{"a #tourist center# contains", "un #toit touristique# recèle", "un centro turístico contiene", "ein #Infocenter# enthält"}
        },  //clear
            Text{"the #Deku Flower near the Swamp Tourist Center# leads to", "la #fleur mojo près de l'office du tourisme des marais# mène à", "la Flor Deku al lado del Centro Turístico del pantano lleva a", "die #Deku-Blume beim Sumpf-Infozentrum# führt zu"}
    );
    hintTable[SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #swampy cave# contains", "une #grotte marécageuse# contient", "una cueva pantanosa contiene", "eine #sumpfige Höhle# enthält"}
        },  //clear
            Text{"the #Southern Swamp grotto# contains", "le #trou près de la maison des araignées des marais# contient", "la gruta en el Pantano del Sur contiene", "die #Grotte in den Sümpfen des Vergessens# enthält"}
    );
    hintTable[SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD] = HintText::Sometimes({
            //obscure
            Text{"a #swamp spider man# rewards", "un #homme-araignée# est maudit par", "un hombre araña del pantano recompensa con", "ein #Sumpf-Spinnenmann# entlohnt"}
        },  //clear
            Text{"the #Swamp Spider House's# reward is", "la #récompense de la maison des araignées des marais# est", "la recompensa de la casa de las arañas del pantano es", "die Belohnung im #Spinnenhaus im Sumpf# ist"}
    );
    hintTable[SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #mystery cave# contains", "une #grotte ponctuelle# contient", "una cueva misteriosa contiene", "eine #mysteriöse Höhle# enthält"}
        },  //clear
            Text{"the #Woods of Mystery grotto# contains", "le #trou du 2ème jour du boisé mystérieux# contient", "la gruta en el Bosque Misterioso contiene", "die #Erdhöhle in den Wäldern der Mysterien# enthält", "", "le #trou du 2ème jour des bois-mystère# contient", ""}
    );
    hintTable[SOUTHERN_SWAMP_KOTAKE_MUSHROOM_SALE] = HintText::Sometimes({
            //obscure
            Text{"a #sleeping witch# rewards", "une #apothicaire# échange", "una bruja durmiente recompensa con", "eine #schlafende Hexe# entlohnt"}
        },  //clear
            Text{"Kotake #trades for a Magic Mushroom#", "Kotaké #échange un champignon magique# contre", "Kotake intercambia un champiñón mágico por", "Kotake #tauscht gegen einen Duftpilz#", "", "Kotake #échange un champignon magique# contre", ""}
    );
    //hintTable[SOUTHERN_SWAMP_PICTOGRAPH_STANDARD] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "un #cliché banal# octroie", "una toma pantanosa recompensa con", "ein #Foto# entlohnt"}
    //    },  //clear
    //        Text{"the #Pictograph Contest's third prize# is", "le #troisième prix du concours de photos# est", "el tercer premio del Concurso de Luminografías es", "der #dritte Preis beim Foto-Wettbewerb# ist"}
    //);
    //hintTable[SOUTHERN_SWAMP_PICTOGRAPH_GOOD] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "un #cliché convenable# octroie", "una toma pantanosa recompensa con", "ein #gutes Foto# entlohnt"}
    //    },  //clear
    //        Text{"the #Pictograph Contest's second prize# is", "le #deuxième prix du concours de photos# est", "el segundo premio del Concurso de Luminografías es", "der #zweite Preis beim Foto-Wettbewerb# ist"}
    //);
    hintTable[SOUTHERN_SWAMP_SCRUB_PURCHASE] = HintText::Sometimes({
            //obscure
            Text{"a #southern merchant# sells", "un #marchand austral# vend", "un mercader del sur vende", "ein #südlicher Händler# verkauft"}
        },  //clear
            Text{"the #Southern Swamp Business Scrub# sells", "la #peste marchande des marais du Sud# vend", "el Mercader Deku en el Pantano del Sur vende", "der #Deku-Händler in den Sümpfen des Vergessens# verkauft"}
    );
    hintTable[SOUTHERN_SWAMP_SCRUB_PURCHASE_CLEAR] = HintText::Sometimes({
            //obscure
            Text{"a #southern merchant# sells", "un #marchand austral# vend", "un mercader del sur vende", "ein #südlicher Händler# verkauft"}
        },  //clear
            Text{"the #Southern Swamp Business Scrub# sells", "la #peste marchande des marais du Sud# vend", "el Mercader Deku en el Pantano del Sur vende", "der #Deku-Händler in den Sümpfen des Vergessens# verkauft"}
    );
    hintTable[SOUTHERN_SWAMP_SCRUB_TRADE_CLEAR] = HintText::Sometimes({
            //obscure
            Text{"a #southern merchant# trades", "un #marchand austral# échange", "un mercader del sur intercambia por", "ein #südlicher Händler# tauscht"}
        },  //clear
            Text{"Business Scrubs #trade for the Town Title Deed#", "une peste marchande #échange un titre de terre# contre", "el Mercadee Deku intercambia la propiedad de la Ciudad por", "Deku-Händler #tauschen gegen die Land-Urkunde#"}
    );
    hintTable[SWAMP_TOURIST_CENTER_ROOF_CLEAR] = HintText::Sometimes({
            //obscure
            Text{"a #tourist center# contains", "un #toit touristique# recèle", "un centro turístico contiene", "ein #Infocenter# enthält"}
        },  //clear
            Text{"the #Deku Flower near the Swamp Tourist Center# leads to", "la #fleur mojo près de l'office du tourisme des marais# mène à", "la Flor Deku al lado del Centro Turístico del pantano lleva a", "die #Deku-Blume beim Informationszentrum# führt zu"}
    );
    hintTable[POTION_SHOP_ITEM_1] = HintText::Sometimes({
            //obscure
            Text{"a #potion maker# sells", "une #apothicaire# vend", "una fabricante de pociones vende", "ein #Elixierbrauer# verkauft"}
        },  //clear
            Text{"the #Hags' Potion Shop# sells", "la #boutique de potions# vend", "la Tienda de Pociones Mágicas vende", "der #Magie-Laden \"Zur alten Schachtel\"# verkauft"}
    );
    hintTable[POTION_SHOP_ITEM_2] = HintText::Sometimes({
            //obscure
            Text{"a #potion maker# sells", "une #apothicaire# vend", "una fabricante de pociones vende", "ein #Elixierbrauer# verkauft"}
        },  //clear
            Text{"the #Hags' Potion Shop# sells", "la #boutique de potions# vend", "la Tienda de Pociones Mágicas vende", "der #Magie-Laden \"Zur alten Schachtel\"# verkauft"}
    );
    hintTable[POTION_SHOP_ITEM_3] = HintText::Sometimes({
            //obscure
            Text{"a #potion maker# sells", "une #apothicaire# vend", "una fabricante de pociones vende", "ein #Elixierbrauer# verkauft"}
        },  //clear
            Text{"the #Hags' Potion Shop# sells", "la #boutique de potions# vend", "la Tienda de Pociones Mágicas vende", "der #Magie-Laden \"Zur alten Schachtel\"# verkauft"}
    );
//Stock Pot Inn
    hintTable[STOCKPOTINN_RESERVATION] = HintText::Sometimes({
            //obscure
            Text{"#checking-in# rewards", "#à l'accueil#, M. @-goro recevra", "registrarse recompensa con", "#Einchecken# entlohnt"}
        },  //clear
            Text{"a Goron had a #Stock Pot Inn reservation# for", "un Goron a une #réservation à l'auberge# pour", "un Goron tenía una reservación en la Posada del Puchero para", "ein Gorone hatte eine #Reservierung im Gasthof \"Zum Eintopf\"# für"}
    );
    hintTable[STOCKPOTINN_MIDNIGHT_MEETING] = HintText::Sometimes({
            //obscure
            Text{"a #late meeting# rewards", "un #rendez-vous nocturne# octroie", "una reunión tardía recompensa con", "ein #spätes Treffen# entlohnt"}
        },  //clear
            Text{"#Anju entrusts at midnight#", "à #minuit, Anju# confie", "Anju te confía a medianoche con", "#Anju übergibt um Mitternacht#"}
    );
    hintTable[STOCKPOTINN_TOILET_HAND] = HintText::Sometimes({
            //obscure
            Text{"a #strange palm# rewards", "une #paume étrange# offre", "una palma extraña recompensa con", "eine #komische Hand# entlohnt"}
        },  //clear
            Text{"the #hand in Stock Pot Inn# has", "la #mystérieuse main de l'auberge# a", "una palma extraña recompensa con", "die #Hand im Gasthof \"Zum Eintopf\"# hat"}
    );
    hintTable[STOCKPOTINN_GRANDMA_SHORT_STORY] = HintText::Sometimes({
            //obscure
            Text{"an #old lady# rewards", "#s'instruire sur les traditions# octroie", "una anciana recompensa con", "eine #alte Dame# entlohnt"}
        },  //clear
            Text{"#Anju's Grandmother# has", "la #grand-mère d'Anju# a", "La abuela de Anju tiene", "#Anjus Großmutter# hat"}
    );
    hintTable[STOCKPOTINN_GRANDMA_LONG_STORY] = HintText::Sometimes({
            //obscure
            Text{"an #old lady# rewards", "#s'instruire sur les traditions# octroie", "una anciana recompensa con", "eine #alte Dame# entlohnt"}
        },  //clear
            Text{"#Anju's Grandmother# has", "la #grand-mère d'Anju# a", "La abuela de Anju tiene", "#Anjus Großmutter# hat"}
    );
    hintTable[STOCKPOTINN_ANJU_AND_KAFEI] = HintText::Sometimes({
            //obscure
            Text{"a #lovers' reunion# rewards", "une #réunion d'amants# octroie", "una reunión de amantes recompensa con", "eine #Wiedervereinigung Verliebter# entlohnt"}
        },  //clear
            Text{"#Anju and Kafei exchange their vows# to form", "le #serment d'amour d'Anju et Kafei# donne forme à", "Anju y Kafei hacen sus votos para formar", "#Anju und Kafei tauschen ihre Verlobungsmasken# gegen"}
    );
    hintTable[STOCKPOTINN_STAFF_ROOM_CHEST] = HintText::Sometimes({
            //obscure
            Text{"an #employee room# contains", "les #employés# ont accès exclusif sur", "un cuarto de empleados contiene", "ein #Mitarbeiter# enthält"}
        },  //clear
            Text{"the #Stock Pot Inn Staff Room# contains", "la #pièce des employés de l'auberge# contient", "el cuarto de empleados de la Posada contiene", "das #Personalzimmer im Gasthof Zum Eintopf# enthält"}
    );
    hintTable[STOCKPOTINN_GUEST_ROOM_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #guest bedroom# contains", "une #chambre réservée# contient", "un cuarto de huéspedes contiene", "ein #Gästezimmer# enthäkt"}
        },  //clear
            Text{"the #Stock Pot Inn Knife Chamber# contains", "la #chambre du couteau à l'auberge# contient", "la Suite Cuchillo en la Posada contiene", "das #Waffenkammer im Gasthof Zum Eintopf# enthält"}
    );
//Stone Tower
    hintTable[STONE_TOWER_INVERTED_RIGHT_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #sky below# contains", "le #ciel-sous-pied# cache", "un cielo por debajo contiene", "ein #Firmament in der Tiefe# enthält"}
        },  //clear
            Text{"a #bean patch in the inverted Stone Tower# leads to", "le #coin de terre meuble de la forteresse de pierre inversée# mène à", "la tierra blanda en la Torre de Piedra Invertida guía hacia", "ein #Fleckchen weicher Erde im umgedrehten Felsenturm# führt zu"}
    );
    hintTable[STONE_TOWER_INVERTED_CENTER_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #sky below# contains", "le #ciel-sous-pied# cache", "un cielo por debajo contiene", "ein #Firmament in der Tiefe# enthält"}
        },  //clear
            Text{"a #bean patch in the inverted Stone Tower# leads to", "le #coin de terre meuble de la forteresse de pierre inversée# mène à", "la tierra blanda en la Torre de Piedra Invertida guía hacia", "ein #Fleckchen weicher Erde im umgedrehten Felsenturm# führt zu"}
    );
    hintTable[STONE_TOWER_INVERTED_LEFT_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #sky below# contains", "le #ciel-sous-pied# cache", "un cielo por debajo contiene", "ein #Firmament in der Tiefe# enthält"}
        },  //clear
            Text{"a #bean patch in the inverted Stone Tower# leads to", "le #coin de terre meuble de la forteresse de pierre inversée# mène à", "la tierra blanda en la Torre de Piedra Invertida guía hacia", "ein #Fleckchen weicher Erde im umgedrehten Felsenturm# führt zu"}
    );
//Termina Field
    hintTable[TERMINA_FIELD_MOONS_TEAR] = HintText::Sometimes({
            //obscure
            Text{"a #falling star# contains", "une #étoile filante# contient", "una estrella fugaz contiene", "ein #stürzender Stern# enthält"}
        },  //clear
            Text{"the #Moon drops#", "la #lune fait tomber#", "la Luna deja caer", "der #Mond tränt#"}
    );
    hintTable[TERMINA_FIELD_GOSSIP_STONES] = HintText::Sometimes({
            //obscure
            Text{"#mysterious stones# reward", "#mes congénères# offrent", "piedras misteriosas recompensan con", "#mysteriöse Steine# enthalten"}
        },  //clear
            Text{"the #Gossip Stones beneath Termina Field# have", "les #pierres à potins sous la plaine Termina# ont", "las Piedras Chisomas bajo el Campo de Términa tienen", "die #Mythensteine unter den Ebenen von Termina# haben"}
    );
    hintTable[TERMINA_FIELD_BUSINESS_SCRUB] = HintText::Sometimes({
            //obscure
            Text{"a #hidden merchant# sells", "un #marchand furtif# vend", "un mercader oculto vende", "ein #versteckter Händler# verkauft"}
        },  //clear
            Text{"the #Business Scrub beneath Termina Field# sells", "la #peste marchande sous la plaine Termina# vend", "el Mercader Deku bajo el Campo de Términa tiene", "der #Deku-Händler unter den Ebenen von Termina# verkauft"}
    );
    hintTable[TERMINA_FIELD_PEAHAT_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #hollow ground# contains", "vaincre des #feuilles qui tournent# octroie", "un suelo hueco contiene", "ein #ausgehüllter Boden# enthält"}
        },  //clear
            Text{"the #Termina Field Peahat grotto# contains", "le #trou du poislico de la plaine Termina# contient", "la gruta con el Peahat en el Campo de Términa contiene", "die #Killeranas-Erdhöhle in den Ebenen von Termina# enthält", "", "le #trou de la peahat de la plaine Termina# contient", ""}
    );
    hintTable[TERMINA_FIELD_DODONGO_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #hollow ground# contains", "exterminer des #lézards explosifs# octroie", "un suelo hueco contiene", "ein #ausgehüllter Boden# enthält"}
        },  //clear
            Text{"the #Termina Field Dodongo grotto# contains", "le #trou des dodongos de la plaine Termina# contient", "la gruta con Dodongos en el Campo de Términa contiene", "die #Dodongo-Erdhöhle in den Ebenen von Termina# enthält"}
    );
    hintTable[TERMINA_FIELD_BIO_BABA_GROTTO_BEEHIVE] = HintText::Sometimes({
            //obscure
            Text{"a #beehive# contains", "une #ruche# contient", "un panal contiene", "ein #Bienennest# enthält"}
        },  //clear
            Text{"the #Termina Field Bio Baba grotto# contains", "le #trou aux ruches de la plaine Termina# contient", "la gruta con Bio Babas Deku en el Campo de Términa contiene", "die #Bio-Deku-Baba-Grotte in den Ebenen von Termina# enthält"}
    );
    hintTable[TERMINA_FIELD_KAMARO] = HintText::Sometimes({
            //obscure
            Text{"a #dancer# rewards", "une #âme d'artiste# lègue", "un bailarín recompensa con", "ein #Tänzer# entlohnt"}
        },  //clear
            Text{"#Kamaro# has", "l'#esprit du danseur Kamaro# a", "Kamaro tiene", "#Kamaro# hat"}
    );
    hintTable[TERMINA_FIELD_PILLAR_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #hollow pillar# contains", "un #pilier creux# contient", "un pilar hueco", "eine #leere Säule# enthält"}
        },  //clear
            Text{"the #Termina Field pillar grotto# contains", "le #trou du pilier de la plaine Termina# contient", "la gruta sobre el pilar en el Campo de Términa contiene", "die #Erdhöhle auf der Säule in den Ebenen von Termina# enthält"}
    );
    hintTable[TERMINA_FIELD_GRASS_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #grassy cave# contains", "une #grotte sous des herbes# contient", "una cueva herbosa contiene", "eine #graßige Höhle# enthält"}
        },  //clear
            Text{"the #Termina Field grass grotto# contains", "le #trou dans l'herbe de la plaine Termina# contient", "la gruta en la hierba alta en el Campo de Términa contiene", "die #Erdhöhle im Gras in den Ebenen von Termina# enthält"}
    );
    hintTable[TERMINA_FIELD_UNDERWATER_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #sunken chest# contains", "un #coffre inondé des plaines# contient", "un cofre hundido contiene", "eine #versunkene Truhe# enthält"}
        },  //clear
            Text{"the #Termina Field chest in water# contains", "le #coffre submergé de la plaine Termina# contient", "el cofre bajo el agua en el Campo de Términa contiene", "die #Unterwassertruhe in den Ebenen von Termina# enthält"}
    );
    hintTable[TERMINA_FIELD_GRASS_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #grassy chest# contains", "un #coffre herbeux# contient", "un cofre herboso contiene", "eine #graßige Truhe# enthält"}
        },  //clear
            Text{"the #Termina Field chest in grass# contains", "le #coffre dans l'herbe de la plaine Termina# contient", "el cofre entre la hierba alta en el Campo de Términa contiene", "die #Truhe im Gras in den Ebenen von Termina# enthält"}
    );
    hintTable[TERMINA_FIELD_STUMP_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #tree chest# contains", "un #coffre-sur-souche# contient", "un cofre en el árbol contiene", "eine #Baumtruhe# enthält"}
        },  //clear
            Text{"the #Termina Field stump chest# contains", "le #coffre sur la souche de la plaine Termina# contient", "el cofre sobre el tocón en el Campo de Términa contiene", "die #Truhe auf dem Baumstumpf in den Ebenen von Termina# enthält"}
    );
    hintTable[TERMINA_FIELD_GROTTO_COW1] = HintText::Sometimes({
            //obscure
            Text{"a #lost creature# gives", "un #bovin des plaines# prodigue", "una criatura perdida da", "ein #verirrtes Wesen# enthält"}
        },  //clear
            Text{"the #cows beneath Termina Field# have", "les #vaches cachées sous la plaine Termina# ont", "las vacas bajo el Campo de Términa tienen", "die #Kühe unter den Ebenen von Termina# haben"}
    );
    hintTable[TERMINA_FIELD_GROTTO_COW2] = HintText::Sometimes({
            //obscure
            Text{"a #lost creature# gives", "un #bovin des plaines# prodigue", "una criatura perdida da", "ein #verirrtes Wesen# enthält"}
        },  //clear
            Text{"the #cows beneath Termina Field# have", "les #vaches cachées sous la plaine Termina# ont", "las vacas bajo el Campo de Términa tienen", "die #Kühe unter den Ebenen von Termina# haben"}
    );
//Twin Islands
    hintTable[HOT_SPRING_WATER_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #steamy grotto# contains", "un #sauna naturel# contient", "una gruta tórrida contiene", "eine #dampfende Höhle# enthält"}
        },  //clear
            Text{"the #hot spring water grotto near Goron Racetrack# has", "le #trou à source chaude de la route du village goron# contient", "la gruta de aguas termales cerca de la Aldea Goron tiene", "die #Erdhöhle mit heißem Quellwasser nahe der Goronen-Rennstrecke# hat"}
    );
    hintTable[TWIN_ISLANDS_GORON_RACE] = HintText::Sometimes({
            //obscure
            Text{"a #sporting event# rewards", "une #compétition épineuse# offre", "un evento deportivo recompensa con", "eine #sportliche Aktivität# entlohnt"}
        },  //clear
            Text{"the #Goron Racetrack's reward# is", "le #prix de la course des Gorons# est", "la recompensa de la carrera Goron es", "die Belohnung auf der #Goronen-Rennstrecke# ist"}
    );
    hintTable[TWIN_ISLANDS_GORON_RACETRACK_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #hidden cave# contains", "la #grotte du conifère solitaire# contient", "una cueva oculta contiene", "eine #versteckte Höhle# enthält"}
        },  //clear
            Text{"the #grotto near Goron Racetrack# contains", "le #trou près de la course des Gorons# contient", "la gruta cerca del Circuito de Carreras Goron contiene", "die #Erdhöhle nahe der Goronen-Rennstrecke# enthält"}
    );
    hintTable[TWIN_ISLANDS_UNDERWATER_RAMP_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #spring treasure# contains", "un #trésor printanier immergé# contient", "un tesoro de primavera contiene", "eine #Frühlingstruhe# enthält"}
        },  //clear
            Text{"a #submerged chest near Goron Racetrack# contains", "un #coffre submergé sur la route du village goron# contient", "un cofre hundido cerca del Circuito de Carreras Goron contiene", "eine #Unterwassertruhe nahe der Goronen-Rennstrecke# enthält"}
    );
    hintTable[TWIN_ISLANDS_CAVE_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #sunken springtime treasure# contains", "un #trésor printanier immergé# contient", "un tesoro de primavera hundido contiene", "eine #versunkene Truhe im Frühling# enthält"}
        },  //clear
            Text{"a #submerged chest near Goron Racetrack# contains", "un #coffre submergé sur la route du village goron# contient", "un cofre hundido cerca del Circuito de Carreras Goron contiene", "eine #Unterwassertruhe nahe der Goronen-Rennstrecke# enthält"}
    );
    hintTable[TWIN_ISLANDS_LULLABY_INTRO] = HintText::Sometimes({
            //obscure
            Text{"a #goron elder# teaches", "un #ancien aux doigts froids# enseigne", "un anciano goron enseña", "ein #Goronenältester# lehrt"}
        },  //clear
            Text{"the #Goron Elder# has", "l'#Ancêtre goron# a", "el Goron Anciano tiene", "der #Goronen-Älteste# hat"}
    );
    hintTable[TINGLE_TWIN_ISLANDS_SH] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende", "ein #Kartenzeichner# verkauft"}
        },  //clear
            Text{"#Tingle sells in the mountains#", "dans les #montagnes, Tingle# vend", "Tingle en las montañas vende", "#Tingle verkauft in den Bergen#"}
    );
    hintTable[TINGLE_TWIN_ISLANDS_RR] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende", "ein #Kartenzeichner# verkauft"}
        },  //clear
            Text{"#Tingle sells in the mountains#", "dans les #montagnes, Tingle# vend", "Tingle en las montañas vende", "#Tingle verkauft in den Bergen#"}
    );
    hintTable[TINGLE_TWIN_ISLANDS_SH_SPRING] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende", "ein #Kartenzeichner# verkauft"}
        },  //clear
            Text{"#Tingle sells in the mountains#", "dans les #montagnes, Tingle# vend", "Tingle en las montañas vende", "#Tingle verkauft in den Bergen#"}
    );
    hintTable[TINGLE_TWIN_ISLANDS_RR_SPRING] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende", "ein #Kartenzeichner# verkauft"}
        },  //clear
            Text{"#Tingle sells in the mountains#", "dans les #montagnes, Tingle# vend", "Tingle en las montañas vende", "#Tingle verkauft in den Bergen#"}
    );
//W Clock Town
    hintTable[W_CLOCK_TOWN_BOMB_BAG_BUY] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "l'#artificier citadin# est contraint à vendre", "un mercader de la ciudad vende", "ein #Stadthändler# verkauft"}
        },  //clear
            Text{"the #Bomb Shop# sells", "sans leur livraison, #la boutique de bombes# vend", "la Tienda de Bombas vende", "der #Bombenladen# verkauft"}
    );
    hintTable[W_CLOCK_TOWN_BIG_BOMB_BAG_BUY] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "l'#artificier citadin# compte vendre", "un mercader de la ciudad vende", "ein #Stadthändler# verkauft"}
        },  //clear
            Text{"Sakon tries to #steal from the old lady#", "la #marchandise que Sakon tente de voler# à la vielle femme est", "lo que Sakon quiere robar de la anciana es", "die #Lieferung der alten Frau für den Bombenladen# ist"}
    );
    hintTable[W_CLOCK_TOWN_POSTMANS_GAME] = HintText::Sometimes({
            //obscure
            Text{"a #delivery person# rewards", "un #livreur concentré# offre", "un repartidor recompensa con", "eine #liefernde Person# entlohnt"}
        },  //clear
            Text{"#counting to 10 seconds# with the postman gives", "#compter pile 10 secondes# avec le facteur donne", "contar 10 segundos con el cartero da", "das #Zählen bis 10 Sekunden# beim Postboten bringt"}
    );
    hintTable[W_CLOCK_TOWN_ROSA_SISTERS] = HintText::Sometimes({
            //obscure
            Text{"#traveling sisters# reward", "#prendre des disciples# octroie", "las hermanas viajeras recompensan con", "#reisende Schwestern# entlohnen"}
        },  //clear
            Text{"the #Rosa Sisters# have", "les #sœurs Rosa# ont", "las hermanas Rosa tienen", "die #Rosa-Schwestern# haben"}
    );
    hintTable[W_CLOCK_TOWN_SWORDSMANS_SCHOOL] = HintText::Sometimes({
            //obscure
            Text{"a #town game# rewards", "les #fines lames# reçoivent", "un juego en la ciudad recompensa con", "ein #Schwertspiel# entlohnt"}
        },  //clear
            Text{"the #Swordsman's School's reward# is", "le #maître d'armes de Cadranbourg# a", "la recompensa de la Escuela de Esgrima es", "die Belohnung in der #Schwertkampfschule# ist", "", "le #maître d'armes de Bourg-Clocher# a", ""}
    );
    hintTable[W_CLOCK_TOWN_ALL_NIGHT_MASK_BUY] = HintText::Sometimes({
            //obscure
            Text{"a #shady town merchant# sells", "un #commerce suspect# vend", "un mercader sospechoso en la ciudad vende", "ein #zwielichtiger Stadthändler# verkauft"}
        },  //clear
            Text{"the #Curiosity Shop's most expensive item# is", "l'#article le plus onéreux du bazar# est", "el artículo más caro de la Tienda de Curiosidades es", "der teuerste Gegenstand im #Kuriositätenladen# ist"}
    );
    hintTable[W_CLOCK_TOWN_BOMB_SHOP_GORON] = HintText::Sometimes({
            //obscure
            Text{"a #town goron merchant# sells", "les #gorons accrédités# peuvent acheter", "un mercader goron en la ciudad vende", "ein #Stadt-Gorone# verkauft"}
        },  //clear
            Text{"the #Goron in the Bomb Shop# sells", "le #goron de la boutique de bombes# vend", "el Goron en la Tienda de Bombas vende", "der #Gorone im Bombenladen# verkauft"}
    );
    hintTable[W_CLOCK_TOWN_CURIOSITY_BOMB_BAG] = HintText::Sometimes({
            //obscure
            Text{"a #shady town merchant# sells", "un #commerce suspect# peut recevoir", "un mercader sospechoso en la ciudad vende", "ein #zwielichtiger Stadthändler# verkauft"}
        },  //clear
            Text{"the Curiosity Shop's #stolen Bomb Shop goods# are", "la #marchandise volée atterrie au bazar# est", "", "die #gestohlene Ware aus dem Bombenladen# im Kuriositätenladen ist"}
    );
    //hintTable[W_CLOCK_TOWN_LOTTERY] = HintText::Sometimes({
    //        //obscure
    //        Text{"a #town lucky numbers# game", "un #numéro gagnant# octroie", "un juego de números de suerte en la ciudad recompensa con", "ein #Glücksnummernspiel# entlohnt"}
    //    },  //clear
    //        Text{"the #lottery's prize# is", "le #prix de la loterie# est", "el premio de la lotería es", "der #Gewinn bei der Lotterie# ist"}
    //);
    hintTable[TRADING_POST_ITEM_1] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende", "ein #Stadthändler# verkauft"}
        },  //clear
            Text{"the #Trading Post# sells", "#Troc en Trop# vend", "el Lugar de Intercambio vende", "der #Basar# verkauft"}
    );
    hintTable[TRADING_POST_ITEM_2] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende", "ein #Stadthändler# verkauft"}
        },  //clear
            Text{"the #Trading Post# sells", "#Troc en Trop# vend", "el Lugar de Intercambio vende", "der #Basar# verkauft"}
    );
    hintTable[TRADING_POST_ITEM_3] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende", "ein #Stadthändler# verkauft"}
        },  //clear
            Text{"the #Trading Post# sells", "#Troc en Trop# vend", "el Lugar de Intercambio vende", "der #Basar# verkauft"}
    );
    hintTable[TRADING_POST_ITEM_4] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende", "ein #Stadthändler# verkauft"}
        },  //clear
            Text{"the #Trading Post# sells", "#Troc en Trop# vend", "el Lugar de Intercambio vende", "der #Basar# verkauft"}
    );
    hintTable[TRADING_POST_ITEM_5] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende", "ein #Stadthändler# verkauft"}
        },  //clear
            Text{"the #Trading Post# sells", "#Troc en Trop# vend", "el Lugar de Intercambio vende", "der #Basar# verkauft"}
    );
    hintTable[TRADING_POST_ITEM_6] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende", "ein #Stadthändler# verkauft"}
        },  //clear
            Text{"the #Trading Post# sells", "#Troc en Trop# vend", "el Lugar de Intercambio vende", "der #Basar# verkauft"}
    );
    hintTable[TRADING_POST_ITEM_7] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende", "ein #Stadthändler# verkauft"}
        },  //clear
            Text{"the #Trading Post# sells", "#Troc en Trop# vend", "el Lugar de Intercambio vende", "der #Basar# verkauft"}
    );
    hintTable[TRADING_POST_ITEM_8] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende", "ein #Stadthändler# verkauft"}
        },  //clear
            Text{"the #Trading Post# sells", "#Troc en Trop# vend", "el Lugar de Intercambio vende", "der #Basar# verkauft"}
    );
    hintTable[BOMB_SHOP_ITEM_1] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "l'#artificier citadin# vend", "un mercader en la ciudad vende", "ein #Stadthändler# verkauft"}
        },  //clear
            Text{"the #Bomb Shop# sells", "la #boutique de bombes# vend", "la Tienda de Bombas vende", "der #Bombenladen# verkauft"}
    );
    hintTable[BOMB_SHOP_ITEM_2] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "l'#artificier citadin# vend", "un mercader en la ciudad vende", "ein #Stadthändler# verkauft"}
        },  //clear
            Text{"the #Bomb Shop# sells", "la #boutique de bombes# vend", "la Tienda de Bombas vende", "der #Bombenladen# verkauft"}
    );
    //hintTable[BOMB_SHOP_ITEM_3] = HintText::Sometimes({
    //        //obscure
    //        Text{"a #town merchant# sells", "l'#artificier citadin# vend", "un mercader en la ciudad vende", "ein #Stadthändler# verkauft"}
    //    },  //clear
    //        Text{"the #Bomb Shop# sells", "la #boutique de bombes# vend", "la Tienda de Bombas vende", "der #Bombenladen# verkauft"}
    //);
//Woodfall
    hintTable[WOODFALL_BRIDGE_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #swamp chest# contains", "un #coffre gardé par une peste# contient", "un cofre en el pantano contiene", "eine #Sumpftruhe# enthält"}
        },  //clear
            Text{"the #chest at the end of the Woodfall pier# contains", "le #coffre au bout la jetée de Boisé-les-Cascades# contient", "el cofre al final del Bosque Catarata contiene", "die #Truhe am Ende des Stegs im Dämmerwald# enthält", "", "le #coffre au bout la jetée de Bois-Cascade# contient", ""}
    );
    hintTable[WOODFALL_BEHIND_OWL_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #swamp chest# contains", "un #coffre qui surveille un hibou# contient", "un cofre en el pantano contiene", "eine #Sumpftruhe# enthält"}
        },  //clear
            Text{"the #chest behind the Woodfall Owl Statue# contains", "le #coffre derrière la statue de hibou à Boisé-les-Cascades# contient", "el cofre detrás de la estatua del búho en el Bosque Catarata contiene", "die #Truhe hinter der Eulenstatue im Dämmerwald# enthält", "", "le #coffre derrière la statue de hibou à Bois-Cascade# contient", ""}
    );
    hintTable[ENTRANCE_TO_WOODFALL_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #swamp chest# contains", "un #coffre au ras du poison# contient", "un cofre en el pantano contiene", "eine #Sumpftruhe# enthält"}
        },  //clear
            Text{"the #chest near the entrance to Woodfall# contains", "le #coffre près de l'entrée de Boisé-les-Cascades# contient", "el cofre cerca de la entrada del Bosque Catarata contiene", "die #Truhe nahe dem Eingang zum Dämmerwald# enthält", "", "le #coffre près de l'entrée de Bois-Cascade# contient", ""}
    );
    hintTable[WOODFALL_GREAT_FAIRY] = HintText::Sometimes({
            //obscure
            Text{"the #fairy of wisdom# rewards", "la #fée de la sagesse# prodigue", "la hada de la sabiduría recompensa con", "die #weise Fee# entlohnt"}
        },  //clear
            Text{"the #Woodfall Great Fairy# has", "la #grande fée de Boisé-les-Cascades# a", "la gran hada del Bosque Catarata tiene", "die #Große Fee im Dämmerwald# hat", "", "la #grande fée de Bois-Cascade# a", ""}
    );
//Zora Cape
    hintTable[ZORA_CAPE_GREAT_FAIRY] = HintText::Sometimes({
            //obscure
            Text{"the #fairy of courage# rewards", "la #fée du courage# prodigue", "la hada del valor recompensa con", "die #mutige Fee# enthält"}
        },  //clear
            Text{"the #Zora Cape Great Fairy# has", "la #grande fée du cap des Zoras# a", "la gran hada de la Gran Bahía tiene", "die #Große Fee am Kap Zora# hat"}
    );
    hintTable[ZORA_CAPE_BEAVER_RACE_1] = HintText::Sometimes({
            //obscure
            Text{"a #river dweller# rewards", "de #gros rongeurs mouillés# détiennent", "un morador del río recompensa con", "ein #Flussbewohner# entlohnt"}
        },  //clear
            Text{"the #beavers# have", "les #castors# ont", "la primer recompensa de los castores es", "die #Biber-Brüder# haben"}
    );
    hintTable[ZORA_CAPE_BEAVER_RACE_2] = HintText::Sometimes({
            //obscure
            Text{"a #river dweller# rewards", "de #gros rongeurs mouillés# détiennent", "un morador del río recompensa con", "ein #Flussbewohner# entlohnt"}
        },  //clear
            Text{"the #beavers# have", "les #castors# ont", "la segunda recompensa de los castores es", "die #Biber-Brüder# haben"}
    );
    hintTable[ZORA_CAPE_LIKE_LIKE] = HintText::Sometimes({
            //obscure
            Text{"a #shield eater# contains", "un #mange-écu# contient", "un devorador de escudos resguarda", "ein #Schildfresser# enthält"}
        },  //clear
            Text{"a #Zora Cape Like Like# has", "un #like like du cap des Zoras# a", "el Like Like en el Cabo Zora resguarda", "ein #Raubschleim am Kap Zora# hat"}
    );
    hintTable[ZORA_CAPE_LEDGE_NO_TREE] = HintText::Sometimes({
            //obscure
            Text{"a #high place# contains", "#escalader une rivière# dévoile", "un lugar en lo alto contiene", "ein #hochgelegener Ort# enthält"}
        },  //clear
            Text{"a #high chest in Zora Cape# has", "un #coffre perché du cap des Zoras# contient", "un cofre en lo alto del Cabo Zora contiene", "eine #hoch gelegene Truhe am Kap Zora# enthält"}
    );
    hintTable[ZORA_CAPE_LEDGE_WITH_TREE] = HintText::Sometimes({
            //obscure
            Text{"a #high place# contains", "#escalader une rivière# dévoile", "un lugar en lo alto contiene", "ein #hochgelegener Ort# enthält"}
        },  //clear
            Text{"a #high chest in Zora Cape# has", "un #coffre perché du cap des Zoras# contient", "un cofre en lo alto del Cabo Zora contiene", "eine #hoch gelegene Truhe am Kap Zora# enthält"}
    );
    hintTable[ZORA_CAPE_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #beach cave# contains", "une #grotte de pêcheur# contient", "una cueva en la playa contiene", "eine #Strandhöhle# enthält"}
        },  //clear
            Text{"the #Zora Cape grotto# contains", "le #trou bouché du cap des Zoras# contient", "la gruta en el Cabo Zora contiene", "die #Erdhöhle am Kap Zora# enthält"}
    );
    hintTable[ZORA_CAPE_UNDERWATER_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #sunken chest# contains", "un #coffre côtier submergé# contient", "un cofre hundido contiene", "eine #versunkene Höhle# enthält"}
        },  //clear
            Text{"the #submerged chest in Zora Cape# contains", "le #coffre submergé du cap des Zoras# contient", "el cofre hundido en el Cabo Zora contiene", "die #Unterwassertruhe am Kap Zora# enthält"}
    );
//Zora Hall
    hintTable[ZORA_HALL_SCRUB_TRADE] = HintText::Sometimes({
            //obscure
            Text{"a #western merchant# trades", "un #marchant occidental# échange", "un mercader del oeste intercambia por", "ein #westlicher Händler# tauscht"}
        },  //clear
            Text{"Business Scrubs #trade for the Mountain Title Deed#", "une peste marchande #échange un titre de montagne# contre", "el Mercader Deku intercambia la propiedad de la montaña por", "Deku-Händler #tauschen gegen die Berg-Urkunde#"}
    );
    hintTable[ZORA_HALL_EVAN] = HintText::Sometimes({
            //obscure
            Text{"a #musician# rewards", "#se faire voler une chanson# octroie", "un músico recompensa con", "ein #Musiker# entlohnt"}
        },  //clear
            Text{"#Evan, the Zora pianist#, has", "le #pianiste Zora, Evan#, a", "Evan, el pianista Zora, tiene", "#Evan, der Zora-Pianist#, hat"}
    );
    hintTable[ZORA_HALL_LULU_ROOM_LEDGE] = HintText::Sometimes({
            //obscure
            Text{"the #singer's room# contains", "la #chambre d'une chanteuse# contient", "el cuarto de la cantante contiene", "das #Zimmer der Singerin# enthält"}
        },  //clear
            Text{"the #Zora Hall Deku Flower# leads to", "la #fleur mojo de la chambre de Lulu# mène à", "la Flor Deku en el Salón Zora lleva hacia", "die #Deku-Blume in der Halle der Zoras# führt zu"}
    );
    hintTable[ZORA_HALL_SCRUB_PURCHASE] = HintText::Sometimes({
            //obscure
            Text{"a #western merchant# sells", "un #marchant occidental# vend", "un mercader del oeste vende", "ein #westlicher Händler# verkauft"}
        },  //clear
            Text{"the #Zora Hall Business Scrub# sells", "la #peste mojo du théâtre des Zoras# vend", "el Mercader Deku en el Salón Zora vende", "der #Deku-Händler in der Halle der Zoras# verkauft"}
    );
    //hintTable[ZORA_HALL_STAGE_LIGHTS] = HintText::Sometimes({
    //        //obscure
    //        Text{"a #tech crew# gives", "aider l'#équipe technique# octroie", "un fan", "ein #Ton-Techniker#"}
    //    },  //clear
    //        Text{"#lighting the Zora Hall torches# lead to", "#allumer les torches du théâtre des Zoras# octroie", "encender las antorchas en el Salón Zora guía da", "das #Entzünden der Fackeln in der Halle der Zoras# führt zu"}
    //);
    //hintTable[ZORA_HALL_BAD_PHOTO_LULU] = HintText::Sometimes({
    //        //obscure
    //        Text{"a #fan# gives", "un #fan insatisfait# offre", "un fan", "ein #Fan#"}
    //    },  //clear
    //        Text{"the #Lulu fan's reward for a mediocre picture# is", "le #mégafan de Lulu échange une photo médiocre# contre", "la recompensa del fan de Lulú por una mala luminografía es", "die #Belohnung des Lulu-Fans für ein mittelmäßiges Bild# ist"}
    //);
    //hintTable[ZORA_HALL_GOOD_PHOTO_LULU] = HintText::Sometimes({
    //        //obscure
    //        Text{"a #fan# gives", "un #fan satisfait# offre", "un fan", "ein #Fan#"}
    //    },  //clear
    //        Text{"the #Lulu fan's reward for a good picture# is", "le #mégafan de Lulu échange une bonne photo# contre", "la recompensa del fan de Lulú por una buena luminografía es", "die #Belohnung des Lulu-Fans für einen gelungenen Schnappschuss# ist"}
    //);
    hintTable[ZORA_SHOP_ITEM_1] = HintText::Sometimes({
            //obscure
            Text{"a #zora merchant# sells", "une #boutique iodée# vend", "un mercader zora vende", "ein #Zora-Händler# verkauft"}
        },  //clear
            Text{"the #Zora Shop# sells", "la #boutique Zora# vend", "la Tienda Zora vende", "der #Zora-Laden# verkauft"}
    );
    hintTable[ZORA_SHOP_ITEM_2] = HintText::Sometimes({
            //obscure
            Text{"a #zora merchant# sells", "une #boutique iodée# vend", "un mercader zora vende", "ein #Zora-Händler# verkauft"}
        },  //clear
            Text{"the #Zora Shop# sells", "la #boutique Zora# vend", "la Tienda Zora vende", "der #Zora-Laden# verkauft"}
    );
    hintTable[ZORA_SHOP_ITEM_3] = HintText::Sometimes({
            //obscure
            Text{"a #zora merchant# sells", "une #boutique iodée# vend", "un mercader zora vende", "ein #Zora-Händler# verkauft"}
        },  //clear
            Text{"the #Zora Shop# sells", "la #boutique Zora# vend", "la Tienda Zora vende", "der #Zora-Laden# verkauft"}
    );

    /*-------------------------
    |  DUNGEON LOCATION TEXT  |
    -------------------------*/
    hintTable[WOODFALL_TEMPLE_HEROS_BOW_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #sleeping temple# contains", "le #temple endormi# contient", "el templo durmiente contiene", "ein #schlafender Tempel# enthält"}
        },  //clear
            Text{"the #Woodfall Temple Dinolfos# protects", "le #dinolfos du temple de Boisé-les-Cascades# protège", "El Dinolfos en el Templo del Bosque Catarata resguarda", "der #Dinolfos im Dämmerwald-Tempel# bewacht", "", "le #dinolfos du temple de Bois-Cascade# protège", ""}
    );
    hintTable[WOODFALL_TEMPLE_MAP_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #sleeping temple# contains", "le #temple endormi# contient", "el templo durmiente contiene", "ein #schlafender Tempel# enthält"}
        },  //clear
            Text{"the #Woodfall Temple Snappers# protect", "les #tortueurs du temple de Boisé-les-Cascades# protègent", "los Snappers en el Templo del Bosque Catarata resguardan", "die #Schnapper im Dämmerwald-Tempel# bewachen", "", "les #tor-tueurs du temple de Bois-Cascade# protègent", ""}
    );
    hintTable[WOODFALL_TEMPLE_COMPASS_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #sleeping temple# contains", "le #temple endormi# contient", "el templo durmiente contiene", "ein #schlafender Tempel# enthält"}
        },  //clear
            Text{"the #Woodfall Temple Dragonflies# protect", "les #draco-lules du temple de Boisé-les-Cascades# protègent", "las Libélulas en el Templo del Bosque Catarata resguardan", "die #Drachen-Libellen im Dämmerwald-Tempel# bewachen", "", "les #draco-lules du temple de Bois-Cascade# protègent", ""}
    );
    hintTable[WOODFALL_TEMPLE_BOSS_KEY_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #sleeping temple# contains", "le #temple endormi# contient", "el templo durmiente contiene", "ein #schlafender Tempel# enthält"}
        },  //clear
            Text{"the #Woodfall Temple Gekko# protects", "le #gekko du temple de Boisé-les-Cascades# protège", "el Gekko en el Templo del Bosque Catarata resguarda", "der #Gekko im Dämmerwald-Tempel# bewacht", "", "le #gekko du temple de Bois-Cascade# protège", ""}
    );
    hintTable[WOODFALL_TEMPLE_SMALL_KEY_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #sleeping temple# contains", "le #temple endormi# contient", "el templo durmiente contiene", "ein #schlafender Tempel# enthält"}
        },  //clear
            Text{"the #Woodfall Temple chest near the elevator# contains", "le #coffre près de l'ascenseur du temple de Boisé-les-Cascades# contient", "el cofre cerca del elevador en el Templo del Bosque Catarata contiene", "die #Truhe nahe dem Aufzug im Dämmerwald-Tempel# enthält", "", "le #coffre près de l'ascenseur du temple de Bois-Cascade# contient", ""}
    );
    hintTable[WOODFALL_TEMPLE_DEKU_PRINCESS] = HintText::Exclude({
            //obscure
            Text{"the #sleeping temple# rewards", "le #temple endormi# détient", "el templo durmiente contiene", "ein #schlafender Tempel# entlohnt"}
        },  //clear
            Text{"#bottling the Deku Princess# makes", "embouteiller la #princesse mojo# créée", "embotellar a la Princesa Deku da", "das #Einfangen der Deku-Prinzessin in eine Flasche# bewirkt"}
    );
    hintTable[WF_SF_ENTRANCE_FAIRY] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #item hovering near the Woodfall Temple entrance# is", "l'#objet volant près de l'entrée du temple de Boisé-les-Cascades# est", "el objeto flotando cerca de la entrada del Templo del Bosque Catarata es", "der #schwebende Gegenstand am Eingang des Dämmerwald-Tempels# ist", "", "l'#objet volant près de l'entrée du temple de Bois-Cascade# est", ""}
    );
    hintTable[WF_SF_ENTRANCE_PLATFORM] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Woodfall Temple chest near the entrance# contains", "le #coffre près de l'entrée du temple de Boisé-les-Cascades# contient", "el cofre cerca del cuarto principal del Templo del Bosque Catarata contiene", "die #Truhe nahe dem Eingang des Dämmerwald-Tempels# enthält", "", "le #coffre près de l'entrée du temple de Bois-Cascade# contient", ""}
    );
    hintTable[WF_SF_MAIN_ROOM_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Woodfall Temple chest in the main room# contains", "le #coffre dans la pièce centrale du temple de Boisé-les-Cascades# contient", "el cofre en el cuarto principal del Templo del Bosque Catarata contiene", "die #Truhe im Hauptraum des Dämmerwald-Tempels# enthält", "", "le #coffre dans la pièce centrale du temple de Bois-Cascade# contient", ""}
    );
    hintTable[WF_SF_MAIN_ROOM_SWITCH] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Woodfall Temple bubble in the main room# contains", "la #bulle dans la pièce centrale du temple de Boisé-les-Cascades# contient", "la burbuja en el cuarto principal del Templo del Bosque Catarata contiene", "die #Blase im Hauptraum des Dämmerwald-Tempels# enthält", "", "la #bulle dans la pièce centrale du temple de Bois-Cascade# contient", ""}
    );
    hintTable[WF_SF_PRE_BOSS_LOWER_RIGHT_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Woodfall Temple bubble near the boss door# contains", "une #bulle près de l'antre du boss du temple de Boisé-les-Cascades# contient", "la burbuja cercana a la guarida del jefe del Templo del Bosque Catarata contiene", "eine #Blase nahe der Boss-Tür im Dämmerwald-Tempel# enthält", "", "une #bulle près de l'antre du boss du temple de Bois-Cascade# contient", ""}
    );
    hintTable[WF_SF_PRE_BOSS_UPPER_RIGHT_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Woodfall Temple bubble near the boss door# contains", "une #bulle près de l'antre du boss du temple de Boisé-les-Cascades# contient", "la burbuja cercana a la guarida del jefe del Templo del Bosque Catarata contiene", "eine #Blase nahe der Boss-Tür im Dämmerwald-Tempel# enthält", "", "une #bulle près de l'antre du boss du temple de Bois-Cascade# contient", ""}
    );
    hintTable[WF_SF_PRE_BOSS_UPPER_LEFT_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Woodfall Temple bubble near the boss door# contains", "une #bulle près de l'antre du boss du temple de Boisé-les-Cascades# contient", "la burbuja cercana a la guarida del jefe del Templo del Bosque Catarata contiene", "eine #Blase nahe der Boss-Tür im Dämmerwald-Tempel# enthält", "", "une #bulle près de l'antre du boss du temple de Bois-Cascade# contient", ""}
    );
    hintTable[WF_SF_PRE_BOSS_PILLAR_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Woodfall Temple bubble on a flaming pillar# contains", "une #bulle sur un pilier embrasé du temple de Boisé-les-Cascades# contient", "la burbuja sobre el pilar en llamas del Templo del Bosque Catarata contiene", "eine #Blase auf einer brennenden Säule im Dämmerwald-Tempel# enthält", "", "une #bulle sur un pilier embrasé du temple de Bois-Cascade# contient", ""}
    );
    hintTable[WF_SF_DEKU_BABA] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Woodfall Temple Deku Baba# has", "une #baba mojo du temple de Boisé-les-Cascades# a", "la Baba Deku en el Templo del Bosque Catarata tiene", "ein #Dekuranha im Dämmerwald-Tempel# hat", "", "une #baba mojo du temple de Bois-Cascade# a", ""}
    );
    hintTable[WF_SF_DRAGONFLY_ROOM_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Woodfall Temple bubble on the second floor# contains", "la #bulle au deuxième étage du temple de Boisé-les-Cascades# contient", "la burbuja en el segundo piso del Templo del Bosque Catarata contiene", "die #Blase im ersten Stock des Dämmerwald-Tempels# enthält", "", "la #bulle au deuxième étage du temple de Bois-Cascade# contient", ""}
    );
    hintTable[WF_SF_SKULLTULA] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Woodfall Temple Skulltula# has", "une #skulltula du temple de Boisé-les-Cascades# a", "la Skulltula en el Templo del Bosque Catarata tiene", "eine #Skulltula im Dämmerwald-Tempel# hat", "", "une #skulltula du temple de Bois-Cascade# a", ""}
    );
    hintTable[WF_SF_DARK_ROOM] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Woodfall Temple chest in the dark room# contains", "le #coffre dans la pièce sombre du temple de Boisé-les-Cascades# contient", "el cofre en el cuarto oscuro del Templo del Bosque Catarata contiene", "die #Truhe im dunklen Raum des Dämmerwald-Tempels# enthält", "", "le #coffre dans la pièce sombre du temple de Bois-Cascade# contient", ""}
    );
    hintTable[WF_SF_JAR_FAIRY] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Woodfall Temple jar# contains", "une #jarre du temple de Boisé-les-Cascades# contient", "el jarrón en el Templo del Bosque Catarata contiene", "ein #Krug im Dämmerwald-Tempel# enthält", "", "une #jarre du temple de Bois-Cascade# contient", ""}
    );
    hintTable[WF_SF_BRIDGE_ROOM_BEEHIVE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Woodfall Temple beehive under a platform# contains", "la #ruche sous une plateforme du temple de Boisé-les-Cascades# contient", "el panal bajo las plataformas del Templo del Bosque Catarata contiene", "das #Bienennest unter einer Plattform im Dämmerwald-Tempel# enthält", "", "la #ruche sous une plateforme du temple de Bois-Cascade# contient", ""}
    );
    hintTable[WF_SF_PLATFORM_ROOM_BEEHIVE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Woodfall Temple beehive above a door# contains", "la #ruche près d'une porte du temple de Boisé-les-Cascades# contient", "el panal encima de la puerta del Templo del Bosque Catarata contiene", "das #Bienennest über einer Tür im Dämmerwald-Tempel# enthält", "", "la #ruche près d'une porte du temple de Bois-Cascade# contient", ""}
    );
    hintTable[ODOLWA_HEART_CONTAINER] = HintText::Exclude({
            //obscure
            Text{"a #masked evil# contains", "occire le #guerrier de la jungle# octroie", "un mal enmascarado contiene", "ein #maskiertes Böses# enthält"}
        },  //clear
            Text{"#Odolwa# has", "#Odolwa# a", "Odolwa tiene", "#Odolwa# hat"}
    );
    hintTable[GIANTS_OATH_TO_ORDER] = HintText::Exclude({
            //obscure
            Text{"a #gentile giant# teaches", "un #gentil géant# enseigne", "", "ein #sanfter Gigant# lehrt"}
        },  //clear
            Text{"the #Giants' song# is", "le #chant des Géants# est", "", "der #Gesang des Himmels# ist"}
    );
//Snowhead Temple
    hintTable[SNOWHEAD_TEMPLE_FIRE_ARROW_CHEST] = HintText::Exclude({
            //obscure
            Text{"an #icy temple# contains", "un #temple enneigé# contient", "un templo helado contiene", "ein #eisiger Tempel# enthält"}
        },  //clear
            Text{"the #Snowhead Temple 2F Wizzrobe# protects", "le #sorcier au 2ème du temple du Pic des neiges# protège", "el Wizzrobe en el 2do. piso del Templo del Pico Nevado resguarda", "der #Zaurob im 1. OG des Pic-Hibernia-Tempels# bewacht", "", "le #sorcier au 2ème du temple du pic des Neiges# protège", ""}
    );
    hintTable[SNOWHEAD_TEMPLE_MAP_CHEST] = HintText::Exclude({
            //obscure
            Text{"an #icy temple# contains", "un #temple enneigé# contient", "un templo helado contiene", "ein #eisiger Tempel# enthält"}
        },  //clear
            Text{"the #Snowhead Temple chest next to the elevator# contains", "le #coffre près de l'ascenseur du temple du Pic des neiges# contient", "el cofre al lado del elevador del Templo del Pico Nevado contiene", "die #Truhe neben dem Aufzug im Pic-Hibernia-Tempel# enthält", "", "le #coffre près de l'ascenseur du temple du pic des Neiges# contient", ""}
    );
    hintTable[SNOWHEAD_TEMPLE_COMPASS_CHEST] = HintText::Exclude({
            //obscure
            Text{"an #icy temple# contains", "un #temple enneigé# contient", "un templo helado contiene", "ein #eisiger Tempel# enthält"}
        },  //clear
            Text{"the #Snowhead Temple chest near White Wolfos# contains", "le #coffre près des loufos blancs du temple du Pic des neiges# contient", "el cofre cerca del Wolfos del Templo del Pico Nevado contiene", "die #Truhe nahe den Weißen Wolfos im Pic-Hibernia-Tempel# enthält", "", "le #coffre près des wolfos blancs du temple du pic des Neiges# contient", ""}
    );
    hintTable[SNOWHEAD_TEMPLE_BOSS_KEY_CHEST] = HintText::Exclude({
            //obscure
            Text{"an #icy temple# contains", "un #temple enneigé# contient", "un templo helado contiene", "ein #eisiger Tempel# enthält"}
        },  //clear
            Text{"the #Snowhead Temple 4F Wizzrobe# protects", "le #sorcier au 4ème du temple du Pic des neiges# protège", "el Wizzrobe en el 4to. piso del Templo del Pico Nevado resguarda", "der #Zaurob im 3. OG des Pic-Hibernia-Tempels# bewacht", "", "le #sorcier au 4ème du temple du pic des Neiges# protège", ""}
    );
    hintTable[SNOWHEAD_TEMPLE_BLOCK_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"an #icy temple# contains", "un #temple enneigé# contient", "un templo helado contiene", "ein #eisiger Tempel# enthält"}
        },  //clear
            Text{"the #Snowhead Temple chest behind two blocks# contains", "le #coffre derrière le double bloc du temple du Pic des neiges# contient", "el cofre detrás de los bloques apilados del Templo del Pico Nevado contiene", "die #Truhe hinter zwei Blöcken im Pic-Hibernia-Tempel# enthält", "", "le #coffre derrière le double bloc du temple du pic des Neiges# contient", ""}
    );
    hintTable[SNOWHEAD_TEMPLE_ICICLE_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"an #icy temple# contains", "un #temple enneigé# contient", "un templo helado contiene", "ein #eisiger Tempel# enthält"}
        },  //clear
            Text{"the #Snowhead Temple chest covered in snow# contains", "le #coffre enseveli de neige du temple du Pic des neiges# contient", "el cofre cubierto de nieve del Templo del Pico Nevado contiene", "die #schneebedeckte Truhe im Pic-Hibernia-Tempel# enthält", "", "le #coffre enseveli de neige du temple du pic des Neiges# contient", ""}
    );
    hintTable[SNOWHEAD_TEMPLE_BRIDGE_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"an #icy temple# contains", "un #temple enneigé# contient", "un templo helado contiene", "ein #eisiger Tempel# enthält"}
        },  //clear
            Text{"the #Snowhead Temple chest encased in ice# contains", "le #coffre gelé du temple du Pic des neiges# contient", "el cofre cubierto de hielo del Templo del Pico Nevado contiene", "die #eingefrorene Truhe im Pic-Hibernia-Tempel# enthält", "", "le #coffre gelé du temple du pic des Neiges# contient", ""}
    );
    hintTable[SH_SF_SNOW_ROOM_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Snowhead Temple bubble hidden near Eeno# contains", "la #bulle cachée près des eeno du temple du Pic des neiges# contient", "la burbuja oculta en el cuarto de los Eenos del Templo del Pico Nevado contiene", "die #versteckte Blase nahe Eeno im Pic-Hibernia-Tempel# enthält", "", "la #bulle cachée près des eeno du temple du pic des Neiges# contient", ""}
    );
    hintTable[SH_SF_CEILING_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Snowhead Temple bubble hidden in the ceiling# contains", "la #bulle cachée dans un plafond du temple du Pic des neiges# contient", "la burbuja oculta en el techo del Templo del Pico Nevado contiene", "die #an der Decke versteckte Blase im Pic-Hibernia-Tempel# enthält", "", "la #bulle cachée dans un plafond du temple du pic des Neiges# contient", ""}
    );
    hintTable[SH_SF_DINOLFOS_1] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Snowhead Temple Dinolfos# protects", "un #dinolfos du temple du Pic des neiges# contient", "un Dinolfos en el Templo del Pico Nevado resguarda", "ein #Dinolfos im Pic-Hibernia-Tempel# bewacht", "", "un #dinolfos du temple du pic des Neiges# contient", ""}
    );
    hintTable[SH_SF_DINOLFOS_2] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Snowhead Temple Dinolfos# protects", "un #dinolfos du temple du Pic des neiges# contient", "un Dinolfos en el Templo del Pico Nevado resguarda", "ein #Dinolfos im Pic-Hibernia-Tempel# bewacht", "", "un #dinolfos du temple du pic des Neiges# contient", ""}
    );
    hintTable[SH_SF_BRIDGE_ROOM_LEDGE_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Snowhead Temple bubble next to a bridge# contains", "la #bulle près d'un pont du temple du Pic des neiges# contient", "la burbuja al lado del puente del Templo del Pico Nevado contiene", "die #Blase neben einer Brücke im Pic-Hibernia-Tempel# enthält", "", "la #bulle près d'un pont du temple du pic des Neiges# contient", ""}
    );
    hintTable[SH_SF_BRIDGE_ROOM_PILLAR_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Snowhead Temple bubble under a bridge# contains", "la #bulle sous un pont du temple du Pic des neiges# contient", "la burbuja debajo del puente del Templo del Pico Nevado contiene", "die #Blase unter einer Brücke im Pic-Hibernia-Tempel# enthält", "", "la #bulle sous un pont du temple du pic des Neiges# contient", ""}
    );
    hintTable[SH_SF_MAP_ROOM_FAIRY] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #item hovering near the Snowhead Temple elevator# is", "l'#objet volant près de l'ascenseur du temple du Pic des neiges# est", "el objeto flotando cerca del elevador en el Templo del Pico Nevado es", "der #schwebende Gegenstand nahe dem Aufzug im Pic-Hibernia-Tempel# ist", "", "l'#objet volant près de l'ascenseur du temple du pic des Neiges# est", ""}
    );
    hintTable[SH_SF_MAP_ROOM_LEDGE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Snowhead Temple chest above the elevator# contains", "le #coffre surplombant l'ascenseur du temple du Pic des neiges# contient", "el cofre sobre el elevador del Templo del Pico Nevado es", "die #Truhe über dem Aufzug im Pic-Hibernia-Tempel# enthält", "", "le #coffre surplombant l'ascenseur du temple du pic des Neiges# contient", ""}
    );
    hintTable[SH_SF_BASEMENT] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Snowhead Temple chest in lava# contains", "le #coffre dans la lave au temple du Pic des neiges# contient", "el cofre sobre la lava del Templo del Pico Nevado es", "die #Truhe in der Lava im Pic-Hibernia-Tempel# enthält", "", "le #coffre dans la lave au temple du pic des Neiges# contient", ""}
    );
    hintTable[SH_SF_TWIN_BLOCK] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Snowhead Temple chest above two blocks# contains", "le #coffre surplombant le double bloc du temple du Pic des neiges# contient", "el cofre sobre los bloques apilados en el Templo del Pico Nevado es", "die #Truhe über zwei Blöcken im Pic-Hibernia-Tempel# enthält", "", "le #coffre surplombant le double bloc du temple du pic des Neiges# contient", ""}
    );
    hintTable[SH_SF_ICICLE_ROOM_WALL] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Snowhead Temple chest hidden near icicles# contains", "le #coffre caché près des glaçons du temple du Pic des neiges# contient", "el cofre cerca de las estalacticas de hielo en el Templo del Pico Nevado contiene", "die #nahe Eiszapfen versteckte Truhe im Pic-Hibernia-Tempel# enthält", "", "le #coffre caché près des glaçons du temple du pic des Neiges# contient", ""}
    );
    hintTable[SH_SF_MAIN_ROOM_WALL] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Snowhead Temple chest hidden in the main room# contains", "le #coffre caché du pilier central du temple du Pic des neiges# contient", "el cofre escondido en el cuarto principal del Templo del Pico Nevado contiene", "die #im Hauptraum versteckte Truhe im Pic-Hibernia-Tempel# enthält", "", "le #coffre caché du pilier central du temple du pic des Neiges# contient", ""}
    );
    hintTable[SH_SF_PILLAR_FREEZARDS] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Snowhead Temple chest protected by Freezards# contains", "le #coffre protégé par des glazzards au temple du Pic des neiges# contient", "el cofre resguardado por Freezards en el Templo del Pico Nevado contiene", "die #von Frostechsen bewachte Truhe im Pic-Hibernia-Tempel# enthält", "", "le #coffre protégé par des freezards au temple du pic des Neiges# contient", ""}
    );
    hintTable[SH_SF_ICE_PUZZLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Snowhead Temple chest hidden by a switch# contains", "le #coffre caché par un interrupteur au temple du Pic des neiges# contient", "el cofre ocultado por un interruptor en el Templo del Pico Nevado contiene", "die #durch einen Schalter enthüllte Truhe im Pic-Hibernia-Tempel# enthält", "", "le #coffre caché par un interrupteur au temple du pic des Neiges# contient", ""}
    );
    hintTable[SH_SF_CRATE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Snowhead Temple crate# contains", "une #boîte du temple du Pic des neiges# contient", "una caja en el Templo del Pico Nevado contiene", "eine #Kiste im Pic-Hibernia-Tempel# enthält", "", "une #boîte du temple du pic des Neiges# contient", ""}
    );
    hintTable[GOHT_HEART_CONTAINER] = HintText::Exclude({
            //obscure
            Text{"a #masked evil# contains", "abattre un #gros taureau# détient", "un mal enmascarado contiene", "ein #maskiertes Böses# enthält"}
        },  //clear
            Text{"#Goht# has", "#Rhork# a", "Goht tiene", "#Goht# hat"}
    );
//Great bay Temple
    hintTable[GBT_ICE_ARROW_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #murky watered temple# contains", "le #temple en eaux troubles# contient", "el templo de aguas turbias contiene", "ein #Tempel in trübem Wasser# enthält"}
        },  //clear
            Text{"the #Great Bay Temple Wart# protects", "le #méduso du temple de la Grande Baie# protège", "el Arghus en el Templo de la Gran Bahía resguarda", "#Wart im Schädelbucht-Tempel# bewacht", "", "le #meduso du temple de la Grande Baie# protège", ""}
    );
    hintTable[GBT_MAP_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #murky watered temple# contains", "le #temple en eaux troubles# contient", "el templo de aguas turbias contiene", "ein #Tempel in trübem Wasser# enthält"}
        },  //clear
            Text{"a #Great Bay Temple chest near a red valve# contains", "un #coffre près d'une valve du temple de la Grande Baie# contient", "el cofre cerca de una válvula roja en el Templo de la Gran Bahía contiene", "eine #Truhe nahe einem roten Ventil im Schädelbucht-Tempel# enthält"}
    );
    hintTable[GBT_COMPASS_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #murky watered temple# contains", "le #temple en eaux troubles# contient", "el templo de aguas turbias contiene", "ein #Tempel in trübem Wasser# enthält"}
        },  //clear
            Text{"the #Great Bay Temple chest near a Real Bombchu# contains", "le #coffre près d'un vrai bombchu du temple de la Grande Baie# contient", "el cofre cerca de un Bombchu real en el Templo de la Gran Bahía contiene", "die #Truhe nahe einer echten Krabbelmine im Schädelbucht-Tempel# enthält", "", "le #coffre près d'un vrai teigneux du temple de la Grande Baie# contient", ""}
    );
    hintTable[GBT_BOSS_KEY_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #murky watered temple# contains", "le #temple en eaux troubles# contient", "el templo de aguas turbias contiene", "ein #Tempel in trübem Wasser# enthält"}
        },  //clear
            Text{"the #Great Bay Temple Gekko# protects", "le #gekko du temple de la Grande Baie# protège", "el Gekko en el Templo de la Gran Bahía resguarda", "der #Gekko im Schädelbucht-Tempel# bewacht"}
    );
    hintTable[GBT_SMALL_KEY_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #murky watered temple# contains", "le #temple en eaux troubles# contient", "el templo de aguas turbias contiene", "ein #Tempel in trübem Wasser# enthält"}
        },  //clear
            Text{"the #Great Bay Temple chest near a Dexihand# contains", "le #coffre près d'une main-blanche au temple de la Grande Baie# contient", "el cofre cercano a una Dexihand en el Templo de la Gran Bahía contiene", "die #Truhe nahe einer Dexihand im Schädelbucht-Tempel# enthält"}
    );
    hintTable[GBT_SF_SKULLTULA] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Great Bay Temple Skulltula# has", "une #skulltula du temple de la Grande Baie# a", "una Skulltula en el Templo de la Gran Bahía tiene", "eine #Skulltula im Schädelbucht-Tempel# hat"}
    );
    hintTable[GBT_SF_WATER_CONTROL_UNDERWATER_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Great Bay Temple bubble in the second room# has", "la #bulle dans la seconde salle du temple de la Grande Baie# contient", "la burbuja en el segundo cuarto del Templo de la Gran Bahía contiene", "die #Blase im zweiten Raum des Schädelbucht-Tempels# enthält"}
    );
    hintTable[GBT_SF_WATERWHEEL_ROOM_LOWER] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Great Bay Temple chest near a waterwheel# contains", "un #coffre près du grand moulin du temple de la Grande Baie# contient", "el cofre cercano a una rueda hidráulica en el Templo de la Gran Bahía contiene", "eine #Truhe nahe einem Wasserrad im Schädelbucht-Tempel# enthält"}
    );
    hintTable[GBT_SF_WATERWHEEL_ROOM_UPPER] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Great Bay Temple chest near a waterwheel# contains", "un #coffre près du grand moulin du temple de la Grande Baie# contient", "el cofre cercano a una rueda hidráulica en el Templo de la Gran Bahía contiene", "eine #Truhe nahe einem Wasserrad im Schädelbucht-Tempel# enthält"}
    );
    hintTable[GBT_SF_GREEN_VALVE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Great Bay Temple chest above a ceiling# contains", "le #coffre au dessus d'un plafond du temple de la Grande Baie# contient", "el cofre cercano al techo en el Templo de la Gran Bahía contiene", "die #Truhe über einer Decke im Schädelbucht-Tempel# enthält"}
    );
    hintTable[GBT_SF_SEESAW_ROOM] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Great Bay Temple chest near the seesaws# contains", "le #coffre près des bascules du temple de la Grande Baie# contient", "el cofre cerca de los subibajas en el Templo de la Gran Bahía contiene", "die #Truhe nahe den Wippen im Schädelbucht-Tempel# enthält"}
    );
    hintTable[GBT_SF_ENTRANCE_TORCHES] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Great Bay Temple chest near the entrance# contains", "le #coffre caché dans l'entrée du temple de la Grande Baie# contient", "el cofre cerca de la entrada del Templo de la Gran Bahía contiene", "die #Truhe nahe dem Eingang des Schädelbucht-Tempels# enthält"}
    );
    hintTable[GBT_SF_BIO_BABAS] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Great Bay Temple chest protected by Bio Babas# contains", "le #coffre des baba mojo aquatiques du temple de la Grande Baie# contient", "el cofre protegido por Bio Babas Deku en el Templo de la Gran Bahía contiene", "die #von Bio-Dekuranhas bewachte Truhe im Schädelbucht-Tempel# enthält"}
    );
    hintTable[GBT_SF_UNDERWATER_BARREL] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Great Bay Temple barrel near the seesaws# contains", "le #tonneau sous les bascules du temple de la Grande Baie# contient", "el barril cerca de los subibajas en el Templo de la Gran Bahía contiene", "das #Fass nahe den Wippen im Schädelbucht-Tempel# enthält"}
    );
    hintTable[GBT_SF_WHIRLPOOL_BARREL] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Great Bay Temple barrel by the whirlpool# contains", "le #tonneau près du siphon du temple de la Grande Baie# contient", "el barril en el cuarto del remolino en el Templo de la Gran Bahía contiene", "das #Fass am Strudel im Schädelbucht-Tempel# enthält"}
    );
    hintTable[GBT_SF_WHIRLPOOL_JAR] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Great Bay Temple jar in the whirlpool# contains", "la #jarre au fond du siphon du temple de la Grande Baie# contient", "el jarrón hundido en el remolino del Templo de la Gran Bahía contiene", "der #Krug im Strudel des Schädelbucht-Tempels# enthält"}
    );
    hintTable[GBT_SF_DEXIHANDS_JAR] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Great Bay Temple jar near Dexihands# contains", "la #jarre près d'une main-blanche du temple de la Grande Baie# contient", "el jarrón hundido junto a las Dexihands en el Templo de la Gran Bahía contiene", "der #Krug nahe den Dexihänden im Schädelbucht-Tempel# enthält"}
    );
    hintTable[GBT_SF_LEDGE_JAR] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Great Bay Temple jar near a red valve# contains", "une #jarre près d'une valve rouge du temple de la Grande Baie# contient", "el jarrón cercano a una válvula roja en el Templo de la Gran Bahía contiene", "ein #Krug nahe einem roten Ventil im Schädelbucht-Tempel# enthält"}
    );
    hintTable[GBT_SF_PRE_BOSS_ROOM_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Great Bay Temple bubble near the boss door# contains", "une #bulle près de l’antre du boss du temple de la Grande Baie# contient", "la burbuja cercana a la guarida del jefe del Templo de la Gran Bahía contiene", "eine #Blase nahe der Boss-Tür im Schädelbucht-Tempel# enthält"}
    );
    hintTable[GBT_SF_PRE_BOSS_ROOM_UNDERWATER_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Great Bay Temple bubble near the boss door# contains", "une #bulle près de l’antre du boss du temple de la Grande Baie# contient", "la burbuja hundida cerca de la guarida del jefe del Templo de la Gran Bahía contiene", "eine #Blase nahe der Boss-Tür im Schädelbucht-Tempel# enthält"}
    );
    hintTable[GYORG_HEART_CONTAINER] = HintText::Exclude({
            //obscure
            Text{"a #masked evil# contains", "abattre un #énorme poisson# octroie", "un mal enmascarado contiene", "ein #maskiertes Böses# enthält"}
        },  //clear
            Text{"#Gyorg# has", "#Gyorg# a", "Gyorg tiene", "#Gyorg# hat"}
    );
//Stone Tower Temple
    hintTable[STONE_TOWER_TEMPLE_MAP_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene", "ein #steiniger Tempel# enthält"}
        },  //clear
            Text{"the #Stone Tower Temple chest near Armos# contains", "le #coffre près des armos au temple de la forteresse de pierre# contient", "el cofre cerca de los Armos en el Templo de la Torre de Piedra contiene", "die #Truhe nahe den Armos-Statuen im Felsenturm-Tempel# enthält"}
    );
    hintTable[STONE_TOWER_TEMPLE_COMPASS_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene", "ein #steiniger Tempel# enthält"}
        },  //clear
            Text{"the #Stone Tower Temple chest near a Real Bombchu# contains", "le #coffre près d'un vrai bombchu au temple de la forteresse de pierre# contient", "el cofre cerca de un Bombchu real en el Templo de la Torre de Piedra contiene", "die #Truhe nahe einer echten Krabbelmine im Felsenturm-Tempel# enthält", "", "le #coffre près d'un vrai teigneux au temple de la forteresse de pierre# contient", ""}
    );
    hintTable[STONE_TOWER_TEMPLE_BOSS_KEY_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene", "ein #steiniger Tempel# enthält"}
        },  //clear
            Text{"#Gomess, in Stone Tower Temple#, protects", "le #faucheur au temple de la forteresse de pierre# protège", "en el Templo de la Torre de Piedra, Gomess protege", "#Gomess im Felsenturm-Tempel# bewacht"}
    );
    hintTable[STONE_TOWER_TEMPLE_ARMOS_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene", "ein #steiniger Tempel# enthält"}
        },  //clear
            Text{"the #Stone Tower Temple chest in lava# contains", "le #coffre dans la lave du temple de la forteresse de pierre# contient", "el cofre sobre la lava en el Templo de la Torre de Piedra contiene", "die #Truhe in der Lava im Felsenturm-Tempel# enthält"}
    );
    hintTable[STONE_TOWER_TEMPLE_BRIDGE_SWITCH_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene", "ein #steiniger Tempel# enthält"}
        },  //clear
            Text{"the #Stone Tower Temple chest near water# contains", "le #coffre près de l'eau du temple de la forteresse de pierre# contient", "el cofre cerca del agua en el Templo de la Torre de Piedra contiene", "die #Truhe nahe dem Wasser im Felsenturm-Tempel# enthält"}
    );
    hintTable[STONE_TOWER_TEMPLE_UPDRAFT_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene", "ein #steiniger Tempel# enthält"}
        },  //clear
            Text{"the #Stone Tower Temple chest near a Hiploop# contains", "le #coffre près d'un hiploop du temple de la forteresse de pierre# contient", "un templo rocoso contiene", "die #Truhe nahe einem Hiploop im Felsenturm-Tempel# enthält"}
    );
    hintTable[STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene", "ein #steiniger Tempel# enthält"}
        },  //clear
            Text{"the #Stone Tower Temple chest near Death Armos# contains", "le #coffre près des armos sombres du temple de la forteresse de pierre# contient", "el cofre cerca de los Armos Letales en el Templo de la Torre de Piedra contiene", "die #Truhe nahe Schatten-Armos im Felsenturm-Tempel# enthält"}
    );
    hintTable[STONE_TOWER_TEMPLE_UPRIGHT_DEATH_ARMOS_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene", "ein #steiniger Tempel# enthält"}
        },  //clear
            Text{"an #upside down chest# contains", "un #coffre à l’envers# contient", "", "eine #auf dem Kopf stehende Truhe# enthält"}
    );
    hintTable[STONE_TOWER_TEMPLE_LIGHT_ARROW_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene", "ein #steiniger Tempel# enthält"}
        },  //clear
            Text{"the #Stone Tower Temple Garo Master# protects", "le #grand maître des Garos du temple de la forteresse de pierre# protège", "el Maestro Garo en el Templo de la Torre de Piedra protege", "der #Garo-Meister im Felsenturm-Tempel# bewacht"}
    );
    hintTable[STONE_TOWER_TEMPLE_GIANTS_MASK_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene", "ein #steiniger Tempel# enthält"}
        },  //clear
            Text{"the #blue Twinmold# protects", "le #Skorn bleu# protège", "el Twinmold azul protege", "der #blaue Twinmold# bewacht"}
    );
    hintTable[ST_SF_MIRROR_SUN_BLOCK] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Stone Tower Temple chest near mirrors# contains", "un #coffre derrière un bloc soleil du temple de la forteresse de pierre# contient", "el cofre cerca de los espejos en el Templo de la Torre de Piedra contiene", "eine #Truhe nahe den Spiegeln im Felsenturm-Tempel# enthält"}
    );
    hintTable[ST_SF_LAVA_ROOM_LEDGE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Stone Tower Temple chest near fiery updrafts# contains", "un #coffre près de courants ascendant au temple de la forteresse de pierre# contient", "el cofre cerca de los remolinos y lava en el Templo de la Torre de Piedra contiene", "eine #Truhe nahe den feurigen Aufwinden im Felsenturm-Tempel# enthält"}
    );
    hintTable[ST_SF_LAVA_ROOM_FIRE_RING] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Stone Tower Temple chest near fiery updrafts# contains", "un #coffre près de courants ascendant au temple de la forteresse de pierre# contient", "el cofre de interruptor cerca de los remolinos y lava en el Templo de la Torre de Piedra contiene", "eine #Truhe nahe den feurigen Aufwinden im Felsenturm-Tempel# enthält"}
    );
    hintTable[ST_SF_EYEGORE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Stone Tower Temple Eyegore# protects", "l'#eyegore du temple de la forteresse de pierre# protège", "el Ojo Diana en el Templo de la Torre de Piedra protege", "der #Eyegore im Felsenturm-Tempel# bewacht"}
    );
    hintTable[ST_SF_UPDRAFT_FIRE_RING] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Stone Tower Temple chest above the updrafts# contains", "le #coffre au bout des courants ascendants du temple de la forteresse de pierre# contient", "el cofre sobre los remolinos en el Templo de la Torre de Piedra contiene", "die #Truhe über den Aufwinden im Felsenturm-Tempel# enthält"}
    );
    hintTable[ST_SF_MIRROR_SUN_SWITCH] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"a #Stone Tower Temple chest near mirrors# contains", "un #coffre près de miroirs du temple de la forteresse de pierre# contient", "un cofre cerca de los espejos en el Templo de la Torre de Piedra contiene", "eine #Truhe nahe den Spiegeln im Felsenturm-Tempel# enthält"}
    );
    hintTable[ST_SF_BOSS_WARP] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Stone Tower Temple chest near the warp point# contains", "le #coffre près du téléporteur du temple de la forteresse de pierre# contient", "el cofre cerca de la tabla de teletransportación en el Templo de la Torre de Piedra contiene", "die #Truhe nahe dem Teleporter im Felsenturm-Tempel# enthält"}
    );
    hintTable[ST_SF_WIZZROBE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Stone Tower Temple Wizzrobe# protects", "le #sorcier du temple de la forteresse de pierre# protège", "el Wizzrobe en el Templo de la Torre de Piedra protege", "der #Zaurob im Felsenturm-Tempel# bewacht"}
    );
    hintTable[ST_SF_DEATH_ARMOS] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Stone Tower Temple chest used to reach the boss# contains", "le #coffre qui permet d’atteindre le boss du temple de la forteresse de pierre# contient", "el cofre usado para alcanzar la guarida del jefe en el Templo de la Torre de Piedra contiene", "die #Truhe zum Erreichen des Bosses im Felsenturm-Tempel# enthält"}
    );
    hintTable[ST_SF_UPDRAFT_FROZEN_EYE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Stone Tower Temple chest revealed by a frozen eye# contains", "le #coffre révélé par un œil glacé du temple de la forteresse de pierre# contient", "el cofre revelado por un ojo congelado en el Templo de la Torre de Piedra contiene", "die #durch ein gefrorenes Auge enthüllte Truhe im Felsenturm-Tempel# enthält"}
    );
    hintTable[ST_SF_THIN_BRIDGE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Stone Tower Temple chest near Beamos# contains", "le #coffre près d'un sentinelle du temple de la forteresse de pierre# contient", "el cofre cerca de un Beamos en el Templo de la Torre de Piedra contiene", "die #Truhe nahe Beamos im Felsenturm-Tempel# enthält"}
    );
    hintTable[ST_SF_BASEMENT_LEDGE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Stone Tower Temple chest hidden in the dark room# contains", "le #coffre dans une pièce sombre du temple de la forteresse de pierre# contient", "el cofre escondido en el cuarto oscuro del Templo de la Torre de Piedra contiene", "die #im dunklen Raum versteckte Truhe im Felsenturm-Tempel# enthält"}
    );
    hintTable[ST_SF_STATUE_EYE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Stone Tower Temple chest revealed by the statue's eye# contains", "le #coffre révélé par l'œil de la statue du temple de la forteresse de pierre# contient", "el cofre revelado por el ojo de la estatua en el Templo de la Torre de Piedra contiene", "die #durch das Auge der Statue enthüllte Truhe im Felsenturm-Tempel# enthält"}
    );
    hintTable[ST_SF_UNDERWATER] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Stone Tower Temple submerged chest# contains", "le #coffre submergé du temple de la forteresse de pierre# contient", "el cofre hundido en el Templo de la Torre de Piedra contiene", "die #Unterwassertruhe im Felsenturm-Tempel# enthält"}
    );
    hintTable[ST_SF_BRIDGE_CRYSTAL] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es", "eine #verirrte Fee# ist"}
        },  //clear
            Text{"the #Stone Tower Temple chest near the boss door# contains", "le #coffre près de l'antre du boss du temple de la forteresse de pierre# contient", "el cofre cerca de la puerta del jefe en el Templo de la Torre de Piedra contiene", "die #Truhe nahe der Boss-Tür im Felsenturm-Tempel# enthält"}
    );
    hintTable[TWINMOLD_HEART_CONTAINER] = HintText::Exclude({
            //obscure
            Text{"a #masked evil# contains", "occire les #mille-pattes jumeaux# octroie", "un mal enmascarado contiene", "ein #maskiertes Böse# enthält"}
        },  //clear
            Text{"the #red Twinmold# has", "le #Skorn rouge# a", "el Twinmold rojo tiene", "der #rote Twinmold# hat"}
    );
//Pirate Fortress
    hintTable[PF_INTERIOR_HOOKSHOT_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene", "die #Heimat der Piraten# enthält"}
        },  //clear
            Text{"the #Pirates' Fortress chest guarded by their leader# contains", "le #coffre gardé par la cheffe de la forteresse des pirates# contient", "el cofre protegido por la líder pirata en su fortaleza contiene", "die #von der Anführerin bewachte Truhe in der Piratenfestung# enthält"}
    );
    hintTable[PF_INT_LOWER_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene", "die #Heimat der Piraten# enthält"}
        },  //clear
            Text{"the #Pirates' Fortress chest in the courtyard# contains", "le #coffre dans la cour de la forteresse des pirates# contient", "el cofre inferior en el patio de la Fortaleza Pirata contiene", "die #Truhe im Innenhof der Piratenfestung# enthält"}
    );
    hintTable[PF_INT_UPPER_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene", "die #Heimat der Piraten# enthält"}
        },  //clear
            Text{"the #Pirates' Fortress chest on a roof# contains", "le #coffre sur un toit de la forteresse des pirates# contient", "el cofre superior en el patio de la Fortaleza Pirata contiene", "die #Truhe auf einem Dach der Piratenfestung# enthält"}
    );
    hintTable[PF_INT_TANK_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene", "die #Heimat der Piraten# enthält"}
        },  //clear
            Text{"the #Pirates' Fortress chest in a fish tank# contains", "le #coffre dans un aquarium de la forteresse des pirates# contient", "el cofre en la pecera de la Fortaleza Pirata contiene", "die #Truhe im Aquarium der Piratenfestung# enthält"}
    );
    hintTable[PF_INT_GUARD_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene", "die #Heimat der Piraten# enthält"}
        },  //clear
            Text{"the #Pirates' Fortress chest guarded by many# contains", "le #coffre bien gardé de la forteresse des pirates# contient", "el cofre protegido por muchas piratas en su fortaleza contiene", "die #von vielen bewachte Truhe in der Piratenfestung# enthält"}
    );
    hintTable[PF_CAGE_ROOM_SHALLOW_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene", "die #Heimat der Piraten# enthält"}
        },  //clear
            Text{"a #Pirates' Fortress chest near a cage# contains", "le #coffre près d'une cage de la forteresse des pirates# contient", "el cofre cerca de la celda en la Fortaleza Pirata contiene", "eine #Truhe nahe einem Käfig in der Piratenfestung# enthält"}
    );
    hintTable[PF_CAGE_ROOM_DEEP_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene", "die #Heimat der Piraten# enthält"}
        },  //clear
            Text{"a #Pirates' Fortress chest near a cage# contains", "le #coffre près d'une cage de la forteresse des pirates# contient", "el cofre cerca de la celda en la Fortaleza Pirata contiene", "eine #Truhe nahe einem Käfig in der Piratenfestung# enthält"}
    );
    hintTable[PF_MAZE_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene", "die #Heimat der Piraten# enthält"}
        },  //clear
            Text{"the #Pirates' Fortress chest in a watery maze# contains", "le #coffre dans le labyrinthe aquatique de la forteresse des pirates# contient", "el cofre en el laberinto acuático en la Fortaleza Pirata contiene", "die #Truhe im Wasser-Labyrinth der Piratenfestung# enthält"}
    );
    hintTable[PF_SEWER_CAGE] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene", "die #Heimat der Piraten# enthält"}
        },  //clear
            Text{"the #Pirates' Fortress prize in a cage# contains", "le #trésor derrière des barreaux de la forteresse des pirates# est", "la celda en la Fortaleza Pirata contiene", "die #Beute im Käfig der Piratenfestung# enthält"}
    );
    hintTable[PF_EXTERIOR_LOG_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene", "die #Heimat der Piraten# enthält"}
        },  //clear
            Text{"a #Pirates' Fortress chest beneath the patrol boats# contains", "un #coffre submergé sous la vigie de la forteresse des pirates# contient", "un cofre hundido bajo la patrulla pirata en su fortaleza contiene", "eine #Truhe unter den Patrouillenbooten der Piratenfestung# enthält"}
    );
    hintTable[PF_EXTERIOR_SAND_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene", "die #Heimat der Piraten# enthält"}
        },  //clear
            Text{"a #Pirates' Fortress chest beneath the patrol boats# contains", "un #coffre submergé sous la vigie de la forteresse des pirates# contient", "un cofre hundido bajo la patrulla pirata en su fortaleza contiene", "eine #Truhe unter den Patrouillenbooten der Piratenfestung# enthält"}
    );
    hintTable[PF_EXTERIOR_CORNER_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene", "die #Heimat der Piraten# enthält"}
        },  //clear
            Text{"a #Pirates' Fortress chest beneath the patrol boats# contains", "un #coffre submergé sous la vigie de la forteresse des pirates# contient", "un cofre hundido bajo la patrulla pirata en su fortaleza contiene", "eine #Truhe unter den Patrouillenbooten der Piratenfestung# enthält"}
    );
    hintTable[PF_INT_INVISIBLE_SOLDIER] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene", "die #Heimat der Piraten# enthält"}
        },  //clear
            Text{"#Shiro, in Pirates' Fortress#, has", "#Shiro, qui est perdu dans la forteresse des pirates#, a", "Shiro, en la Fortaleza Pirata, tiene", "#Shiro in der Piratenfestung# hat"}
    );
    hintTable[PF_INT_HOOKSHOT_ROOM_ZORA_EGG] = HintText::Exclude({
            //obscure
            Text{"in the #home of pirates# rests", "le #foyer des pirates# héberge", "en el hogar de las piratas yace", "in der #Heimat der Piraten# ruht"}
        },  //clear
            Text{"#bottling the Zora Egg in the leader's room# makes", "embouteiller l'#œuf de Zora dans la salle du trône de pirates# crée", "embotellar el Huevo Zora en el cuarto de la líder da", "das #Zora-Ei im Raum der Anführerin in eine Flasche zu stecken# bewirkt"}
    );
    hintTable[PF_INT_GUARD_ROOM_ZORA_EGG] = HintText::Exclude({
            //obscure
            Text{"in the #home of pirates# rests", "le #foyer des pirates# héberge", "en el hogar de las piratas yace", "in der #Heimat der Piraten# ruht"}
        },  //clear
            Text{"#bottling a Zora Egg in Pirates' Fortress# makes", "embouteiller un #œuf de Zora dans la forteresse des pirates# crée", "embotellar un Huevo Zora en la Fortaleza Pirata da", "das #Zora-Ei in der Piratenfestung in eine Flasche zu stecken# bewirkt"}
    );
    hintTable[PF_INT_BARREL_MAZE_ZORA_EGG] = HintText::Exclude({
            //obscure
            Text{"in the #home of pirates# rests", "le #foyer des pirates# héberge", "en el hogar de las piratas yace", "in der #Heimat der Piraten# ruht"}
        },  //clear
            Text{"#bottling a Zora Egg in Pirates' Fortress# makes", "embouteiller un #œuf de Zora dans la forteresse des pirates# crée", "embotellar un Huevo Zora en la Fortaleza Pirata da", "das #Zora-Ei in der Piratenfestung in eine Flasche zu stecken# bewirkt"}
    );
    hintTable[PF_INT_LAVA_ROOM_ZORA_EGG] = HintText::Exclude({
            //obscure
            Text{"in the #home of pirates# rests", "le #foyer des pirates# héberge", "en el hogar de las piratas yace", "in der #Heimat der Piraten# ruht"}
        },  //clear
            Text{"#bottling a Zora Egg in Pirates' Fortress# makes", "embouteiller un #œuf de Zora dans la forteresse des pirates# crée", "embotellar un Huevo Zora en la Fortaleza Pirata da", "das #Zora-Ei in der Piratenfestung in eine Flasche zu stecken# bewirkt"}
    );
//Beneath the Well
    hintTable[BENEATH_THE_WELL_MIRROR_SHIELD_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #frightful exchange# contains", "le #marché des revenants# contient", "un intercambio espantoso contiene", "ein #grausiger Tausch# enthält"}
        },  //clear
            Text{"the #chest at the end Beneath the Well# contains", "le #coffre dans le pièce lumineuse du fond du puits# contient", "el cofre al final de Bajo el Pozo contiene", "die #Truhe am Ende von Unter dem Brunnen# enthält"}
    );
    hintTable[WELL_LEFT_PATH_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #frightful exchange# contains", "le #marché des revenants# contient", "un intercambio espantoso contiene", "ein #grausiger Tausch# enthält"}
        },  //clear
            Text{"the #chest in the left path Beneath the Well# contains", "le #coffre de la branche de gauche du fond du puits# contient", "el cofre en el camino izquierdo Bajo el Pozo contiene", "die #Truhe auf dem linken Pfad von Unter dem Brunnen# enthält"}
    );
    hintTable[WELL_RIGHT_PATH_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #frightful exchange# contains", "le #marché des revenants# contient", "un intercambio espantoso contiene", "ein #grausiger Tausch# enthält"}
        },  //clear
            Text{"the #chest in the right path Beneath the Well# contains", "le #coffre de la branche de droite du fond du puits# contient", "el cofre en el camino derecho Bajo el Pozo contiene", "die #Truhe auf dem rechten Pfad von Unter dem Brunnen# enthält"}
    );
    hintTable[BENEATH_THE_WELL_COW] = HintText::Exclude({
            //obscure
            Text{"a #lost creature# gives", "la #source laitière des puits# prodigue", "una criatura perdida da", "ein #verirrtes Wesen# enthält"}
        },  //clear
            Text{"the #cow Beneath the Well# has", "la #vache du fond du puits# a", "la vaca encontrada Bajo el Pozo da", "die #Kuh Unter dem Brunnen# hat"}
    );
//Ikana Castle
    hintTable[IKANA_CASTLE_PILLAR] = HintText::Exclude({
            //obscure
            Text{"a #fiery pillar# contains", "un #pilier enflammé# garde", "un pilar en llamas contiene", "eine #feurige Säule# enthält"}
        },  //clear
            Text{"an #Ikana Castle pillar# holds", "un #pilier embrasé du château d'Ikana# contient", "un pilar en el Castillo de Ikana tiene", "eine #Säule von Schloss Ikana# trägt"}
    );
    hintTable[IKANA_CASTLE_IKANA_KING] = HintText::Exclude({
            //obscure
            Text{"a #fallen king# teaches", "un #roi déchu# enseigne", "un rey caído enseña", "ein #gefallener König# lehrt"}
        },  //clear
            Text{"#Igos du Ikana# has", "#Igos d'Ikana# a", "el rey Igos du Ikana tiene", "#Igos du Ikana# hat"}
    );
//Secret Shrine
    hintTable[SECRET_SHRINE_DINOLFOS_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #secret place# contains", "#deux fois deux cœurs# débloque", "un lugar secreto contiene", "ein #geheimer Ort# enthält"}
        },  //clear
            Text{"the #Secret Shrine Dinolfos# protect", "le #dinolfos du sanctuaire secret# protège", "el Dinolfos del Santuario Secreto protege", "die #Dinolfos im verborgenen Schrein jenseits des Wasserfalls# bewachen"}
    );
    hintTable[SECRET_SHRINE_WIZZROBE_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #secret place# contains", "#huit cœurs# débloquent", "un lugar secreto contiene", "ein #geheimer Ort# enthält"}
        },  //clear
            Text{"the #Secret Shrine Wizzrobe# protects", "le #sorcier du sanctuaire secret# protège", "el Wizzrobe del Santuario Secreto protege", "der #Zaurob im verborgenen Schrein jenseits des Wasserfalls# bewacht"}
    );
    hintTable[SECRET_SHRINE_WART_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #secret place# contains", "une #douzaine de cœurs# débloquent", "un lugar secreto contiene", "ein #geheimer Ort# enthält"}
        },  //clear
            Text{"the #Secret Shrine Wart# protects", "le #méduso du sanctuaire secret# protège", "el Arghus del Santuario Secreto protege", "das #Warzenauge im verborgenen Schrein jenseits des Wasserfalls# bewacht", "", "le #meduso du sanctuaire secret# protège", ""}
    );
    hintTable[SECRET_SHRINE_GARO_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #secret place# contains", "#seize cœurs# débloquent", "un lugar secreto contiene", "ein #geheimer Ort# enthält"}
        },  //clear
            Text{"the #Secret Shrine Garo Master# protects", "le #grand maître des Garos du sanctuaire secret# protège", "el Maestro Garo del Santuario Secreto protege", "der #Garo-Meister im verborgenen Schrein jenseits des Wasserfalls# bewacht"}
    );
    hintTable[SECRET_SHRINE_FINAL_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #secret place# contains", "#triompher de moult revanches# octroie", "un lugar secreto contiene", "ein #geheimer Ort# enthält"}
        },  //clear
            Text{"the #Secret Shrine's final prize# is", "la #récompense ultime du sanctuaire secret# est", "la recompensa final del Santuario Secreto es", "der #finale Preis im verborgenen Schrein jenseits des Wasserfalls# ist"}
    );
//The Moon
    hintTable[THE_MOON_DEKU_TRIAL_BONUS] = HintText::Exclude({
            //obscure
            Text{"a #masked child's game# contains", "un #cache-cache feuillu# recèle", "un juego de niños enmascarados contiene", "ein #maskiertes Kinderspiel# enthält"}
        },  //clear
            Text{"the #Odolwa Moon Trial prize# is", "la #partie de cache-cache avec l'enfant au masque d'Odolwa# recèle", "la recompensa de la prueba de Odolwa en la Luna es", "das #Deku-Labyrinth des Mondes# enthält"}
    );
    hintTable[THE_MOON_GORON_TRIAL_BONUS] = HintText::Exclude({
            //obscure
            Text{"a #masked child's game# contains", "un #cache-cache roulant# recèle", "un juego de niños enmascarados contiene", "ein #maskiertes Kinderspiel# enthält"}
        },  //clear
            Text{"the #Goht Moon Trial's prize# is", "la #partie de cache-cache avec l'enfant au masque de Rhork# recèle", "la recompensa de la prueba de Goht en la Luna es", "das #Goronen-Labyrinth des Mondes# enthält"}
    );
    hintTable[THE_MOON_ZORA_TRIAL_BONUS] = HintText::Exclude({
            //obscure
            Text{"a #masked child's game# contains", "un #cache-cache aquatique# recèle", "un juego de niños enmascarados contiene", "ein #maskiertes Kinderspiel# enthält"}
        },  //clear
            Text{"the #Gyorg Moon Trial's prize# is", "la #partie de cache-cache avec l'enfant au masque de Gyorg# recèle", "la recompensa de la prueba de Gyorg en la Luna es", "das #Zora-Labyrinth des Mondes# enthält"}
    );
    hintTable[THE_MOON_LINK_TRIAL_BONUS] = HintText::Exclude({
            //obscure
            Text{"a #masked child's game# contains", "un #cache-cache hostile# recèle", "un juego de niños enmascarados contiene", "ein #maskiertes Kinderspiel# enthält"}
        },  //clear
            Text{"the #Twinmold Moon Trial's prize# is", "la #partie de cache-cache avec l'enfant au masque de Skorn# recèle", "la recompensa de la prueba de Twinmold en la Luna es", "das #Link-Labyrinth des Mondes# enthält"}
    );
    hintTable[THE_MOON_GARO_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #masked child's game# contains", "un #cache-cache hostile# recèle", "un juego de niños enmascarados contiene", "ein #maskiertes Kinderspiel# enthält"}
        },  //clear
            Text{"the #Twinmold Moon Trial Garo Master# protects", "le #grand maître des Garos de la lune# protège", "el Maestro Garo en la prueba de Twinmold en la Luna protege", "der #Garo-Meister im Link-Labyrinth des Mondes# bewacht"}
    );
    hintTable[THE_MOON_IRON_KNUCKLE_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #masked child's game# contains", "un #cache-cache hostile# recèle", "un juego de niños enmascarados contiene", "ein #maskiertes Kinderspiel# enthält"}
        },  //clear
            Text{"the #Twinmold Moon Trial Iron Knuckle# protects", "le #hache-viande de la lune# protège", "el Nudillo de Hierro en la prueba de Twinmold en la Luna protege", "der #Eisenprinz im Link-Labyrinth des Mondes# bewacht"}
    );
    hintTable[THE_MOON_MAJORA_CHILD] = HintText::Exclude({
            //obscure
            Text{"the #lonely child# rewards", "l'#enfant isolé# décerne", "el niño solitario recompensa con", "das #einsame Kind# entlohnt"}
        },  //clear
            Text{"the #moon child wearing Majora's Mask# has", "l'#enfant au masque de Majora# détient", "el niño en la luna que usa la Máscara de Majora tiene", "das #Kind mit Majoras Maske# hat"}
    );
//Southern Swamp Skulltula House
    hintTable[SSH_MAIN_ROOM_NEAR_CEILING] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"the #swamp Skulltula high on the main room wall# has", "la #skulltula des marais en haut de la pièce principale# a", "la Skulltula del pantano alto en la pared del cuarto principal tiene", "die #Sumpf-Skulltula oben an der Wand im Hauptraum# hat"}
    );
    hintTable[SSH_MAIN_ROOM_WATER] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the main room# has", "une #skulltula des marais dans la pièce principale# a", "la Skulltula del pantano andando en el agua del cuarto principal tiene", "eine #Sumpf-Skulltula im Hauptraum# hat"}
    );
    hintTable[SSH_MAIN_ROOM_LOWER_LEFT_SOIL] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the main room's soil# has", "une #skulltula des marais dans la terre meuble de la pièce principale# a", "la Skulltula del pantano dentro de la tierra blanda a la izquierda tiene", "eine #Sumpf-Skulltula im Fleckchen weicher Erde des Hauptraums# hat"}
    );
    hintTable[SSH_MAIN_ROOM_LOWER_RIGHT_SOIL] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the main room's soil# has", "une #skulltula des marais dans la terre meuble de la pièce principale# a", "la Skulltula del pantano dentro de la tierra blanda a la derecha tiene", "eine #Sumpf-Skulltula im Fleckchen weicher Erde des Hauptraums# hat"}
    );
    hintTable[SSH_MAIN_ROOM_UPPER_SOIL] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the main room's soil# has", "une #skulltula des marais dans la terre meuble de la pièce principale# a", "la Skulltula del pantano dentro de la tierra blanda superior tiene", "eine #Sumpf-Skulltula im Fleckchen weicher Erde des Hauptraums# hat"}
    );
    hintTable[SSH_MAIN_ROOM_PILLAR] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the main room# has", "une #skulltula des marais dans la pièce principale# a", "la Skulltula del pantano andando en el pilar del cuarto principal tiene", "eine #Sumpf-Skulltula im Hauptraum# hat"}
    );
    hintTable[SSH_MAIN_ROOM_UPPER_PILLAR] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the main room# has", "une #skulltula des marais dans la pièce principale# a", "la Skulltula del pantano andando en el pilar superior del cuarto principal tiene", "eine #Sumpf-Skulltula im Hauptraum# hat"}
    );
    hintTable[SSH_MAIN_ROOM_JAR] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the main room# has", "une #skulltula des marais dans la pièce principale# a", "la Skulltula del pantano dentro del jarrón en el cuarto principal tiene", "eine #Sumpf-Skulltula im Hauptraum# hat"}
    );
    hintTable[SSH_MONUMENT_ROOM_CRATE_1] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the slab room# has", "une #skulltula des marais dans la pièce à stèle# a", "una Skulltula del pantano dentro de una caja en el cuarto del monumento tiene", "eine #Sumpf-Skulltula im Monument-Raum# hat"}
    );
    hintTable[SSH_MONUMENT_ROOM_CRATE_2] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the slab room# has", "une #skulltula des marais dans la pièce à stèle# a", "una Skulltula del pantano dentro de una caja en el cuarto del monumento tiene", "eine #Sumpf-Skulltula im Monument-Raum# hat"}
    );
    hintTable[SSH_MONUMENT_ROOM_TORCH] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the slab room# has", "une #skulltula des marais dans la pièce à stèle# a", "la Skulltula del pantano cerca de la antorcha en el cuarto del monumento tiene", "eine #Sumpf-Skulltula im Monument-Raum# hat"}
    );
    hintTable[SSH_MONUMENT_ROOM_ON_MONUMENT] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the slab room# has", "une #skulltula des marais dans la pièce à stèle# a", "la Skulltula del pantano andando sobre el monumento tiene", "eine #Sumpf-Skulltula im Monument-Raum# hat"}
    );
    hintTable[SSH_MONUMENT_ROOM_LOWER_WALL] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"the #swamp Skulltula high on the slab room wall# has", "la #skulltula des marais sur le mur de la pièce à stèle# a", "la Skulltula del pantano andando sobre la pared del cuarto del monumento tiene", "die #Sumpf-Skulltula oben an der Wand vom Monument-Raum# hat"}
    );
    hintTable[SSH_GOLD_ROOM_NEAR_CEILING] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"the #swamp Skulltula high on the gold room wall# has", "la #skulltula des marais en haut de la pièce dorée# a", "la Skulltula del pantano en lo alto del cuarto dorado tiene", "die #Sumpf-Skulltula oben an der Wand im vergoldeten Raum# hat"}
    );
    hintTable[SSH_GOLD_ROOM_PILLAR] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"the #swamp Skulltula on the gold room pillar# has", "la #skulltula des marais sur un pilier de la pièce dorée# a", "la Skulltula del pantano cerca del techo del cuarto dorado tiene", "die #Sumpf-Skulltula auf der Säule im vergoldeten Raum# hat"}
    );
    hintTable[SSH_GOLD_ROOM_BEEHIVE] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"the #swamp Skulltula in a gold room beehive# has", "la #skulltula des marais dans une ruche de la pièce dorée# a", "la Skulltula del pantano en el panal del cuarto dorado tiene", "die #Sumpf-Skulltula im Bienennest im vergoldeten Raum# hat"}
    );
    hintTable[SSH_GOLD_ROOM_WALL] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"the #swamp Skulltula on the gold room ladder# has", "la #skulltula des marais sur l'échelle de la pièce dorée# a", "la Skulltula del pantano sobre la escalera del cuarto dorado tiene", "die #Sumpf-Skulltula auf der Leiter im vergoldeten Raum# hat"}
    );
    hintTable[SSH_POT_ROOM_JAR] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the jar room# has", "une #skulltula des marais dans la pièce à jarres# a", "una Skulltula del pantano dentro de un jarrón pequeño en el cuarto de jarrones tiene", "eine #Sumpf-Skulltula im Raum der Krüge# hat"}
    );
    hintTable[SSH_POT_ROOM_POT_1] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the jar room# has", "une #skulltula des marais dans la pièce à jarres# a", "una Skulltula del pantano dentro de un jarrón grande en el cuarto de jarrones tiene", "eine #Sumpf-Skulltula im Raum der Krüge# hat"}
    );
    hintTable[SSH_POT_ROOM_POT_2] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the jar room# has", "une #skulltula des marais dans la pièce à jarres# a", "una Skulltula del pantano dentro de un jarrón grande en el cuarto de jarrones tiene", "eine #Sumpf-Skulltula im Raum der Krüge# hat"}
    );
    hintTable[SSH_POT_ROOM_BEHIND_VINES] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"the #swamp Skulltula behind the jar room vines# has", "la #skulltula des marais derrière les lianes de la pièce à jarres# a", "la Skulltula del pantano detrás de las enredaderas en el cuarto de jarrones tiene", "die #Sumpf-Skulltula hinter den Ranken im Raum der Krüge# hat"}
    );
    hintTable[SSH_POT_ROOM_WALL] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"the #swamp Skulltula on the jar room wall# has", "la #skulltula des marais sur le mur de la pièce à jarres# a", "la Skulltula del pantano en la pared del cuarto de jarrones tiene", "die #Sumpf-Skulltula an der Wand im Raum der Krüge# hat"}
    );
    hintTable[SSH_POT_ROOM_BEEHIVE_1] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in a jar room beehive# has", "une #skulltula des marais dans une ruche de la pièce à jarres# a", "una Skulltula del pantano en el panal del cuarto de jarrones tiene", "eine #Sumpf-Skulltula im Bienennest im Raum der Krüge# hat"}
    );
    hintTable[SSH_POT_ROOM_BEEHIVE_2] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in a jar room beehive# has", "une #skulltula des marais dans une ruche de la pièce à jarres# a", "una Skulltula del pantano en el panal del cuarto de jarrones tiene", "eine #Sumpf-Skulltula im Bienennest im Raum der Krüge# hat"}
    );
    hintTable[SSH_TREE_ROOM_TREE_1] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the tree room# has", "une #skulltula des marais dans perchée sur son arbre# a", "una Skulltula del pantano en el cuarto del árbol", "eine #Sumpf-Skulltula im Raum mit dem Baum# hat"}
    );
    hintTable[SSH_TREE_ROOM_TREE_2] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the tree room# has", "une #skulltula des marais dans perchée sur son arbre# a", "una Skulltula del pantano en el cuarto del árbol", "eine #Sumpf-Skulltula im Raum mit dem Baum# hat"}
    );
    hintTable[SSH_TREE_ROOM_TREE_3] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the tree room# has", "une #skulltula des marais dans perchée sur son arbre# a", "una Skulltula del pantano en el cuarto del árbol", "eine #Sumpf-Skulltula im Raum mit dem Baum# hat"}
    );
    hintTable[SSH_TREE_ROOM_GRASS_1] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the tree room# has", "une #skulltula des marais dans la pièce de l'arbre# a", "una Skulltula del pantano en el cuarto del árbol", "eine #Sumpf-Skulltula im Raum mit dem Baum# hat"}
    );
    hintTable[SSH_TREE_ROOM_GRASS_2] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"a #swamp Skulltula in the tree room# has", "une #skulltula des marais dans la pièce de l'arbre# a", "una Skulltula del pantano en el cuarto del árbol", "eine #Sumpf-Skulltula im Raum mit dem Baum# hat"}
    );
    hintTable[SSH_TREE_ROOM_BEEHIVE] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"the #swamp Skulltula in a tree room beehive# has", "une #skulltula des marais dans une ruche de la pièce de l'arbre# a", "la Skulltula del pantano en el panal del cuarto del árbol", "die #Sumpf-Skulltula im Bienennest im Raum mit dem Baum# hat"}
    );
//Oceanside spider House
    hintTable[OSH_ENTRANCE_LEFT_WALL] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula down the entrance slope# has", "une #skulltula de la côte dans la pente d'entrée# a", "una Skulltula del océano en el declive de la entrada tiene", "eine #Meer-Skulltula an der Rampe am Eingang# hat"}
    );
    hintTable[OSH_ENTRANCE_RIGHT_WALL] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula down the entrance slope# has", "une #skulltula de la côte dans la pente d'entrée# a", "una Skulltula del océano en el declive de la entrada tiene", "eine #Meer-Skulltula an der Rampe am Eingang# hat"}
    );
    hintTable[OSH_ENTRANCE_WEB] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"the #ocean Skulltula behind an entrance web# has", "la #skulltula de la côte derrière une toile à l'entrée# a", "una Skulltula del océano detrás de las telarañas en la entrada tiene", "die #Meer-Skulltula hinter einem Spinnennetz am Eingang# hat"}
    );
    hintTable[OSH_LIBRARY_HOLE_BEHIND_PICTURE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the library# has", "une #skulltula de la côte dans la bibliothèque# a", "una Skulltula del océano en la biblioteca tiene", "eine #Meer-Skulltula in der Bibliothek# hat"}
    );
    hintTable[OSH_LIBRARY_HOLE_BEHIND_CABINET] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the library# has", "une #skulltula de la côte dans la bibliothèque# a", "una Skulltula del océano en la biblioteca tiene", "eine #Meer-Skulltula in der Bibliothek# hat"}
    );
    hintTable[OSH_LIBRARY_ON_CORNER_BOOKSHELF] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the library# has", "une #skulltula de la côte dans la bibliothèque# a", "una Skulltula del océano en la biblioteca tiene", "eine #Meer-Skulltula in der Bibliothek# hat"}
    );
    hintTable[OSH_LIBRARY_CEILING_EDGE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the library# has", "une #skulltula de la côte dans la bibliothèque# a", "una Skulltula del océano en la biblioteca tiene", "eine #Meer-Skulltula in der Bibliothek# hat"}
    );
    hintTable[OSH_LIBRARY_BEHIND_BOOKCASE_1] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the library# has", "une #skulltula de la côte dans la bibliothèque# a", "una Skulltula del océano en la biblioteca tiene", "eine #Meer-Skulltula in der Bibliothek# hat"}
    );
    hintTable[OSH_LIBRARY_BEHIND_BOOKCASE_2] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the library# has", "une #skulltula de la côte dans la bibliothèque# a", "una Skulltula del océano en la biblioteca tiene", "eine #Meer-Skulltula in der Bibliothek# hat"}
    );
    hintTable[OSH_LIBRARY_BEHIND_PICTURE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the library# has", "une #skulltula de la côte dans la bibliothèque# a", "una Skulltula del océano en la biblioteca tiene", "eine #Meer-Skulltula in der Bibliothek# hat"}
    );
    hintTable[OSH_SECOND_ROOM_CEILING_EDGE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the hallway# has", "une #skulltula de la côte dans le couloir# a", "una Skulltula del océano en el pasillo tiene", "eine #Meer-Skulltula im Flur# hat"}
    );
    hintTable[OSH_SECOND_ROOM_CEILING_PLANK] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the hallway# has", "une #skulltula de la côte dans le couloir# a", "una Skulltula del océano en el pasillo tiene", "eine #Meer-Skulltula im Flur# hat"}
    );
    hintTable[OSH_SECOND_ROOM_JAR] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the hallway# has", "une #skulltula de la côte dans le couloir# a", "una Skulltula del océano en el pasillo tiene", "eine #Meer-Skulltula im Flur# hat"}
    );
    hintTable[OSH_SECOND_ROOM_WEBBED_HOLE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula behind a hallway web# has", "une #skulltula de la côte derrière une toile du couloir# a", "una Skulltula del océano detrás de las telarañas en el pasillo tiene", "eine #Meer-Skulltula hinter einem Spinnennetz im Flur# hat"}
    );
    hintTable[OSH_SECOND_ROOM_WEBBED_POT] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula behind a hallway web# has", "une #skulltula de la côte derrière une toile du couloir# a", "una Skulltula del océano en el jarrón con telarañas en el pasillo tiene", "eine #Meer-Skulltula hinter einem Spinnennetz im Flur# hat"}
    );
    hintTable[OSH_SECOND_ROOM_UPPER_POT] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the hallway# has", "une #skulltula de la côte dans le couloir# a", "una Skulltula del océano en el jarrón superior del pasillo tiene", "eine #Meer-Skulltula im Flur# hat"}
    );
    hintTable[OSH_SECOND_ROOM_BEHIND_SKULL_1] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the hallway# has", "une #skulltula de la côte dans le couloir# a", "una Skulltula del océano detrás de una máscara en el pasillo tiene", "eine #Meer-Skulltula im Flur# hat"}
    );
    hintTable[OSH_SECOND_ROOM_BEHIND_SKULL_2] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the hallway# has", "une #skulltula de la côte dans le couloir# a", "una Skulltula del océano detrás de una máscara en el pasillo tiene", "eine #Meer-Skulltula im Flur# hat"}
    );
    hintTable[OSH_SECOND_ROOM_LOWER_POT] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the hallway# has", "une #skulltula de la côte dans le couloir# a", "una Skulltula del océano en el jarrón pequeño del pasillo tiene", "eine #Meer-Skulltula im Flur# hat"}
    );
    hintTable[OSH_STORAGE_ROOM_CEILING_WEB] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula behind a storage room web# has", "une #skulltula de la côte derrière une toile du débarras# a", "una Skulltula del océano detrás de las telarañas en el almacén tiene", "eine #Meer-Skulltula hinter einem Spinnennetz im Vorratsraum# hat"}
    );
    hintTable[OSH_STORAGE_ROOM_BEHIND_CRATE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the storage room# has", "une #skulltula de la côte dans le débarras# a", "una Skulltula del océano detrás de la caja en el almacén tiene", "eine #Meer-Skulltula im Vorratsraum# hat"}
    );
    hintTable[OSH_STORAGE_ROOM_WALL] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the storage room# has", "une #skulltula de la côte dans le débarras# a", "una Skulltula del océano en la pared del almacén tiene", "eine #Meer-Skulltula im Vorratsraum# hat"}
    );
    hintTable[OSH_STORAGE_ROOM_CRATE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the storage room# has", "une #skulltula de la côte dans le débarras# a", "una Skulltula del océano dentro de la caja en el almacén tiene", "eine #Meer-Skulltula im Vorratsraum# hat"}
    );
    hintTable[OSH_STORAGE_ROOM_BARREL] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the storage room# has", "une #skulltula de la côte dans le plafond du débarras# a", "una Skulltula del océano dentro del barril en el almacén tiene", "eine #Meer-Skulltula im Vorratsraum# hat"}
    );
    hintTable[OSH_COLORED_SKULLS_CEILING_EDGE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the table room# has", "une #skulltula de la côte dans la salle à manger# a", "una Skulltula del océano andando en el filo del techo en el cuarto de la mesa tiene", "eine #Meer-Skulltula im Tischzimmer# hat"}
    );
    hintTable[OSH_COLORED_SKULLS_CHANDELIER_1] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the table room# has", "une #skulltula de la côte dans la salle à manger# a", "una de las Skulltulas del océano  en el candelabro tiene", "eine #Meer-Skulltula im Tischzimmer# hat"}
    );
    hintTable[OSH_COLORED_SKULLS_CHANDELIER_2] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the table room# has", "une #skulltula de la côte dans la salle à manger# a", "una de las Skulltulas del océano  en el candelabro tiene", "eine #Meer-Skulltula im Tischzimmer# hat"}
    );
    hintTable[OSH_COLORED_SKULLS_CHANDELIER_3] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the table room# has", "une #skulltula de la côte dans la salle à manger# a", "una de las Skulltulas del océano  en el candelabro tiene", "eine #Meer-Skulltula im Tischzimmer# hat"}
    );
    hintTable[OSH_COLORED_SKULLS_BEHIND_PICTURE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the table room# has", "une #skulltula de la côte dans la salle à manger# a", "una Skulltula del océano detrás del cuadro en el cuarto de la mesa tiene", "eine #Meer-Skulltula im Tischzimmer# hat"}
    );
    hintTable[OSH_COLORED_SKULLS_POT] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es", "eine #goldene Spinne# ist"}
        },  //clear
            Text{"an #ocean Skulltula in the table room# has", "une #skulltula de la côte dans la salle à manger# a", "una Skulltula del océano en el jarrón del cuarto de la mesa tiene", "eine #Meer-Skulltula im Tischzimmer# hat"}
    );

    /*----------------------
    |   REGION HINT TEXT   |
    ----------------------*/
    hintTable[LINKS_POCKET] = HintText::Region({Text{"Your Pocket", "tes poches", "", "Links Tasche"}});
    hintTable[N_CLOCK_TOWN] = HintText::Region({Text{"North Clock Town", "Cadranbourg-Nord", "Norte de la Ciudad Reloj", "Nord-Unruh-Stadt", "", "le nord de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_FAIRY_FOUNTAIN] = HintText::Region({Text{"Clock Town’s Fairy Fountain", "la fontaine de fées de Cadranbourg", "Fuente de las hadas de Ciudad Reloj", "Unruh-Stadt-Feen-Quelle", "", "la fontaine de fées de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_DEKU_PLAYGROUND] = HintText::Region({Text{"the Deku Playground", "l'aire de jeux des pestes mojo", "Campo de Juegos Deku", "Deku-Spielplatz"}});
    hintTable[E_CLOCK_TOWN] = HintText::Region({Text{"East Clock Town", "Cadranbourg-Est", "Este de la Ciudad Reloj", "Ost-Unruh-Stadt", "", "l'est de Bourg-Clocher", ""}});
    hintTable[STOCKPOTINN] = HintText::Region({Text{"the Stock Pot Inn", "l’Auberge de la Marmite", "Posada del Puchero", "Gasthof \"Zum Eintopf\"", "", "l'auberge de Bourg-Clocher", ""}});
    hintTable[STOCKPOTINN_GUEST_ROOM] = HintText::Region({Text{"the Stock Pot Inn", "l’Auberge de la Marmite", "Posada del Puchero", "Gasthof \"Zum Eintopf\"", "", "l'auberge de Bourg-Clocher", ""}});
    hintTable[STOCKPOTINN_STAFF_ROOM] = HintText::Region({Text{"the Stock Pot Inn", "l’Auberge de la Marmite", "Posada del Puchero", "Gasthof \"Zum Eintopf\"", "", "l'auberge de Bourg-Clocher", ""}});
    hintTable[STOCKPOTINN_GRANDMA_ROOM] = HintText::Region({Text{"the Stock Pot Inn", "l’Auberge de la Marmite", "Posada del Puchero", "Gasthof \"Zum Eintopf\"", "", "l'auberge de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_OBSERVATORY] = HintText::Region({Text{"the Astral Observatory", "l'observatoire céleste", "Observatorio Astronónico", "Observatorium"}});
    hintTable[CLOCK_TOWN_BAR] = HintText::Region({Text{"the Milk Bar", "le bar laitier", "Bar Lácteo", "Milchbar \"Latte\""}});
    hintTable[CLOCK_TOWN_HONEY_DARLING] = HintText::Region({Text{"East Clock Town", "Cadranbourg-Est", "Este de la Ciudad Reloj", "Ost-Unruh-Stadt", "", "l'est de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_TREASURE_CHEST_GAME] = HintText::Region({Text{"East Clock Town", "Cadranbourg-Est", "Este de la Ciudad Reloj", "Ost-Unruh-Stadt", "", "l'est de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_ARCHERY] = HintText::Region({Text{"East Clock Town", "Cadranbourg-Est", "Este de la Ciudad Reloj", "Ost-Unruh-Stadt", "", "l'est de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_MAYOR_HOUSE] = HintText::Region({Text{"East Clock Town", "Cadranbourg-Est", "Este de la Ciudad Reloj", "Ost-Unruh-Stadt", "", "l'est de Bourg-Clocher", ""}});
    hintTable[W_CLOCK_TOWN] = HintText::Region({Text{"West Clock Town", "Cadranbourg-Ouest", "Oeste de la Ciudad Reloj", "West-Unruh-Stadt", "", "l'ouest de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_SWORDSMANS_SCHOOL] = HintText::Region({Text{"West Clock Town", "Cadranbourg-Ouest", "Oeste de la Ciudad Reloj", "West-Unruh-Stadt", "", "l'ouest de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_POSTMAN_HOUSE] = HintText::Region({Text{"West Clock Town", "Cadranbourg-Ouest", "Oeste de la Ciudad Reloj", "West-Unruh-Stadt", "", "l'ouest de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_LOTTERY] = HintText::Region({Text{"West Clock Town", "Cadranbourg-Ouest", "Oeste de la Ciudad Reloj", "West-Unruh-Stadt", "", "l'ouest de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_BOMB_SHOP] = HintText::Region({Text{"West Clock Town", "Cadranbourg-Ouest", "Oeste de la Ciudad Reloj", "West-Unruh-Stadt", "", "l'ouest de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_TRADING_POST] = HintText::Region({Text{"West Clock Town", "Cadranbourg-Ouest", "Oeste de la Ciudad Reloj", "West-Unruh-Stadt", "", "l'ouest de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_CURIOSITY_SHOP] = HintText::Region({Text{"West Clock Town", "Cadranbourg-Ouest", "Oeste de la Ciudad Reloj", "West-Unruh-Stadt", "", "l'ouest de Bourg-Clocher", ""}});
    hintTable[S_CLOCK_TOWN] = HintText::Region({Text{"South Clock Town", "Cadranbourg-Sud", "Sur de la Ciudad Reloj", "Süd-Unruh-Stadt", "", "le sud de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWER] = HintText::Region({Text{"the Clock Tower", "la tour du cadran", "Torre del Reloj", "Uhrturm", "", "la tour du clocher", ""}});
    hintTable[CLOCK_TOWER_ROOF] = HintText::Region({Text{"the Clock Tower’s Roof", "le toit de la tour du cadran", "Cima de la Torre del Reloj", "Dach des Uhrturms", "", "le toit de la tour du clocher", ""}});
    hintTable[LAUNDRY_POOL] = HintText::Region({Text{"the Laundry Pool", "le lavoir", "Lavadero", "Waschplatz"}});
    hintTable[LAUNDRY_POOL_KAFEI_HIDEOUT] = HintText::Region({Text{"the Laundry Pool", "le lavoir", "Lavadero", "Waschplatz"}});
    hintTable[TERMINA_FIELD] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa", "Ebenen von Termina"}});
    hintTable[TERMINA_FIELD_PEAHAT_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa", "Ebenen von Termina"}});
    hintTable[TERMINA_FIELD_DODONGO_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa", "Ebenen von Termina"}});
    hintTable[TERMINA_FIELD_BIO_BABA_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa", "Ebenen von Termina"}});
    hintTable[TERMINA_FIELD_PILLAR_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa", "Ebenen von Termina"}});
    hintTable[TERMINA_FIELD_GRASS_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa", "Ebenen von Termina"}});
    hintTable[TERMINA_FIELD_BUSINESS_SCRUB_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa", "Ebenen von Termina"}});
    hintTable[TERMINA_FIELD_COW_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa", "Ebenen von Termina"}});
    hintTable[TERMINA_FIELD_GOSSIP_STONES_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa", "Ebenen von Termina"}});
    hintTable[ROAD_TO_SOUTHERN_SWAMP] = HintText::Region({Text{"the Road to Southern Swamp", "la route des marais du Sud", "Camino al Pantano del Sur", "Sumpfweg"}});
    hintTable[ROAD_TO_SOUTHERN_SWAMP_ARCHERY] = HintText::Region({Text{"the Road to Southern Swamp", "la route des marais du Sud", "Camino al Pantano del Sur", "Sumpfweg"}});
    hintTable[ROAD_TO_SWAMP_GROTTO] = HintText::Region({Text{"the Road to Southern Swamp", "la route des marais du Sud", "Camino al Pantano del Sur", "Sumpfweg"}});
    hintTable[SOUTHERN_SWAMP] = HintText::Region({Text{"the Southern Swamp", "les marais du Sud", "Pantano del Sur", "Sümpfe des Vergessens"}});
    hintTable[SWAMP_TOURIST_CENTER] = HintText::Region({Text{"the Southern Swamp", "les marais du Sud", "Pantano del Sur", "Sümpfe des Vergessens"}});
    hintTable[SOUTHERN_SWAMP_HAGS_POTION_SHOP] = HintText::Region({Text{"the Southern Swamp", "les marais du Sud", "Pantano del Sur", "Sümpfe des Vergessens"}});
    hintTable[MYSTERY_WOODS] = HintText::Region({Text{"the Woods of Mystery", "le boisé mystérieux", "Bosque Misterioso", "Wälder der Mysterien", "", "les bois-mystère", ""}});
    hintTable[SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO] = HintText::Region({Text{"the Woods of Mystery", "le boisé mystérieux", "Bosque Misterioso", "Wälder der Mysterien", "", "les bois-mystère", ""}});
    hintTable[SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO] = HintText::Region({Text{"the Southern Swamp", "les marais du Sud", "Pantano del Sur", "Sümpfe des Vergessens"}});
    hintTable[SOUTHERN_SWAMP_TOP] = HintText::Region({Text{"the Southern Swamp", "les marais du Sud", "Pantano del Sur", "Sümpfe des Vergessens"}});
    hintTable[DEKU_PALACE] = HintText::Region({Text{"the Deku Palace", "le palais mojo", "Palacio Deku", "Deku-Palast"}});
    hintTable[DEKU_PALACE_INTERIOR] = HintText::Region({Text{"the Deku Palace", "le palais mojo", "Palacio Deku", "Deku-Palast"}});
    hintTable[DEKU_PALACE_BEAN_GROTTO] = HintText::Region({Text{"the Deku Palace", "le palais mojo", "Palacio Deku", "Deku-Palast"}});
    hintTable[DEKU_SHRINE] = HintText::Region({Text{"the Deku Palace", "le palais mojo", "Palacio Deku", "Deku-Palast"}});
    hintTable[WOODFALL] = HintText::Region({Text{"Woodfall", "Boisé-les-Cascades", "Bosque Catarata", "Dämmerwald", "", "Bois-Cascade", ""}});
    hintTable[WOODFALL_FAIRY_FOUNTAIN] = HintText::Region({Text{"Woodfall’s Fairy Fountain", "la fontaine des fées de Boisé-les-Cascades", "Fuente de las hadas del Bosque Catarata", "Dämmerwald-Feen-Quelle", "", "la fontaine des fées de Bois-Cascade", ""}});
    hintTable[PATH_TO_MOUNTAIN_VILLAGE] = HintText::Region({Text{"the road to Mountain Village", "la route vers le village dans la montagne", "Camino al Pueblo de la Montaña", "Weg zur Bergsiedlung"}});
    hintTable[MOUNTAIN_VILLAGE] = HintText::Region({Text{"the Mountain Village", "le village dans la montagne", "Pueblo de la Montaña", "Bergsiedlung"}});
    hintTable[GORON_GRAVEYARD] = HintText::Region({Text{"the Goron Graveyard", "le cimetière des Gorons", "Cementerio Goron", "Goronen-Grab"}});
    hintTable[MOUNTAIN_SMITHY] = HintText::Region({Text{"the Mountain Village", "le village dans la montagne", "Pueblo de la Montaña", "Bergsiedlung"}});
    hintTable[MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO] = HintText::Region({Text{"the Mountain Village", "le village dans la montagne", "Pueblo de la Montaña", "Bergsiedlung"}});
    hintTable[TWIN_ISLANDS] = HintText::Region({Text{"the road to Goron Village", "la route du village goron", "Islas Gemelas", "Zwillingsinseln"}});
    hintTable[GORON_RACETRACK] = HintText::Region({Text{"the Goron Racetrack", "la course des Gorons", "Circuito de carreras Goron", "Goronen-Rennstrecke"}});
    hintTable[TWIN_ISLANDS_GORON_RACETRACK_GROTTO] = HintText::Region({Text{"the road to Goron Village", "la route du village goron", "Islas Gemelas", "Zwillingsinseln"}});
    hintTable[TWIN_ISLANDS_SPRING_WATER_GROTTO] = HintText::Region({Text{"the road to Goron Village", "la route du village goron", "Islas Gemelas", "Zwillingsinseln"}});
    hintTable[GORON_VILLAGE] = HintText::Region({Text{"the Goron Village", "le village goron", "Aldea Goron", "Goronendorf"}});
    hintTable[GORON_VILLAGE_LENS_CAVE] = HintText::Region({Text{"the Goron Village", "le village goron", "Aldea Goron", "Goronendorf"}});
    hintTable[GORON_VILLAGE_INTERIOR] = HintText::Region({Text{"the Goron Village", "le village goron", "Aldea Goron", "Goronendorf"}});
    hintTable[GORON_VILLAGE_SHOP] = HintText::Region({Text{"the Goron Village", "le village goron", "Aldea Goron", "Goronendorf"}});
    hintTable[ROAD_TO_SNOWHEAD] = HintText::Region({Text{"the road to Snowhead", "la route du Pic des neiges", "Camino al Pico Nevado", "Pic-Hibernia-Weg", "", "la route du pic des Neiges", ""}});
    hintTable[ROAD_TO_SNOWHEAD_GROTTO] = HintText::Region({Text{"the road to Snowhead", "la route du Pic des neiges", "Camino al Pico Nevado", "Pic-Hibernia-Weg", "", "la route du pic des Neiges", ""}});
    hintTable[SNOWHEAD] = HintText::Region({Text{"Snowhead", "le Pic des neiges", "Pico Nevado", "Pic Hibernia", "", "le pic des Neiges", ""}});
    hintTable[SNOWHEAD_FAIRY_FOUNTAIN] = HintText::Region({Text{"Snowhead’s Fairy Fountain", "la fontaine de fées du Pic des neiges", "Fuente de las hadas del Pico Nevado", "Pic-Hibernia-Feen-Quelle", "", "la fontaine de fées du pic des Neiges", ""}});
    hintTable[MILK_ROAD] = HintText::Region({Text{"Milk Road", "la route du lait", "Camino Lácteo", "Milchstraße"}});
    hintTable[GORMAN_TRACK] = HintText::Region({Text{"the Gorman Track", "la piste des Gorman", "Circuito de Gorman", "Rennbahn der Gorman-Brüder"}});
    hintTable[ROMANI_RANCH] = HintText::Region({Text{"Romani Ranch", "le ranch Romani", "Rancho Romani", "Romani-Ranch"}});
    hintTable[DOGGY_RACETRACK] = HintText::Region({Text{"Romani Ranch", "le ranch Romani", "Rancho Romani", "Romani-Ranch"}});
    hintTable[CUCCO_SHACK] = HintText::Region({Text{"Romani Ranch", "le ranch Romani", "Rancho Romani", "Romani-Ranch"}});
    hintTable[ROMANI_RANCH_HOUSE] = HintText::Region({Text{"Romani Ranch", "le ranch Romani", "Rancho Romani", "Romani-Ranch"}});
    hintTable[ROMANI_RANCH_BARN] = HintText::Region({Text{"Romani Ranch", "le ranch Romani", "Rancho Romani", "Romani-Ranch"}});
    hintTable[GREAT_BAY_COAST] = HintText::Region({Text{"Great Bay Coast", "la côte de la Grande Baie", "Costa de la Gran Bahía", "Schädelküste"}});
    hintTable[GREAT_BAY_COAST_MARINE_LAB] = HintText::Region({Text{"Great Bay Coast", "la côte de la Grande Baie", "Costa de la Gran Bahía", "Schädelküste"}});
    hintTable[GREAT_BAY_COAST_GROTTO] = HintText::Region({Text{"Great Bay Coast", "la côte de la Grande Baie", "Costa de la Gran Bahía", "Schädelküste"}});
    hintTable[GREAT_BAY_COAST_COW_GROTTO] = HintText::Region({Text{"Great Bay Coast", "la côte de la Grande Baie", "Costa de la Gran Bahía", "Schädelküste"}});
    hintTable[FISHERMAN_HUT] = HintText::Region({Text{"Great Bay Coast", "la côte de la Grande Baie", "Costa de la Gran Bahía", "Schädelküste"}});
    hintTable[PINNACLE_ROCK] = HintText::Region({Text{"Pinnacle Rock", "le Pic de pierre", "Roca Pináculo", "Nadelfelsen", "", "le puits de pierre", ""}});
    hintTable[ZORA_CAPE] = HintText::Region({Text{"Zora Cape", "le cap des Zoras", "Cabo Zora", "Kap Zora"}});
    hintTable[WATERFALL_RAPIDS] = HintText::Region({Text{"Zora Cape", "le cap des Zoras", "Cabo Zora", "Kap Zora"}});
    hintTable[GREAT_BAY_FAIRY_FOUNTAIN] = HintText::Region({Text{"Zora Cape’s Fairy Fountain", "la fontaine des fées du cap des Zoras", "Fuente de las hadas de la Gran Bahía", "Kap-Zora-Feen-Quelle"}});
    hintTable[ZORA_CAPE_GROTTO] = HintText::Region({Text{"Zora Cape", "le cap des Zoras", "Cabo Zora", "Kap Zora"}});
    hintTable[ZORA_HALL] = HintText::Region({Text{"Zora Hall", "le théâtre des Zoras", "Salón Zora", "Höhle der Zoras"}});
    hintTable[ZORA_HALL_EVANS_ROOM] = HintText::Region({Text{"Zora Hall", "le théâtre des Zoras", "Salón Zora", "Höhle der Zoras"}});
    hintTable[ZORA_HALL_LULUS_ROOM] = HintText::Region({Text{"Zora Hall", "le théâtre des Zoras", "Salón Zora", "Höhle der Zoras"}});
    hintTable[ZORA_HALL_JAPAS_ROOM] = HintText::Region({Text{"Zora Hall", "le théâtre des Zoras", "Salón Zora", "Höhle der Zoras"}});
    hintTable[ZORA_HALL_TIJOS_ROOM] = HintText::Region({Text{"Zora Hall", "le théâtre des Zoras", "Salón Zora", "Höhle der Zoras"}});
    hintTable[ZORA_HALL_SHOP] = HintText::Region({Text{"Zora Hall", "le théâtre des Zoras", "Salón Zora", "Höhle der Zoras"}});
    hintTable[ZORA_HALL_BACK_ENTRANCE] = HintText::Region({Text{"Zora Hall", "le théâtre des Zoras", "Salón Zora", "Höhle der Zoras"}});
    hintTable[ROAD_TO_IKANA] = HintText::Region({Text{"the road to Ikana", "la route d'Ikana", "Camino a Ikana", "Ikana-Weg"}});
    hintTable[ROAD_TO_IKANA_GROTTO] = HintText::Region({Text{"the road to Ikana", "la route d'Ikana", "Camino a Ikana", "Ikana-Weg"}});
    hintTable[IKANA_GRAVEYARD] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana", "Friedhof von Ikana"}});
    hintTable[IKANA_GRAVEYARD_GROTTO] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana", "Friedhof von Ikana"}});
    hintTable[IKANA_GRAVEYARD_BELOW_GRAVE1] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana", "Friedhof von Ikana"}});
    hintTable[IKANA_GRAVEYARD_BATS_ROOM] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana", "Friedhof von Ikana"}});
    hintTable[IKANA_GRAVEYARD_TABLET_ROOM] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana", "Friedhof von Ikana"}});
    hintTable[IKANA_GRAVEYARD_BELOW_GRAVE2] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana", "Friedhof von Ikana"}});
    hintTable[IKANA_GRAVEYARD_PRE_IRON_KNUCKLE_ROOM] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana", "Friedhof von Ikana"}});
    hintTable[IKANA_GRAVEYARD_IRON_KNUCKLE_ROOM] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana", "Friedhof von Ikana"}});
    hintTable[IKANA_GRAVEYARD_BELOW_GRAVE3] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana", "Friedhof von Ikana"}});
    hintTable[DAMPES_HUT] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana", "Friedhof von Ikana"}});
    hintTable[IKANA_CANYON] = HintText::Region({Text{"Ikana Canyon", "le canyon d'Ikana", "Cañón de Ikana", "Ikana-Canyon", "", "la vallée d'Ikana", ""}});
    hintTable[IKANA_CANYON_UPPER] = HintText::Region({Text{"Ikana Canyon", "le canyon d'Ikana", "Cañón de Ikana", "Ikana-Canyon", "", "la vallée d'Ikana", ""}});
    hintTable[IKANA_CANYON_CAVE] = HintText::Region({Text{"Ikana Canyon", "le canyon d'Ikana", "Cañón de Ikana", "Ikana-Canyon", "", "la vallée d'Ikana", ""}});
    hintTable[SAKONS_HIDEOUT] = HintText::Region({Text{"Ikana Canyon", "le canyon d'Ikana", "Cañón de Ikana", "Ikana-Canyon", "", "la vallée d'Ikana", ""}});
    hintTable[MUSIC_BOX_HOUSE] = HintText::Region({Text{"Ikana Canyon", "le canyon d'Ikana", "Cañón de Ikana", "Ikana-Canyon", "", "la vallée d'Ikana", ""}});
    hintTable[IKANA_CANYON_POE_HUT] = HintText::Region({Text{"Ikana Canyon", "le canyon d'Ikana", "Cañón de Ikana", "Ikana-Canyon", "", "la vallée d'Ikana", ""}});
    hintTable[IKANA_CANYON_GREAT_FAIRY_FOUNTAIN] = HintText::Region({Text{"Ikana Canyon’s Fairy Fountain", "la fontaine des fées du canyon d'Ikana", "Fuente de las hadas del Cañón de Ikana", "Ikana-Canyon-Feen-Quelle", "", "la fontaine des fées de la vallée d'Ikana", ""}});
    hintTable[IKANA_CANYON_SECRET_SHRINE_GROTTO] = HintText::Region({Text{"Ikana Canyon", "le canyon d'Ikana", "Cañón de Ikana", "Ikana-Canyon", "", "la vallée d'Ikana", ""}});
    hintTable[STONE_TOWER] = HintText::Region({Text{"Stone Tower", "la forteresse de pierre", "Torre de Piedra", "Felsenturm"}});
    hintTable[INVERTED_STONE_TOWER] = HintText::Region({Text{"Stone Tower", "la forteresse de pierre", "Torre de Piedra", "Felsenturm"}});

    /*---------------------
    |   JUNK HINT TEXT    |
    ---------------------*/
    hintTable[JUNK01] = HintText::Junk({Text{"That's no moon.", "C'est pas une lune, ce truc.", "Esa no es una luna", "Das ist doch kein Mond!"}});
    hintTable[JUNK02] = HintText::Junk({Text{"The moon is haunted.", "La lune est hantée.", "La luna está embrujada", "Wenn Fliegen hinter #Fliegen# fliegen, fliegen #Fliegen# hinter #Fliegen# her!"}});
    hintTable[JUNK03] = HintText::Junk({Text{"Majora has sick dance moves.", "Majora est une bête sur le dance floor.", "Majora baila como Chayanne", "Majora hat krasse Tanz-Moves!"}});
    hintTable[JUNK04] = HintText::Junk({Text{"Making hints is hard.", "C'est dur de faire des indices.", "Hacer pistas es dificil", "Hinweise zu machen ist schon eine schwere Angelegenheit..."}});
    hintTable[JUNK05] = HintText::Junk({Text{"May the way of the Hero lead to the Triforce.", "Que la Triforce guide les pas du héros.", "Que la senda del héroe lleve a la Trifuerza", "Möge der Weg des Helden zur Macht über die Zeit führen."}});
    hintTable[JUNK06] = HintText::Junk({Text{"They say that the final item you're looking for can be found somewhere in Termina.", "Selon moi, l'objet qui t'élude se terre en Termina.", "Dicen que el objeto final que buscas se puede encontrar en algún lado en Termina", "Laut Mythen und Legenden sei dein begehrtes Item irgendwo in Termina."}});
    hintTable[JUNK07] = HintText::Junk({Text{"They say that 85 percent of statistics are made up", "On raconte que 85 pourcent des statistiques sortent de nulle part.", "Dicen que el 85 por ciento de las estadísticas son inventadas", "Es heißt, wenn man ein beschmiertes Brot auf den Rücken einer Katze bindet, kann man fliegen!"}});
    hintTable[JUNK08] = HintText::Junk({Text{"They say the golden dog is picked as the winner most often", "Il paraît que le chien doré gagne plus souvent que les autres.", "Dicen que el perro dorado es seleccionado como el ganador más comunmente", "Golden Hund ist Siegesstund!"}});
    hintTable[JUNK09] = HintText::Junk({Text{"Be patient young grasshopper", "Patience, petit scarabée!&...Pourquoi je ris, cette blague est&nulle! Peut-être dans une autre&langue ça veut dire un truc...", "Tenga paciencia, pequeño grillo", "Hab Geduld, junger Graßhüpfer..."}});
    hintTable[JUNK10] = HintText::Junk({Text{"The Ikana King used to be quite handsome", "Le roi d'Ikana était assez beau gosse, autrefois.", "El Rey de Ikana solía ser muy apuesto", "Der König von Ikana war einst sehr hübsch."}});
    hintTable[JUNK11] = HintText::Junk({Text{"If the Goron Elder is frozen how does he move each day", "L'Ancêtre goron est gelé, non? Comment il fait pour changer de place chaque jour?", "El Anciano Goron está congelado. ¿Como se mueve cada día...?", "Wenn Fliegen... hatten wir den nicht schon einmal?"}});
    hintTable[JUNK12] = HintText::Junk({Text{"The Owl's feathers lead the way", "Les plumes du hibou montrent la voie.", "Las plumas del búho marcan el camino", "Die Federn zeigen den wahren Weg..."}});
    hintTable[JUNK13] = HintText::Junk({Text{"The Happy Mask Salesman doesn't sleep", "Le propriétaire de la foire aux masques ne dors jamais.", "El vendedor de las máscaras no duerme", "Der Maskenhändler hat zu viel Kaffee getrunken."}});
    hintTable[JUNK14] = HintText::Junk({Text{"why do they call it oven when you of in the cold food of out hot eat the food", "Les lave-linges durent plus longtemps avec Ganon! ♪", "Le dicen desayuno porque rompes el ayuno", "Ich kenne einen guten Fahrradwitz, aber ich Fahrrad ihn dir nicht."}});
    hintTable[JUNK15] = HintText::Junk({Text{"It seems Link has difficulties remembering music without the help of a fairy.", "On dirait qu'un @ sans fée n'a aucune mémoire musicale.", "Parece que Link tiene dificultades para recordar música sin ayuda de un hada.", "Es heißt, die Mutter von Anju mag Tiger."}});
    hintTable[JUNK16] = HintText::Junk({Text{"Pickle.", "Cornichon.", "Esperpento.", "Kartoffelsalat."}});
    hintTable[JUNK17] = HintText::Junk({Text{"Why is it called The Legend of Zelda Majora's Mask when Zelda isn't here?", "Si c'est toujours la Légende de Zelda, elle est où Zelda?", "¿Por qué se llama The Legend of Zelda Majora's Mask cuando Zelda no está aquí?", "Wieso heißt das spiel The Legend of Zelda Majora's Mask, wenn Zelda doch gar nicht vorkommt?"}});
    hintTable[JUNK18] = HintText::Junk({Text{"They say you can find the Star Fox cast in your mask inventory screen.", "Il paraît que le casting de Star Fox peut se trouver dans l'inventaire.", "Dicen que puedes encontrar al elenco de Star Fox en tu inventario de máscaras.", "Glitches sind ein Pfad zu mannigfaltigen Fähigkeiten, welche manche von uns für unnatürlich halten."}});
    hintTable[JUNK19] = HintText::Junk({Text{"They say #L# is Real 2401.", "La musique du moulin te dis pas quelque chose? C'est juste moi?", "Dicen que #L# es real 2401", "Du solltest ab und zu eine Pause einlegen. Vielleicht fällt dir die Lösung dann vor die Augen."}});
    hintTable[JUNK20] = HintText::Junk({Text{"They say #The Moon# blinks if you stare long enough", "Il paraît que la lune cligne des yeux si on la regarde assez longtemps.", "Dicen que #La Luna# parpadea si miras lo suficiente", "Wenn man #dem Mond# lang genug in die Augen starrt, wird er verlegen."}});
    hintTable[JUNK21] = HintText::Junk({Text{"They say bunnies have a really good sense of time.", "Il paraît que les lapins ont un bon sens du temps.", "Dicen que los conejos tienen muy buen sentido del tiempo", "Du musst an das Herz der Masken glauben!"}});
    hintTable[JUNK22] = HintText::Junk({Text{"They say this game has a method of infinitely jumping.", "Il paraît qu'on peut sauter indéfiniment si on est assez motivé.", "Dicen que hay un método para saltar infinitamente en este juego", "Es heißt, dass ein Zora mit einer Flasche fliegen kann."}});
    hintTable[JUNK23] = HintText::Junk({Text{"According to all known laws of aviation there is no way a Zora should be able to fly.", "#Sauvegarder# votre progression à-&...Ah, non! Désolé!&&", "Según todas las leyes conocidas de la aviación, es imposible que un Zora pueda volar.", "Hier könnte ihre Werbung stehen."}});
    hintTable[JUNK24] = HintText::Junk({Text{"Why is Zelda green?", "Pourquoi qu'il est vert, Zelda?", "¿Por qué Zelda es verde?", "Hey, @, weißt du nicht weiter?"}});
    hintTable[JUNK25] = HintText::Junk({Text{"Did you know for the first time in 23 years, in 2023 Waluigi didn't star in a game?", "Savais-tu que la première année en 23 ans sans apparition de Waluigi dans un jeu était en 2023?", "¿Sabías que por primera vez en 23 años, Waluigi no protagonizo ningún juego en 2023?", "Liegt ein Auge auf dem Tresen, ist ein Gibdo da gewesen."}});
    hintTable[JUNK26] = HintText::Junk({Text{"Here's a hint, @. Don't be bad.", "Un conseil, @. Soit bon.", "Aquí hay una pista, @. Git gud.", "In der N64 Version konnte man Kafei am ersten Tag mit der Ka-Bumm-Maske verletzen. Jetzt geht das nicht mehr."}});
    hintTable[JUNK27] = HintText::Junk({Text{"They say this randomizer actually took longer to develop than the original Majora's Mask.", "Il paraît que la conception de ce randomiseur fut plus longue que celle du Majora's Mask original.", "Dicen que este randomizer tomó más tiempo de desarrollar que el Majora's Mask original", "Es heißt, dass die Entwicklungszeit für Majora's Mask kürzer war, als die des Randomizers."}});
    hintTable[JUNK28] = HintText::Junk({Text{"They say pirates are allergic to #bees#.", "Il paraît que les pirates sont allergiques aux #abeilles#.", "Dicen que las piratas son alérgicas a las #abejas#", "Man sagt, Piraten hätten Angst vor #Bienen#."}});
    hintTable[JUNK29] = HintText::Junk({Text{"Ocean man, take me by the hand.", "Biggoron pue des pieds.", "Dale, Zelda dale. Pásame la trifuerza que tengo hambre.", "Das ist die perfekte Welle."}});
    hintTable[JUNK30] = HintText::Junk({Text{"Special shoutouts to ennopp who plays piano during this cutscene", "[VOTRE BLAGUE OU RÉFÉRENCE ICI]", "Saludos a ennopp, que toca piano en esta escena", "Ja, ich will... schlafen..."}});
    hintTable[JUNK31] = HintText::Junk({Text{"Did you know it's actually surprisingly easy to mod a 3DS?", "Il paraît que hacker une 3DS est un jeu d'enfant.", "¿Sabías que es sorprendentemente fácil hackear un 3DS?", "... ... ... Wieso redest du mit einem Stein?"}});
    hintTable[JUNK32] = HintText::Junk({Text{"Zora eggs are quite delicious.", "J'adore les œufs de Zora. Surtout avec de la mayo.", "Los huevos zora son una delicia", "Zora-Eier sind sehr lecker!"}});
    hintTable[JUNK33] = HintText::Junk({Text{"Zabora and Gabora have gotten better at making swords that stay sharp.", "Zabora et Gabora forgent des lames bien plus pérennes qu'avant.", "Zubora y Gabora hacen mejores espadas ahora", "I am the Bone of my Deku-Stick"}});
    hintTable[JUNK34] = HintText::Junk({Text{"They say Tacoman369 has never defeated Majora.", "On raconte que Tacoman369 n'a jamais vaincu Majora.", "Dicen que Tacoman369 nunca ha derrotado a Majora.", "Es heißt, Tacoman369 hat nie Majora besiegt. Hat er selbst gesagt!"}});
    hintTable[JUNK35] = HintText::Junk({Text{"L2P @.", "Sois gentil avec les cocottes.", "Aserejé a dejeb", "Hey... Listen..."}});
    hintTable[JUNK36] = HintText::Junk({Text{"They say the #Majora's Mask 3D Randomizer# developers are cool people.", "Ils paraît que les développeurs du #Majora's Mask 3D Randomizer# sont des gens cools.", "Dicen que los desarrolladores de #Majora's Mask 3D Randomizer# son gente cool.", "Die Entwickler des #Majora's Mask 3d Randomizers# sollen töfte Leute sein."}});
    hintTable[JUNK37] = HintText::Junk({Text{"Also try #Ocarina of Time 3D Randomizer#!", "Essayez aussi #Ocarina of Time 3D Randomizer#!", "También prueba el #Ocarina of Time 3D Randomizer#!", "Versuche auch den #Ocarina of Time 3D Randomizer#!"}});
    hintTable[JUNK38] = HintText::Junk({Text{"The single rupee is a unique item.", "Le rubis vert est un objet unique.", "La rupia es única en su tipo", "Der grüne Rubin ist einzigartig..."}});
    hintTable[JUNK39] = HintText::Junk({Text{"Hey, listen!", "Hey! Listen!", "¡Dale, con la silla!", "Watch out!"}});
    hintTable[JUNK40] = HintText::Junk({Text{"They say even the Hero of Time can't help everyone.", "Il paraît que même le Héros du Temps ne peut pas aider tout le monde.", "Dicen que incluso el Héroe del Tiempo no puede ayudar a todos", "@ kann nicht jedem helfen."}});
    hintTable[JUNK41] = HintText::Junk({Text{"The dirt around here tastes really good.", "La terre par ici est délicieuse.", "Dile, que, que... ¡Que coma tierra!", "Die Erde hier schmeckt wirklich gut!"}});
    hintTable[JUNK42] = HintText::Junk({Text{"Talk to me again for the best hint.", "Réessaie pour voir, j'aurai peut-être un meilleur indice.", "Háblame de nuevo para una mejor pista", "Wenn du mich dreißig mal ansprichst, erzähle ich dir den besten Hinweiß!"}});
    hintTable[JUNK43] = HintText::Junk({Text{"They say Gorons discovered a method of space travel.", "Il paraît que les gorons ont découvert une méthode de voyage spatial.", "Dicen que los Goron descubrieron la manera de viajar al espacio", "Es heißt, Goronen sollen einen Weg ins All gefunden haben!"}});
    hintTable[JUNK44] = HintText::Junk({Text{"I AM ERROR", "I AM ERROR", "ALL YOUR BASE ARE BELONG TO US", "I AM ERROR"}});
    hintTable[JUNK45] = HintText::Junk({Text{"Real 3DS ZELDA players use motion controls.", "Les vrais pros jouent avec les capteurs de mouvement.", "Los verdaderos jugadores de ZELDA 3DS usan el Gyro", "I AM BAGGU"}});
    hintTable[JUNK46] = HintText::Junk({Text{"Real ZELDA players use HOLD targeting.", "Régler la visée L sur \"Maintenir\" dans les options est super cool.", "Los verdaderos jugadores de ZELDA usan Mantener para fijar el blanco", "Es heißt, dass Nummer Zwei besser als Nummer Drei ist. Nummer Eins soll hinter her hinken..."}});
    hintTable[JUNK47] = HintText::Junk({Text{"They say items are random...", "Il paraît que les objets sont tout mélangés.", "Dicen que los objetos son aleatorios...", "Findest du die richtigen Items...?"}});
    hintTable[JUNK48] = HintText::Junk({Text{"Dear Mario, please come to the castle. I've baked a cake for you. Yours truly, Princess Toadstool, Peach", "Mon très cher Mario: Viens vite au château, je t'ai préparé un délicieux gâteau...                         À bientôt, &Princesse Toadstool, Peach.", "Lo siento, Mario. ¡Tu princesa está en otro castillo!", "... ... ... Starr mich nicht so an... ich werd noch rot..."}});
    hintTable[JUNK49] = HintText::Junk({Text{"They say the key to victory is beating the game...", "Il paraît que la clé de la victoire est de finir le jeu.", "Un tip: Para ganar, acaba el juego", "D45 M3N5L1CH3 G3H1RN 15T 53HR 5CHL4U"}});
    hintTable[JUNK50] = HintText::Junk({Text{"They say the gold dog cheats.", "Selon moi, le chien doré est un sale tricheur.", "El perro dorado es un tramposo", "Der blaue Hund soll immer gewinnen, wenn man vorher Romani ein super geheimes Item gibt!"}});
    hintTable[JUNK51] = HintText::Junk({Text{"They say @ drowned.", "Comment on débloque le masque de Mario?", "Dicen que @ se ahogó", "Es heißt, @ sei ertrunken."}});
    hintTable[JUNK52] = HintText::Junk({Text{"Goodbye then.", "OK, à plus.", "Adiosito", "Dann halt nicht."}});
    hintTable[JUNK53] = HintText::Junk({Text{"You've met with a terrible hint, haven't you?", "Jeune garçon, tu es confronté a un terrible indice, n'est-ce pas?", "Te has encontrado con una pista terrible, no es así?", "Du erlagst einem schrecklichen Schicksal, nicht wahr?"}});
    hintTable[JUNK54] = HintText::Junk({Text{"I'm stoned. Get it?", "Ces histoires me laissent de marbre.&...Hahah...", "Me dicen Pedro. ¿Lo entiendes?", "Bitte steinige mich nicht. Checkste?"}});
    hintTable[JUNK55] = HintText::Junk({Text{"One who doesn't have all the masks will not get a #special reward#", "Seuls ceux qui détiennent tout les masques recevront une #récompense spéciale#.", "Quien no tenga todas las máscaras no recibirá una #super duper recompensa#.", "#I sing for you.#"}});
    hintTable[JUNK56] = HintText::Junk({Text{"They say the #blue dog# will win a race some day...", "Il paraît que le #chien bleu# a déjà gagné une course.", "Algún día el perro azul ganará la carrera....", "Sei ein Fels!"}});
    hintTable[JUNK57] = HintText::Junk({Text{"Remember to check your 3DS battery level and save often.", "Pense bien à garder le console chargée et sauvegarder souvent.", "Recuerda revisar la batería de tu 3DS y guardar seguido", "Vergiss nicht, gelegentlich eine Pause einzulegen."}});
    hintTable[JUNK58] = HintText::Junk({Text{"Just be a rock.", "#Atchoum!#", "Beep boop, soy un robot", "Vergiss nicht, gelegentlich zu speichern und die Batterie deines 3DS aufzuladen."}});
    hintTable[JUNK59] = HintText::Junk({Text{"I can't feel my legs!", "Je sens pas mes jambes!", "¡No puedo sentir mis piernas!", "Ich war einst wie du ein Abenteurer. Doch dann steckte ein Pfeil in mein Knie."}});
    hintTable[JUNK60] = HintText::Junk({Text{"What are you staring at?", "Tu veux ma photo?", "¿Qué me ves?", "... Was glotzt du so?"}});
    hintTable[JUNK61] = HintText::Junk({Text{"Glitches are a pathway to many abilities some consider to be... Unnatural.", "Les cartes sont assez abordables, non?&Je m'attendais à pire en voyant le vendeur.", "Haz un par de maromas o algo.", "#Tingle Tingle Meer und Sand, lies die Karte in meiner Hand!#"}});
    hintTable[JUNK62] = HintText::Junk({Text{"You ever just feel like smashing that $ button?", "Appuyer sur $ fait grimper plus vite.", "¡Apachúrrale starp!", "Ich bin eine Biene!"}});
    hintTable[JUNK63] = HintText::Junk({Text{"I think the Mask of Truth has it's uses!", "Il paraît que le masque de vérité a des effets #secrets#.", "Dicen que la Máscara de la verdad tiene usos", "\"Du kannst nicht vorbei! Kehr zurück in die Schatten!\" Warte... ich soll das nicht sagen, das wird sonst zu teuer..."}});
    hintTable[JUNK64] = HintText::Junk({Text{"There's a lot of eyes here, isn't there?", "Ça en fait des yeux, dis-donc.", "Hay demasiados ojos aquí, ¿no crees?", "Es gibt schon viele Augen hier, nicht wahr?"}});
    hintTable[JUNK65] = HintText::Junk({Text{"I think that #large object in the sky# hasn't moved in a few days.", "Ce #gros machin# dans le ciel n'a plus bougé depuis quelque jours, si?", "Mi novia se convirtió en la luna", "Ich glaube das #große Ding im Himmel# hat sich für eine Weile nicht mehr bewegt."}});
    hintTable[JUNK66] = HintText::Junk({Text{"Watch out for that #large object in the sky!#", "Le #ciel# nous tombe sur la tête!!", "Cuidado con la cabeza", "Achte auf das #große Ding im Himmel!#"}});
    hintTable[JUNK67] = HintText::Junk({Text{"#Tingle Tingle Kooloo Limpah!#", "#Tingle Tingle Kooloolin... Pah!#", "Dicen que Ganondorf iba a ser un pescador en Términa", "Wenn man so darüber nachdenkt, ist Termina ein komisches Land."}});
    hintTable[JUNK68] = HintText::Junk({Text{"They say if you have three specific items, you can zoom across Termina.", "Il parait qu'on peut tracer à travers Termina avec trois objets précis.", "Dicen que con tres objetos específicos, puedes dispararte por Términa", "Drei Relikte sind nötig, im die Macht der Geschwindigkeit und die Macht des Fluges zu erlangen!"}});
    hintTable[JUNK69] = HintText::Junk({Text{"They say the powder keg can remain fairly elusive.", "Il paraît que le baril de poudre peut s'avérer assez élusif.", "Dicen que el Barril de Pólvora puede ser dificil de encontrar", "Leb deinen Traum, denn er wird wahr."}});
    hintTable[JUNK70] = HintText::Junk({Text{"It's pretty cold here, would you mind warming me up, @?", "Fais frisquet dites-moi... N'auriez vous point de quoi me réchauffer, messire?", "¡Prepárense para los problemas, y mas vale que teman!", "Es ist schon echt kalt hier... Hey, @. Warum wärmen wir uns nicht einander auf?"}});
    hintTable[JUNK71] = HintText::Junk({Text{"These hints can be quite useful. This is an exception.", "Il paraît que ces indices peuvent s'avérer utiles.&Celui-ci n'en est pas la preuve.", "Freezer mintió cuando dijo que Namekuseí explotará en 5 minutos", "Hinweise sind schon nützlich... Ausnahmen bestätigen die Regeln!"}});
    hintTable[JUNK72] = HintText::Junk({Text{"Turns are more effective when you tilt the whole console.", "Pencher la console aide à négocier les virages serrés. Si si, j'te jure!", "Caminar hacia atrás es más efectivo que rodar", "Wenn du den B-Knopf stärker drückst, ist dein Angriff stärker!"}});
    hintTable[JUNK73] = HintText::Junk({Text{"You ever been in a cockpit before?", "Je m'demande ce que Ganon est en train de faire!", "Si te ataco con un diccionario, ¿se considera agresión física o verbal?", "Marco."}});
    hintTable[JUNK74] = HintText::Junk({Text{"It's a secret to everybody", "Il est écrit: Seul Link peut vaincre Ganon.", "¡NOOOO! ¡TORITO!", "Polo."}});
    hintTable[JUNK75] = HintText::Junk({Text{"You found me!", "Nom d'un caillou! Tu m'as trouvé!", "¡Tenía que ser el chavo del ocho!", "Du hast mich gefunden!"}});
    hintTable[JUNK76] = HintText::Junk({Text{"I have it on my post-it note somewhere.", "Ah oui, ton indice! Attends, je crois bien l'avoir mis quelque part...", "¡Hola! Me has atrapado medio #SUAVEMENTE#.", "Ich habs mir irgendwo aufgeschrieben..."}});
    hintTable[JUNK77] = HintText::Junk({Text{"Follow the rainbow.", "Laisssse-moi!&Laisssse-moi!&&Laisssse-moitranquille!", "Sigue el arcoíris", "Folge dem Regenbogen!"}});

    /*------------------------
    |   DUNGEON HINT TEXT    |
    ------------------------*/
    hintTable[WOODFALL_TEMPLE] = HintText::DungeonName({
            //obscure
            Text{"the sleeping temple", "le temple endormi", "el templo durmiente", "der schlafende Tempel"}
        },  //clear
            Text{"the Woodfall Temple", "le temple de Boisé-les-Cascades", "el Templo del Bosque Catarata", "den Dämmerwald-Tempel", "", "le temple de Bois-Cascade", ""}
    );
    hintTable[SNOWHEAD_TEMPLE] = HintText::DungeonName({
            //obscure
            Text{"an icy temple", "un temple glacé", "el templo helado", "ein eisiger Tempel"}
        },  //clear
            Text{"the Snowhead Temple", "le temple du Pic des neiges", "el Templo del Pico Nevado", "den Pic-Hibernia-Tempel", "", "le temple du pic des Neiges", ""}
    );
    hintTable[GREAT_BAY_TEMPLE] = HintText::DungeonName({
            //obscure
            Text{"the murky watered temple", "le temple en eaux troubles", "el templo de aguas turbias", "der Tempel im trüben Wasser"}
        },  //clear
            Text{"the Great Bay Temple", "le temple de la Grande Baie", "el Templo de la Gran Bahía", "den Schädelbucht-Tempel"}
    );
    hintTable[STONE_TOWER_TEMPLE] = HintText::DungeonName({
            //obscure
            Text{"a rocky temple", "un temple sens dessus dessous", "el templo rocoso", "ein steinerner Tempel"}
        },  //clear
            Text{"the Stone Tower Temple", "le temple de la forteresse de pierre", "el Templo de la Torre de Piedra", "den Felsenturm-Tempel"}
    );
    hintTable[PIRATE_FORTRESS] = HintText::DungeonName({
            //obscure
            Text{"the home of pirates", "le foyer des pirates", "el hogar de las piratas", "die Heimat der Piraten"}
        },  //clear
            Text{"the Pirates' Fortress", "la forteresse des pirates", "la Fortaleza Pirata", "die Piratenfestung"}
    );
    hintTable[BENEATH_THE_WELL] = HintText::DungeonName({
            //obscure
            Text{"an empty watering hole", "un abreuvoir vide", "un abrevadero en sequía", "ein ausgetrocknetes Wasserloch"}
        },  //clear
            Text{"Beneath the Well", "le fond du puits", "Bajo el Pozo", "den Untergrund des Brunnens"}
    );
    hintTable[IKANA_CASTLE] = HintText::DungeonName({
            //obscure
            Text{"a fallen castle", "un château déchu", "un castillo rendido", "ein gefallenes Schloss"}
        },  //clear
            Text{"the Ancient Castle of Ikana", "les vestiges du château d'Ikana", "el Antiguo Castillo de Ikana", "das antike Schloss von Ikana"}
    );
    hintTable[SECRET_SHRINE] = HintText::DungeonName({
            //obscure
            Text{"a mini boss run area", "une zone à mini boss", "donde se congregan los jefes menores", "ein Gebiet für Zwischenbosse"}
        },  //clear
            Text{"the Secret Shrine", "le sanctuaire secret", "el Santuario Secreto", "den geheimen Schrein"}
    );
    hintTable[SSH] = HintText::DungeonName({
            //obscure
            Text{"a home to muddy spiders", "un nid puant d'araignées", "un hogar para arañas lodosas", "ein Zuhause für schlammige Spinnen"}
        },  //clear
            Text{"the Swamp Spider House", "la maison des araignées des marais", "la Casa de las Arañas del Pantano", "das Sumpf-Spinnenhaus"}
    );
    hintTable[OSH] = HintText::DungeonName({
            //obscure
            Text{"a home To swimming spiders", "un nid poussiéreux d'araignées", "un hogar para arañas nadadoras", "ein Zuhause für schwimmende Spinnen"}
        },  //clear
            Text{"the Ocean Spider House", "la maison des araignées de la côte", "la Casa de las Arañas de la Playa", "das Meer-Spinnenhaus"}
    );
    hintTable[THE_MOON] = HintText::DungeonName({
            //obscure
            Text{"a dungeon out of this world", "un donjon d'un autre monde", "un calabozo fuera de éste mundo", "ein Verlies aus einer anderen Welt"}
        },  //clear
            Text{"the Moon", "la lune", "la Luna", "den Mond"}
    );

    /*-----------------------
    |    BOSS HINT TEXT     |
    -----------------------*/
    hintTable[ODOLWA] = HintText::Boss({
            //obscure
            Text{"a #masked jungle warrior# holds", "un #guerrier de la jungle masqué# détient", "un guerrero salvaje enmascarado", "ein #maskierter Urwald-Krieger# hält"}
        },  //clear
            Text{"#Odolwa# holds", "#Odolwa# détient", "Odolwa", "#Odolwa# hält"}
    );
    hintTable[GOHT] = HintText::Boss({
            //obscure
            Text{"a #masked mechanical monster# holds", "une #chimère mécanique masquée# détient", "un monstruo mecánico enmascarado", "ein #maskiertes Maschinen-Monster# hält"}
        },  //clear
            Text{"#Goht# holds", "#Rhork# détient", "Goht", "#Goht# hält"}
    );
    hintTable[GYORG] = HintText::Boss({
            //obscure
            Text{"a #gargantuan masked fish# holds", "un #léviathan gargantuesque masqué# détient", "un pez colosal enmascarado", "ein #riesiger maskierter Fisch# hält"}
        },  //clear
            Text{"#Gyorg# holds", "#Gyorg# détient", "Gyorg", "#Gyorg# hält"}
    );
    hintTable[TWINMOLD] = HintText::Boss({
            //obscure
            Text{"a #giant masked insect# holds", "un #double insecte géant masqué# détient", "un insecto gigante enmascarado", "ein #gigantisches maskiertes Insekt# hält"}
        },  //clear
            Text{"#Twinmold# holds", "#Skorn# détient", "Twinmold", "#Twinmold# hält"}
    );
    hintTable[MAJORA] = HintText::Boss({
            //obscure
            Text{"a #cursed mask# holds", "un #masque maléfique# détient", "una máscara maldita", "eine #verfluchte Maske# hält"}
        },  //clear
            Text{"#Majora's Mask# holds", "Le #masque de Majora# détient", "la Máscara de Majora", "#Majoras Maske# hält"}
    );


}

const HintText& Hint(const HintKey hintKey) {
    return hintTable[hintKey];
}

std::vector<HintText> GetHintCategory(HintCategory category) {

    std::vector<HintText> hintsInCategory = {};

    for (const auto& hint : hintTable) {
        if (hint.GetType() == category) {
            hintsInCategory.push_back(hint);
        }
    }
    return hintsInCategory;
}
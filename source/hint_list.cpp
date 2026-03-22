#include "hint_list.hpp"
//#include "custom_messages.hpp"

#include <array>

//using namespace CustomMessages;

static std::array<HintText, KEY_ENUM_MAX> hintTable;

void HintTable_Init() {
    /*--------------------------
    |       GENERAL TEXT       |
    --------------------------*/
    hintTable[NONE]            = HintText::Exclude({Text{"No Hint",                     "INDICE MANQUANT",              ""}});
    hintTable[PREFIX]          = HintText::Exclude({Text{"They say that ",              "Selon moi, ",                  "Según dicen, "}});
    hintTable[WAY_OF_THE_HERO] = HintText::Exclude({Text{" is on the way of the hero.", " est sur le chemin du héros.", " está en la senda del héroe."}});
    hintTable[PLUNDERING]      = HintText::Exclude({Text{"plundering ",                 "explorer ",                    "inspeccionar "}});
    hintTable[FOOLISH]         = HintText::Exclude({Text{" is a foolish choice.",       " est futile.",                 " es una mala decisión."}});
    hintTable[CAN_BE_FOUND_AT] = HintText::Exclude({Text{"can be found at",             "se trouve dans",               "se encuentra en"}});
    hintTable[HOARDS]          = HintText::Exclude({Text{"hoards",                      "recèle",                       "atesora"}});

    //hintTable[ITEM] = HintText::Item({Text{"English", "French", "Spanish"}});
    /*--------------------------
    |        ITEM HINTS        |
    --------------------------*/
    hintTable[KOKIRI_SWORD] = HintText::Item({
            //obscure
            Text{"a forest blade", "une lame sylvestre", "acero del bosque"}
        },  //clear
            Text{"the Kokiri Sword", "l'épée Kokiri", "la Espada Kokiri"}
    );
    hintTable[RAZOR_SWORD] = HintText::Item({
            //obscure
            Text{"a sharp blade", "une lame aiguisée", "acero tajante"}
        },  //clear
            Text{"the Razor Sword", "la lame rasoir", "la Espada Afilada"}
    );
    hintTable[GILDED_SWORD] = HintText::Item({
            //obscure
            Text{"a very sharp blade", "une lame aiguisée deux fois", "acero súper tajante"}
        },  //clear
            Text{"the Gilded Sword", "la lame dorée", "la Espada de Esmeril"}
    );
    hintTable[GREAT_FAIRYS_SWORD] = HintText::Item({
            //obscure
            Text{"A powerful fairy blade", "une lame féerique", "el poderoso acero de las hadas"}
        },  //clear
            Text{"the Great Fairy's Sword", "l'épée de la grande fée", "la Espada de la Gran Hada", "", "la grande épée des fées", ""}
    );
    hintTable[HEROS_SHIELD] = HintText::Item({
            //obscure
            Text{"a basic shield", "un bouclier basique", "un blasón básico"}
        },  //clear
            Text{"a Hero's Shield", "le bouclier du Héros", "el Escudo del Héroe"}
    );
    hintTable[MIRROR_SHIELD] = HintText::Item({
            //obscure
            Text{"a reflective shield", "un bouclier réfléchissant", "un blasón lustroso"}
        },  //clear
            Text{"the Mirror Shield", "le bouclier miroir", "el Escudo Espejo"}
    );
    hintTable[DEKU_STICK] = HintText::Item({
            //obscure
            Text{"a flammable weapon", "une arme inflammable", "un arma flamable"}
        },  //clear
            Text{"a Deku Stick", "un bâton mojo", "un palo Deku"}
    );
    hintTable[LAND_TITLE] = HintText::Item({
            //obscure
            Text{"a property deal", "un accord immobilier", "una escritura de propiedad"}
        },  //clear
            Text{"a Land Title Deed", "un titre de terre", "una Escritura de propiedad de la Ciudad"}
    );
    hintTable[SWAMP_TITLE] = HintText::Item({
            //obscure
            Text{"a property deal", "un accord immobilier", "una escritura de propiedad"}
        },  //clear
            Text{"a Swamp Title Deed", "un titre de marais", "una Escritura de propiedad del Pantano"}
    );
    hintTable[MOUNTAIN_TITLE] = HintText::Item({
            //obscure
            Text{"a property deal", "un accord immobilier", "una escritura de propiedad"}
        },  //clear
            Text{"a Mountain Title Deed", "un titre de montagne", "una Escritura de propiedad de la Montañaa"}
    );
    hintTable[OCEAN_TITLE] = HintText::Item({
            //obscure
            Text{"a property deal", "un accord immobilier", "una escritura de propiedad"}
        },  //clear
            Text{"an Ocean Title Deed", "un titre d'océan", "una Escritura de propiedad del Océano"}
    );
    hintTable[BOMBERS_NOTEBOOK] = HintText::Item({
            //obscure
            Text{"a handy notepad", "un cahier pratique", "una útil libreta"}
        },  //clear
            Text{"the Bombers' Notebook", "le carnet des Bombers", "el Cuaderno de los Bomber", "", "le journal des Bombers", ""}
    );
    hintTable[ROOM_KEY] = HintText::Item({
            //obscure
            Text{"a hotel door opener", "un croche-porte hôtelier", "una llave de hotel"}
        },  //clear
            Text{"a Room Key", "une clé de chambre", "una Llave del cuarto"}
    );
    hintTable[LETTER_KAFEI] = HintText::Item({
            //obscure
            Text{"a lover's letter", "une lettre de dulcinée", "una carta de un amante"}
        },  //clear
            Text{"the Letter to Kafei", "la lettre pour Kafei", "la Carta a Kafei"}
    );
    hintTable[PENDANT_MEMORIES] = HintText::Item({
            //obscure
            Text{"a cherished necklace", "un collier chéri", "un preciado collar"}
        },  //clear
            Text{"the Pendant of Memories", "le pendentif des amoureux", "el Colgante de recuerdos"}
    );
    hintTable[LETTER_MAMA] = HintText::Item({
            //obscure
            Text{"A special delivery", "une livraison spéciale", "una entrega especial"}
        },  //clear
            Text{"the Letter to Mama", "la lettre express pour Maman", "la Entrega especial a mamá", "", "la lettre express pour maman", ""}
    );
    hintTable[MOONS_TEAR] = HintText::Item({
            //obscure
            Text{"a lunar teardrop", "un suintement lunaire", "una gota astral"}
        },  //clear
            Text{"a Moon's Tear", "une larme de lune", "la Lágrima de luna"}
    );
    hintTable[SPIN_ATTACK] = HintText::Item({
            //obscure
            Text{"a magic attack", "un cercle agrandi", "un ataque mágico"}
        },  //clear
            Text{"the mastered Spin Attack", "l'attaque circulaire perfectionnée", "el Ataque giratorio"}
    );
    hintTable[LENS_OF_TRUTH] = HintText::Item({
            //obscure
            Text{"a lie detector", "un perce-mensonge", "un detector de mentiras"}
        },  //clear
            Text{"the Lens of Truth", "la loupe de vérité", "la Lupa de la Verdad", "", "le monocle de vérité", ""}
    );
    hintTable[HEROS_BOW] = HintText::Item({
            //obscure
            Text{"a bow", "un bâton affublé d'une corde", "un lanzador de dardos"}
        },  //clear
            Text{"the Hero's Bow", "l'arc du Héros", "el Arco del héroe"}
    );
    hintTable[FIRE_ARROWS] = HintText::Item({
            //obscure
            Text{"the power of fire", "la pyromanie", "el poder del fuego"}
        },  //clear
            Text{"the Fire Arrow", "la flèche de feu", "la Flecha de fuego"}
    );
    hintTable[ICE_ARROWS] = HintText::Item({
            //obscure
            Text{"the power of ice", "une pompe à chaleur", "el poder del hielo"}
        },  //clear
            Text{"the Ice Arrow", "la flèche de glace", "la Flecha de hielo"}
    );
    hintTable[LIGHT_ARROWS] = HintText::Item({
            //obscure
            Text{"the power of light", "la lumière", "el poder de la luz"}
        },  //clear
            Text{"the Light Arrow", "la flèche de lumière", "la Flecha de luz"}
    );
    hintTable[HOOKSHOT] = HintText::Item({
            //obscure
            Text{"a chain and grapple", "une force de traction", "una cadena con pico"}
        },  //clear
            Text{"the Hookshot", "le grappin", "el Gancho"}
    );
    hintTable[MAGIC_BEAN] = HintText::Item({
            //obscure
            Text{"a plant seed", "un plancher en devenir", "una semilla peculiar"}
        },  //clear
            Text{"a Magic Bean", "un haricot magique", "una habichuela mágica"}
    );
    hintTable[MAGIC_BEAN_PACK] = HintText::Item({
            //obscure
            Text{"multiple plant seeds", "un sac de munitions de jardin", "varias semillas peculiares"}
        },  //clear
            Text{"a pack of Magic Beans", "un paquet de haricots magiques", "un lote de habichuelas mágicas"}
    );
    hintTable[DOUBLE_DEFENSE] = HintText::Item({
            //obscure
            Text{"magical defence", "la peau dure", "defensa mágica"}
        },  //clear
            Text{"Double Defense", "la résistance double", "Poder defensivo doble"}
    );
    hintTable[OCARINA_OF_TIME] = HintText::Item({
            //obscure
            Text{"a musical instrument", "un instrument de musique", ""}
        },  //clear
            Text{"the Ocarina of Time", "l'ocarina du temps", ""}
    );
    hintTable[PICTOGRAPH_BOX] = HintText::Item({
            //obscure
            Text{"a capture device", "une chambre obscure", "un dispositivo de capturas"}
        },  //clear
            Text{"the Picto Box", "la boîte à image", "la Caja Luminográfica"}
    );
    hintTable[POWDER_KEG] = HintText::Item({
            //obscure
            Text{"an explosive barrel", "un baril explosif", "un barril explosivo"}
        },  //clear
            Text{"a Powder Keg", "un baril de poudre", "el Barril de Pólvora"}
    );
    hintTable[KEATON_MASK] = HintText::Item({
            //obscure
            Text{"a popular mask", "un masque populaire", "una máscara popular"}
        },  //clear
            Text{"the Keaton Mask", "le masque de keaton", "la Máscara keaton", "", "le masque de renard", ""}
    );
    hintTable[BUNNY_HOOD] = HintText::Item({
            //obscure
            Text{"the ears of the wild", "des zoulies noreilles toutes duveteuses", "las orejas salvajes"}
        },  //clear
            Text{"the Bunny Hood", "la capuchon de lapin", "la Capucha de conejo", "", "le masque de lapin", ""}
    );
    hintTable[GORON_MASK] = HintText::Item({
            //obscure
            Text{"a mountain spirit", "une âme montagnarde", "un espíritu de la montaña"}
        },  //clear
            Text{"the Goron Mask", "le masque goron", "la Máscara Goron"}
    );
    hintTable[ZORA_MASK] = HintText::Item({
            //obscure
            Text{"an ocean spirit", "une âme musicienne", "un espíritu del océano"}
        },  //clear
            Text{"the Zora Mask", "le masque zora", "la Máscara Zora"}
    );
    hintTable[DEKU_MASK] = HintText::Item({
            //obscure
            Text{"a forest spirit", "une âme sylvestre", "un espíritu del bosque"}
        },  //clear
            Text{"the Deku Mask", "le masque mojo", "la Máscara Deku"}
    );
    hintTable[POSTMANS_HAT] = HintText::Item({
            //obscure
            Text{"a hard worker's hat", "l'uniforme d'un homme pressé", "el gorro de un trabajador dedicado"}
        },  //clear
            Text{"the Postman's Hat", "la casquette du facteur", "la Gorra de cartero"}
    );
    hintTable[ALL_NIGHT_MASK] = HintText::Item({
            //obscure
            Text{"insomnia", "un crise d'insomnie", "el insomnio"}
        },  //clear
            Text{"the All-Night Mask", "le masque de la nuit blanche", "la Máscara para trasnochar"}
    );
    hintTable[BLAST_MASK] = HintText::Item({
            //obscure
            Text{"a dangerous mask", "un masque dangereux", "una máscara peligrosa"}
        },  //clear
            Text{"the Blast Mask", "le masque explosif", "la Máscara explosiva", "", "le masque d'explosion", ""}
    );
    hintTable[STONE_MASK] = HintText::Item({
            //obscure
            Text{"inconspicousness", "la discrétion", "discreción"}
        },  //clear
            Text{"the Stone Mask", "le masque de pierre", "la Máscara de piedra", "", "le masque de la pierre", ""}
    );
    hintTable[GREAT_FAIRYS_MASK] = HintText::Item({
            //obscure
            Text{"a friend of fairies", "un aimant à fées", "la amistad de las hadas"}
        },  //clear
            Text{"the Great Fairy's Mask", "le masque de la grande fée", "la Máscara de la Gran Hada", "", "le masque des grandes fées", ""}
    );
    hintTable[BREMEN_MASK] = HintText::Item({
            //obscure
            Text{"a bird's mask", "un bec de piaf", "una máscara aviar"}
        },  //clear
            Text{"the Bremen Mask", "le masque de Brême", "la Máscara de Bremen"}
    );
    hintTable[DON_GEROS_MASK] = HintText::Item({
            //obscure
            Text{"a conductor's mask", "un masque de chef d'orchestre", "la máscara de un director"}
        },  //clear
            Text{"Don Gero's Mask", "le masque de Don Gero", "la Máscara de Don Gero"}
    );
    hintTable[MASK_OF_SCENTS] = HintText::Item({
            //obscure
            Text{"a pig's mask", "un nez sensible", "el olor a victoria"}
        },  //clear
            Text{"the Mask of Scents", "le masque des parfums", "la Máscara de aromas"}
    );
    hintTable[ROMANIS_MASK] = HintText::Item({
            //obscure
            Text{"a cow's mask", "une carte de membre", "una prueba de madurez"}
        },  //clear
            Text{"Romani's Mask", "le masque Romani", "la Máscara de Romani"}
    );
    hintTable[CIRCUS_LEADERS_MASK] = HintText::Item({
            //obscure
            Text{"a mask of sadness", "un masque dégoulinant", "un símbolo de melancolía"}
        },  //clear
            Text{"the Troupe Leader's Mask", "le masque du chef de la troupe", "la Máscara del jefe de la compañía"}
    );
    hintTable[KAFEIS_MASK] = HintText::Item({
            //obscure
            Text{"the mask of a missing one", "un portrait robot", "la cara de alguien extraviado"}
        },  //clear
            Text{"Kafei's Mask", "le masque de Kafei", "la Máscara de Kafei"}
    );
    hintTable[COUPLES_MASK] = HintText::Item({
            //obscure
            Text{"the mark of a couple", "un serment d'amour", "la marca de una pareja"}
        },  //clear
            Text{"the Couple's Mask", "le masque des amoureux", "la Máscara de los novios"}
    );
    hintTable[KAMAROS_MASK] = HintText::Item({
            //obscure
            Text{"dance moves", "un cours de danse", "unos buenos pasos de baile"}
        },  //clear
            Text{"Kamaro's Mask", "le masque de Kamaro", "la Máscara de Kamaro"}
    );
    hintTable[GIBDOS_MASK] = HintText::Item({
            //obscure
            Text{"a mask of monsters", "un visage hideux", "una fachada monstruosa"}
        },  //clear
            Text{"the Gibdo Mask", "le masque de gibdo", "la Máscara de Gibdo"}
    );
    hintTable[GAROS_MASK] = HintText::Item({
            //obscure
            Text{"the mask of spies", "une cagoule d'espion", "el símbolo de espionaje"}
        },  //clear
            Text{"Garo's Mask", "la cagoule garo", "la Máscara de Garo"}
    );
    hintTable[CAPTAINS_HAT] = HintText::Item({
            //obscure
            Text{"a commanding presence", "l'autorité sur une armée", "una presencia imponente"}
        },  //clear
            Text{"the Captain's Hat", "le heaume du capitaine", "la Casco del capitán"}
    );
    hintTable[GIANTS_MASK] = HintText::Item({
            //obscure
            Text{"a growth spur", "une poussée de croissance", "un súbito crecimiento"}
        },  //clear
            Text{"the Giant's Mask", "le masque du géant", "la Máscara del gigante"}
    );
    hintTable[FIERCE_DEITY_MASK] = HintText::Item({
            //obscure
            Text{"the wrath of a god", "une colère divine", "la ira divina"}
        },  //clear
            Text{"the Fierce Deity's Mask", "le masque du mauvais génie", "la Máscara de la Fiera Deidad", "", "le masque du Dieu Démon", ""}
    );
    hintTable[MASK_OF_TRUTH] = HintText::Item({
            //obscure
            Text{"a piercing gaze", "un masque interprète", "una mirada penetrante"}
        },  //clear
            Text{"the Mask of Truth", "le masque de vérité", "la Máscara de la verdad"}
    );
    hintTable[FISHING_PASS] = HintText::Item({
            //obscure
            Text{"a fishing pass", "un papier sans utilité", "un cupón de pesca"}
        },  //clear
            Text{"a Fishing Pass", "un billet de pêche", "una entrada de la zona de pesca", "", "un ticket de pêche", ""}
    );
    hintTable[ICE_TRAP] = HintText::Item({
            //obscure
            Text{"a frosty surprise", "un coup de froid", "una gélida sorpresa"}
        },  //clear
            Text{"an Ice Trap", "un piège de glace", "una trampa de hielo"}
    );
    hintTable[ZORA_EGG] = HintText::Item({
            //obscure
            Text{"a zora egg", "une progéniture dérobée", "un huevo Zora"}
        },  //clear
            Text{"a Zora Egg", "un œuf de Zora", "un Huevo Zora"}
    );
//SKULLTULA TOKENS
    hintTable[SWAMP_SKULLTULA_TOKEN] = HintText::Item({
            //obscure
            Text{"a golden token", "une fraction de malédiction", "un símbolo dorado"}
        },  //clear
            Text{"a Swamp Skulltula Token", "une âme de skulltula d'or des marais", "un símbolo de Skulltula del Pantano"}
    );
    hintTable[OCEANSIDE_SKULLTULA_TOKEN] = HintText::Item({
            //obscure
            Text{"a golden token", "une fraction de nettoyage", "un símbolo dorado"}
        },  //clear
            Text{"an Oceanside Skulltula Token", "une âme de skulltula d'or de la côte", "un símbolo de Skulltula del Océano"}
    );
//Stray Fairies
    hintTable[CT_STRAY_FAIRY] = HintText::Item({
            //obscure
            Text{"a lost fairy", "un fragment d'être", "una hada perdida"}
        },  //clear
            Text{"the Clock Town Stray Fairy", "la fée égarée de Cadranbourg", "la hada extraviada de la Ciudad", "", "la fée égarée de Bourg-Clocher", ""}
    );
    hintTable[WF_STRAY_FAIRY] = HintText::Item({
            //obscure
            Text{"a lost fairy", "un fragment d'être", "una hada perdida"}
        },  //clear
            Text{"a Woodfall Stray Fairy", "une fée égarée du temple de Boisé-les-Cascades", "una hada extraviada del Bosque Catarata", "", "une fée égarée du temple de Bois-Cascade", ""}
    );
    hintTable[SH_STRAY_FAIRY] = HintText::Item({
            //obscure
            Text{"a lost fairy", "un fragment d'être", "una hada perdida"}
        },  //clear
            Text{"a Snowhead Stray Fairy", "une fée égarée du temple du Pic des neiges", "una hada extraviada del Pico Nevado", "", "une fée égarée du temple du pic des Neiges", ""}
    );
    hintTable[GBT_STRAY_FAIRY] = HintText::Item({
            //obscure
            Text{"a lost fairy", "un fragment d'être", "una hada perdida"}
        },  //clear
            Text{"a Great Bay Stray Fairy", "une fée égarée du temple de la Grande Baie", "una hada extraviada de la Gran Bahía"}
    );
    hintTable[ST_STRAY_FAIRY] = HintText::Item({
            //obscure
            Text{"a lost fairy", "un fragment d'être", "una hada perdida"}
        },  //clear
            Text{"a Stone Tower Stray Fairy", "une fée égarée du temple de la forteresse de pierre", "una hada extraviada de la Torre de Piedra"}
    );
//PROGRESSIVE ITEMS (unused currently)
    hintTable[PROGRESSIVE_SWORD] = HintText::Item({
            //obscure
            Text{"a progressive sword", "un aiguisage", "una espada progresiva"}
        },  //clear
            Text{"a progressive sword", "une lame progressive", "una espada progresiva"}
    );
    hintTable[PROGRESSIVE_BOMB_BAG] = HintText::Item({
            //obscure
            Text{"a progressive bomb bag", "une poche poudreuse", "un saco de bombas progresivo"}
        },  //clear
            Text{"a progressive bomb bag", "un sac de bombes progressif", "un saco de bombas progresivo"}
    );
    hintTable[PROGRESSIVE_BOW] = HintText::Item({
            //obscure
            Text{"a progressive bow", "une capacité de tir accrue", "un arco progresivo"}
        },  //clear
            Text{"a progressive quiver", "un carquois progressif", "un carcaj progresivo"}
    );
    hintTable[PROGRESSIVE_WALLET] = HintText::Item({
            //obscure
            Text{"a progressive wallet", "du talent pour le économies", "una bolsa progresiva"}
        },  //clear
            Text{"a progressive wallet", "une bourse progressive", "una bolsa de rupias progresiva"}
    );
    hintTable[PROGRESSIVE_MAGIC_METER] = HintText::Item({
            //obscure
            Text{"progressive magic meter", "de l'endurance sorcière", "poder mágico progresivo"}
        },  //clear
            Text{"a progressive magic power", "une amélioration d'énergie magique", "un poder mágico progresivo"}
    );
    //PROGRESSIVE_BOMBCHUS
//BOTTLE ITEMS
    hintTable[EMPTY_BOTTLE] = HintText::Item({
            //obscure
            Text{"a glass container", "un récipient étanche", "un contenedor de cristal"}
        },  //clear
            Text{"an Empty Bottle", "un flacon vide", "una botella vacía"}
    );
    hintTable[EMPTY_BOTTLE1] = HintText::Item({
            //obscure
            Text{"a glass container", "un récipient étanche", "un contenedor de cristal"}
        },  //clear
            Text{"an Empty Bottle", "un flacon vide", "una botella vacía"}
    );
    hintTable[EMPTY_BOTTLE2] = HintText::Item({
            //obscure
            Text{"a glass container", "un récipient étanche", "un contenedor de cristal"}
        },  //clear
            Text{"an Empty Bottle", "un flacon vide", "una botella vacía"}
    );
    hintTable[BOTTLE_WITH_MILK] = HintText::Item({
            //obscure
            Text{"a dairy product", "une double dose de calcium", "un producto lácteo"}
        },  //clear
            Text{"a Milk Bottle", "un flacon de lait", "una botella de leche"}
    );
    hintTable[BOTTLE_WITH_RED_POTION] = HintText::Item({
            //obscure
            Text{"a vessel of health", "la santé en bouteille", "un brebaje vital"}
        },  //clear
            Text{"a Red Potion Bottle", "un flacon de potion rouge", "una botella de poción roja"}
    );
    hintTable[BOTTLE_WITH_GREEN_POTION] = HintText::Item({
            //obscure
            Text{"a magic potion", "de la magie à boire", "un brebaje mágico"}
        },  //clear
            Text{"a Green Potion Bottle", "un flacon de potion verte", "una botella de poción verde"}
    );
    hintTable[BOTTLE_WITH_BLUE_POTION] = HintText::Item({
            //obscure
            Text{"a blue drink", "une boisson fongique", "un brebaje cerúleo"}
        },  //clear
            Text{"a Blue Potion Bottle", "un flacon de potion bleue", "una botella de poción azul"}
    );
    hintTable[BOTTLE_WITH_FAIRY] = HintText::Item({
            //obscure
            Text{"a fairy", "un farfadet", "una hada"}
        },  //clear
            Text{"a Fairy Bottle", "une fée en flacon", "una botella con hada"}
    );
    hintTable[BOTTLE_WITH_FISH] = HintText::Item({
            //obscure
            Text{"something fresh", "l'éclat d'argent au fond de l'eau", "algo fresco"}
        },  //clear
            Text{"a Fish Bottle", "un poisson en flacon", "una botella con pez"}
    );
    hintTable[CHATEAU_ROMANI] = HintText::Item({
            //obscure
            Text{"an adult beverage", "un breuvage adulte", "un trago para adultos"}
        },  //clear
            Text{"a Chateau Romani Bottle", "un flacon de Cuvée Romani", "una botella de Reserva Romani"}
    );
    hintTable[BOTTLE_WITH_BUGS] = HintText::Item({
            //obscure
            Text{"an insect", "un fouisseur", "un insecto"}
        },  //clear
            Text{"a Bug Bottle", "un insecte en flacon", "una botella con insecto"}
    );
    hintTable[BOTTLE_WITH_POE] = HintText::Item({
            //obscure
            Text{"a captured spirit", "une hantise violette", "un espíritu apresado"}
        },  //clear
            Text{"a Poe Bottle", "un esprit en flacon", "una botella con Poe"}
    );
    hintTable[BOTTLE_WITH_BIG_POE] = HintText::Item({
            //obscure
            Text{"a large captured spirit", "une flamme issue de trois", "un gran espíritu apresado"}
        },  //clear
            Text{"a Big Poe Bottle", "un grand esprit en flacon", "una botella con un Gran Poe", "", "une âme en flacon", ""}
    );
    hintTable[BOTTLE_WITH_HOT_SPRING_WATER] = HintText::Item({
            //obscure
            Text{"a hot liquid", "un liquide chaud", "un líquido hirviente"}
        },  //clear
            Text{"a Hot Spring Water Bottle", "de l'eau de source chaude en flacon", "una botella con agua caliente de manantial"}
    );
    hintTable[BOTTLE_WITH_SPRING_WATER] = HintText::Item({
            //obscure
            Text{"a fresh drink", "un petit arrosage", "un líquido fresco"}
        },  //clear
            Text{"a Spring Water Bottle", "de l'eau de source en flacon", "una botella con agua de manantial"}
    );
    hintTable[DEKU_PRINCESS] = HintText::Item({
            //obscure
            Text{"a princess", "du sang royal", "una princesa"}
        },  //clear
            Text{"a Deku Princess Bottle", "la princesse mojo en flacon", "una botella con la Princesa Deku"}
    );
    hintTable[GOLD_DUST] = HintText::Item({
            //obscure
            Text{"a gleaming powder", "une poudre scintillante", "un polvo brillante"}
        },  //clear
            Text{"a Gold Dust Bottle", "de la poudre d'or en flacon", "una botella con polvo dorado"}
    );
    hintTable[BOTTLE_WITH_ZORA_EGG] = HintText::Item({
            //obscure
            Text{"a lost child", "une progéniture dérobée", "un renacuajo perdido"}
        },  //clear
            Text{"a Zora Egg Bottle", "un œuf de Zora en flacon", "una botella con un huevo Zora"}
    );
    hintTable[SEAHORSE] = HintText::Item({
            //obscure
            Text{"a sea creature", "une queue enroulée", "una criatura del océano"}
        },  //clear
            Text{"a Seahorse Bottle", "un hippocampe en flacon", "una botella con el caballo de mar"}
    );
    hintTable[BOTTLE_WITH_MUSHROOM] = HintText::Item({
            //obscure
            Text{"a strange fungus", "du mycélium", "un hongo raro"}
        },  //clear
            Text{"a Magic Mushroom Bottle", "un champignon magique en flacon", "una botella con champiñón mágico"}
    );
    hintTable[BOTTLE_WITH_MYSTERY_MILK] = HintText::Item({
            //obscure
            Text{"a strange drink", "un remède maison", "una bebida sospechosa"}
        },  //clear
            Text{"a Mystery Milk Bottle", "du lait mystère en flacon", "una botella de leche sospechosa", "", "du lait suspect en flacon", ""}
    );
//UPGRADABLE ITEMS
    hintTable[LARGE_QUIVER]         = HintText::Item({Text{"a ranged weapon", "un grand tube", "un arma de largo alcance"}});
    hintTable[LARGEST_QUIVER]       = HintText::Item({Text{"a ranged weapon", "un énorme tube", "un arma de largo alcance"}});
    hintTable[BOMB_BAG]             = HintText::Item({Text{"a vessel of explosives", "une besace pyrotechnique", "un contenedor de explosivos"}});
    hintTable[BIG_BOMB_BAG]         = HintText::Item({Text{"a vessel of explosives", "une besace pyrotechnique", "un contenedor de explosivos"}});
    hintTable[BIGGEST_BOMB_BAG]     = HintText::Item({Text{"a vessel of explosives", "une besace pyrotechnique", "un contenedor de explosivos"}});
    hintTable[ADULT_WALLET]         = HintText::Item({Text{"a coin purse", "une tirelire", "una cartera"}});
    hintTable[GIANT_WALLET]         = HintText::Item({Text{"a coin purse", "une tirelire", "una cartera"}});
    hintTable[MAGIC_POWER]          = HintText::Item({Text{"magic power", "une barre verte", "poder mágico"}});
    hintTable[EXTENDED_MAGIC_POWER] = HintText::Item({Text{"magic power", "une barre verte", "poder mágico"}});
//SONGS
    hintTable[SONG_OF_TIME] = HintText::Item({
            //obscure
            Text{"song of time", "une boucle temporelle", "una canción temporal"}
        },  //clear
            Text{"the Song of Time", "le Chant du temps", "la canción del tiempo"}
    );
    hintTable[SONG_OF_STORMS] = HintText::Item({
            //obscure
            Text{"stormy weather", "un temps de chien", "clima torrencial"}
        },  //clear
            Text{"the Song of Storms", "le Chant des tempêtes", "la canción de la tormenta"}
    );
    hintTable[SONG_OF_HEALING] = HintText::Item({
            //obscure
            Text{"a soothing melody", "le repos des âmes", "una canción calmante"}
        },  //clear
            Text{"the Song of Healing", "le Chant de l'apaisement", "la canción de curación"}
    );
    hintTable[SONG_OF_SOARING] = HintText::Item({
            //obscure
            Text{"white wings", "une paire d'ailes", "alas blancas"}
        },  //clear
            Text{"the Song of Soaring", "le Chant de l'envol", "la canción de vuelo"}
    );
    //hintTable[SONG_OF_DOUBLE_TIME] = HintText::Item({
    //        //obscure
    //        Text{"double time", "une réduction des attentes", "tiempo acelerado"}});
    //hintTable[INVERTED_SONG_OF_TIME] = HintText::Item({
    //        //obscure
    //        Text{"slowed time", "un timing assoupli", "tiempo ralentizado"}});
    hintTable[EPONAS_SONG] = HintText::Item({
            //obscure
            Text{"a horses song", "l'appel d'une partenaire", "una canción equina"}
        },  //clear
            Text{"Epona's Song", "le Chant d'Épona", "la canción de Epona", "", "le Chant d'Epona", ""}
    );
    hintTable[SONATA_OF_AWAKENING] = HintText::Item({
            //obscure
            Text{"a royal song", "un chant royal", "una canción de realeza"}
        },  //clear
            Text{"the Sonata of Awakening", "la Sonate de l'éveil", "la sonata del despertar"}
    );
    hintTable[LULLABY_INTRO] = HintText::Item({
            //obscure
            Text{"a sleepy melody intro", "une mélodie incomplète", "una introducción al sueño"}
        },  //clear
            Text{"the Lullaby Intro", "l'intro de la Berceuse", "la introducción de la nana"}
    );
    hintTable[GORONS_LULLABY] = HintText::Item({
            //obscure
            Text{"a sleepy melody", "le repos du géant", "sueño profundo"}
        },  //clear
            Text{"the Goron's Lullaby", "la Berceuse de Gorons", "la nana goron"}
    );
    hintTable[NEW_WAVE_BOSSA_NOVA] = HintText::Item({
            //obscure
            Text{"a song of newborns", "un chant de nourrissons", "canción para nacimientos"}
        },  //clear
            Text{"the New Wave Bossa Nova", "la Bossa-nova des flots", "la bossanova de las olas"}
    );
    hintTable[ELEGY_OF_EMPTINESS] = HintText::Item({
            //obscure
            Text{"empty shells", "un soldat sans cœur", "caparazones huecos"}
        },  //clear
            Text{"the Elegy of Emptiness", "l'Hymne du vide", "la elegía al vacío"}
    );
    hintTable[OATH_TO_ORDER] = HintText::Item({
            //obscure
            Text{"a song of giants", "un rendez-vous au carnaval", "una plegaria a los gigantes"}
        },  //clear
            Text{"the Oath to Order", "l'Ode de l'appel", "la oda al orden"}
    );
//PIECES OF HEART
    hintTable[PIECE_OF_HEART] = HintText::Item({
            //obscure
            Text{"a segment of health", "un segment de vie", "un segmento de vida"}
        },  //clear
            Text{"a Piece of Heart", "un fragment de cœur", "una pieza de corazón"}
    );
    hintTable[HEART_CONTAINER] = HintText::Item({
            //obscure
            Text{"a new heart", "un cœur tout neuf", "un nuevo corazón"}
        },  //clear
            Text{"a Heart Container", "un quart de cœur", "un contenedor de corazón", "", "un réceptacle de cœur", ""}
    );
//MAPS
    //hintTable[MAP] = HintText::Item({
    //        //obscure
    //        Text{"a paper guide", "un guide en papier", "un papiro guía"}});
    hintTable[WOODFALL_TEMPLE_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía"}
        },  //clear
            Text{"the Woodfall Temple Map", "la carte du temple de Boisé-les-Cascades", "el mapa del Templo del Bosque Catarata", "", "la carte du temple de Bois-Cascade", ""}
    );
    hintTable[SNOWHEAD_TEMPLE_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía"}
        },  //clear
            Text{"the Snowhead Temple Map", "la carte du temple du Pic des neiges", "el mapa del Templo del Pico Nevado", "", "la carte du temple du pic des Neiges", ""}
    );
    hintTable[GBT_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía"}
        },  //clear
            Text{"the Great Bay Temple Map", "la carte du temple de la Grande Baie", "el mapa del Templo de la Gran Bahía"}
    );
    hintTable[STONE_TOWER_TEMPLE_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía"}
        },  //clear
            Text{"the Stone Tower Temple Map", "la carte du temple de la forteresse de pierre", "el mapa del Templo de la Torre de Piedra"}
    );
    hintTable[CLOCK_TOWN_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía"}
        },  //clear
            Text{"the Clock Town Map", "la carte de Cadranbourg", "el mapa de la Ciudad Reloj", "", "la carte de Bourg-Clocher", ""}
    );
    hintTable[WOODFALL_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía"}
        },  //clear
            Text{"the Woodfall Map", "la carte de Boisé-les-Cascades", "el mapa del Bosque Catarata", "", "la carte de Bois-Cascade", ""}
    );
    hintTable[SNOWHEAD_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía"}
        },  //clear
            Text{"the Snowhead Map", "la carte du Pic des neiges", "el mapa del Pico Nevado", "", "la carte du pic des Neiges", ""}
    );
    hintTable[GREAT_BAY_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía"}
        },  //clear
            Text{"the Great Bay Map", "la carte de la Grande Baie", "el mapa de la Gran Bahía"}
    );
    hintTable[STONE_TOWER_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía"}
        },  //clear
            Text{"the Stone Tower Map", "la carte de la forteresse de pierre", "el mapa de la Torre de Piedra"}
    );
    hintTable[ROMANI_RANCH_MAP] = HintText::Item({
            //obscure
            Text{"a paper guide", "un guide en papier", "un papiro guía"}
        },  //clear
            Text{"the Romani Ranch Map", "la carte du ranch Romani", "el mapa del Rancho Romani"}
    );
//COMPASSES
    //hintTable[COMPASS] = HintText::Item({
    //        //obscure
    //        Text{"a magnetic needle", "une aiguille magnétique", "una aguja imantada"}});
    hintTable[WOODFALL_TEMPLE_COMPASS] = HintText::Item({
            //obscure
            Text{"a magnetic needle", "une aiguille magnétique", "una aguja imantada"}
        },  //clear
            Text{"the Woodfall Temple Compass", "la boussole du temple de Boisé-les-Cascades", "la brújula del Templo del Bosque Catarata", "", "la boussole du temple de Bois-Cascade", ""}
    );
    hintTable[SNOWHEAD_TEMPLE_COMPASS] = HintText::Item({
            //obscure
            Text{"a magnetic needle", "une aiguille magnétique", "una aguja imantada"}
        },  //clear
            Text{"the Snowhead Temple Compass", "la boussole du temple du Pic des neiges", "la brújula del Templo del Pico Nevado", "", "la boussole du temple du pic des Neiges", ""}
    );
    hintTable[GBT_COMPASS] = HintText::Item({
            //obscure
            Text{"a magnetic needle", "une aiguille magnétique", "una aguja imantada"}
        },  //clear
            Text{"the Great Bay Temple Compass", "la boussole du temple de la Grande Baie", "la brújula del Templo de la Gran Bahía"}
    );
    hintTable[STONE_TOWER_TEMPLE_COMPASS] = HintText::Item({
            //obscure
            Text{"a magnetic needle", "une aiguille magnétique", "una aguja imantada"}
        },  //clear
            Text{"the Stone Tower Temple Compass", "la boussole du temple de la forteresse de pierre", "la brújula del Templo de la Torre de Piedra"}
    );
//BOSSKEYS
    //hintTable[BOSS_KEY] = HintText::Item({
    //        //obscure
    //        Text{"an important key", "une clé importante", "una llave importante"}});
    hintTable[WOODFALL_TEMPLE_BOSS_KEY] = HintText::Item({
            //obscure
            Text{"an important key", "une clé importante", "una llave importante"}
        },  //clear
            Text{"the Woodfall Temple Boss Key", "la grande clé du temple de Boisé-les-Cascades", "la llave del jefe del Templo del Bosque Catarata", "", "la grande clé du temple de Bois-Cascade", ""}
    );
    hintTable[SNOWHEAD_TEMPLE_BOSS_KEY] = HintText::Item({
            //obscure
            Text{"an important key", "une clé importante", "una llave importante"}
        },  //clear
            Text{"the Snowhead Temple Boss Key", "la grande clé du temple du Pic des neiges", "la llave del jefe del Templo del Pico Nevado", "", "la grande clé du temple du pic des Neiges", ""}
    );
    hintTable[GBT_BOSS_KEY] = HintText::Item({
            //obscure
            Text{"an important key", "une clé importante", "una llave importante"}
        },  //clear
            Text{"the Great Bay Temple Boss Key", "la grande clé du temple de la Grande Baie", "la llave del jefe del Templo de la Gran Bahía"}
    );
    hintTable[STONE_TOWER_TEMPLE_BOSS_KEY] = HintText::Item({
            //obscure
            Text{"an important key", "une clé importante", "una llave importante"}
        },  //clear
            Text{"the Stone Tower Temple Boss Key", "la grande clé du temple de la forteresse de pierre", "la llave del jefe del Templo de la Torre de Piedra"}
    );
//SMALLKEYS
    //hintTable[SMALL_KEY] = HintText::Item({
    //        //obscure
    //        Text{"a useful key", "une clé pratique", "una llave útil"}});
    hintTable[WOODFALL_TEMPLE_SMALL_KEY] = HintText::Item({
            //obscure
            Text{"swampy small key", "une clé marécageuse", "una llave pantanosa"}
        },  //clear
            Text{"the Woodfall Temple Small Key", "la petite clé du temple de Boisé-les-Cascades", "la llave pequeña del Templo del Bosque Catarata", "", "la petite clé du temple de Bois-Cascade", ""}
    );
    hintTable[SNOWHEAD_TEMPLE_SMALL_KEY] = HintText::Item({
            //obscure
            Text{"icy small key", "une clé glacée", "una llave helada"}
        },  //clear
            Text{"a Snowhead Temple Small Key", "une petite clé du temple du Pic des neiges", "una llave pequeña del Templo del Pico Nevado", "", "une petite clé du temple du pic des Neiges", ""}
    );
    hintTable[GBT_SMALL_KEY] = HintText::Item({
            //obscure
            Text{"ocean small key", "une clé marine", "una llave húmeda"}
        },  //clear
            Text{"the Great Bay Temple Small Key", "la petite clé du temple de la Grande Baie", "la llave pequeña del Templo de la Gran Bahía"}
    );
    hintTable[STONE_TOWER_TEMPLE_SMALL_KEY] = HintText::Item({
            //obscure
            Text{"rocky small key", "une clé rocheuse", "una llave rocosa"}
        },  //clear
            Text{"a Stone Tower Temple Small Key", "une petite clé du temple de la forteresse de pierre", "una llave pequeña del Templo de la Torre de Piedra"}
    );
//DUNGEON REWARDS
    hintTable[ODOLWAS_REMAINS] = HintText::Item({
            //obscure
            Text{"a boss's remains", "un sceau de géant", "los restos de un jefe"}
        },  //clear
            Text{"Odolwa's Remains", "les restes d'Odolwa", "los Restos de Odolwa"}
    );
    hintTable[GOHTS_REMAINS] = HintText::Item({
            //obscure
            Text{"a boss's remains", "un sceau de géant", "los restos de un jefe"}
        },  //clear
            Text{"Goht's Remains", "les restes de Rhork", "los Restos de Goht"}
    );
    hintTable[GYORGS_REMAINS] = HintText::Item({
            //obscure
            Text{"a boss's remains", "un sceau de géant", "los restos de un jefe"}
        },  //clear
            Text{"Gyorg's Remains", "les restes de Gyorg", "los Restos de Gyorg"}
    );
    hintTable[TWINMOLDS_REMAINS] = HintText::Item({
            //obscure
            Text{"a boss's remains", "un sceau de géant", "los restos de un jefe"}
        },  //clear
            Text{"Twinmold's Remains", "les restes de Skorn", "los Restos de Twinmold"}
    );

    /*-----------------------
    |    REFILL ITEMS       |
    -----------------------*/
    hintTable[RECOVERY_HEART] = HintText::Item({
            //obscure
            Text{"Recovery Heart", "un petit soin", "un pequeño corazón"}
        },  //clear
            Text{"a Recovery Heart", "un cœur de vie", "un corazón"}
    );
    hintTable[GREEN_RUPEE] = HintText::Item({
            //obscure
            Text{"Green rupee", "le début de la richesse", "una gema verdeante"}
        },  //clear
            Text{"a Green Rupee", "un rubis vert", "una rupia verde"}
    );
    hintTable[BLUE_RUPEE] = HintText::Item({
            //obscure
            Text{"Blue rupee", "une richesse azurée", "una gema cerúlea"}
        },  //clear
            Text{"a Blue Rupee", "un rubis bleu", "una rupia azul"}
    );
    hintTable[RED_RUPEE] = HintText::Item({
            //obscure
            Text{"Red rupee", "une richesse écarlate", "una gema carmesí"}
        },  //clear
            Text{"a Red Rupee", "un rubis rouge", "una rupia roja"}
    );
    hintTable[PURPLE_RUPEE] = HintText::Item({
            //obscure
            Text{"Purple rupee", "une richesse violacée", "una gema cárdena"}
        },  //clear
            Text{"a Purple Rupee", "un rubis mauve", "una rupia púrpura", "", "un rubis violet", ""}
    );
    hintTable[SILVER_RUPEE] = HintText::Item({
            //obscure
            Text{"Silver rupee", "une richesse scintillante", "una gema argéntea"}
        },  //clear
            Text{"a Silver Rupee", "un rubis argenté", "una rupia plateada"}
    );
    hintTable[HUGE_RUPEE] = HintText::Item({
            //obscure
            Text{"Huge rupee", "une richesse écrasante", "una gema enorme"}
        },  //clear
            Text{"a Huge Rupee", "un énorme rubis", "una rupia enorme"}
    );
    hintTable[DEKU_NUTS_5] = HintText::Item({
            //obscure
            Text{"5 nuts", "un paquet de flashs", "5 nueces"}
        },  //clear
            Text{"Deku Nuts (5 pieces)", "une demi-dizaine de noix mojos", "Nueces deku (5)", "", "une demi-dizaine de noix mojo", ""}
    );
    hintTable[DEKU_NUTS_10] = HintText::Item({
            //obscure
            Text{"10 nuts", "un paquet de flashs", "10 nueces"}
        },  //clear
            Text{"Deku Nuts (10 pieces)", "une dizaine de noix mojos", "Nueces deku (10)", "", "une dizaine de noix mojo", ""}
    );
    hintTable[BOMBS_5] = HintText::Item({
            //obscure
            Text{"5 explosive orbs", "un paquet d'explosifs", "5 explosiones"}
        },  //clear
            Text{"Bombs (5 pieces)", "une demi-dizaine de bombes", "Bombas (5)"}
    );
    hintTable[BOMBS_10] = HintText::Item({
            //obscure
            Text{"10 explosive orbs", "un paquet d'explosifs", "10 explosiones"}
        },  //clear
            Text{"Bombs (10 pieces)", "une dizaine de bombes", "Bombas (10)"}
    );
    hintTable[BOMBS_20] = HintText::Item({
            //obscure
            Text{"20 explosive orbs", "un paquet d'explosifs", "20 explosiones"}
        },  //clear
            Text{"Bombs (20 pieces)", "une vingtaine de bombes", "Bombas (20)"}
    );
    hintTable[BOMBCHU_5] = HintText::Item({
            //obscure
            Text{"5 explosive mice", "un paquet d'explosifs", "5 ratones explosivos"}
        },  //clear
            Text{"Bombchu (5 pieces)", "une demi-dizaine de bombchu", "Bombchus (5)", "", "une demi-dizaine de missiles teigneux", ""}
    );
    hintTable[BOMBCHU_10] = HintText::Item({
            //obscure
            Text{"10 explosive mice", "un paquet d'explosifs", "10 ratones explosivos"}
        },  //clear
            Text{"Bombchu (10 pieces)", "une dizaine de bombchu", "Bombchus (10)", "", "une dizaine de missiles teigneux", ""}
    );
    hintTable[BOMBCHU_20] = HintText::Item({
            //obscure
            Text{"20 explosive mice", "un paquet d'explosifs", "20 ratones explosivos"}
        },  //clear
            Text{"Bombchu (20 pieces)", "une vingtaine de bombchu", "Bombchus (20)", "", "une vingtaine de missiles teigneux", ""}
    );
    hintTable[ARROWS_10] = HintText::Item({
            //obscure
            Text{"10 projectile sticks", "un paquet d'aiguilles", "10 palos proyectiles"}
        },  //clear
            Text{"Arrow (10 pieces)", "une dizaine de flèches", "Flechas (10)"}
    );
    hintTable[ARROWS_30] = HintText::Item({
            //obscure
            Text{"30 projectile sticks", "un paquet d'aiguilles", "30 palos proyectiles"}
        },  //clear
            Text{"Arrow (30 pieces)", "une trentaine de flèches", "Flechas (30)"}
    );
    hintTable[ARROWS_40] = HintText::Item({
            //obscure
            Text{"40 projectile sticks", "un paquet d'aiguilles", "40 palos proyectiles"}
        },  //clear
            Text{"Arrow (40 pieces)", "une quarantaine de flèches", "Flechas (40)"}
    );
    hintTable[ARROWS_50] = HintText::Item({
            //obscure
            Text{"50 projectile sticks", "un paquet d'aiguilles", "50 palos proyectiles"}
        },  //clear
            Text{"Arrow (50 pieces)", "une cinquantaine de flèches", "Flechas (50)"}
    );
    hintTable[BLUE_POTION_REFILL] = HintText::Item({
            //obscure
            Text{"Blue Potion Refill", "une dose de bleu", "un relleno de Poción Azul"}
        },  //clear
            Text{"some Blue Potion", "de la potion bleue", "un relleno de Poción Azul"}
    );
    hintTable[GREEN_POTION_REFILL] = HintText::Item({
            //obscure
            Text{"Green Potion Refill", "une dose de vert", "un relleno de Poción Verde"}
        },  //clear
            Text{"some Green Potion", "de la potion verte", "un relleno de Poción Verde"}
    );
    hintTable[RED_POTION_REFILL] = HintText::Item({
            //obscure
            Text{"Red Potion Refill", "une dose de rouge", "un relleno de Poción Roja"}
        },  //clear
            Text{"some Red Potion", "de la potion rouge", "un relleno de Poción Roja"}
    );
    hintTable[BOMBCHU_DROP] = HintText::Item({
            //obscure
            Text{"explosive mice", "un paquet d'explosifs", "un ratón explosivo"}
        },  //clear
            Text{"some Bombchu", "un paquet de bombchu", "algunos Bombchus", "", "un paquet de missiles teigneux", ""}
    );
    hintTable[DEKU_STICK_1] = HintText::Item({
            //obscure
            Text{"1 stick", "une branche", "una rama"}
        },  //clear
            Text{"a Deku Stick", "un bâton mojo", "un palo Deku"}
    );

    /*----------------
    |   SHOP ITEMS   |
    ----------------*/
    hintTable[BUY_ARROWS_10]        = HintText::Item({Text{"Buy 10 Arrows", "Acheter: Flèches (10)", "Comprar 10 flechas"}});
    hintTable[BUY_ARROWS_30]        = HintText::Item({Text{"Buy 30 Arrows", "Acheter: Flèches (30)", "Comprar 30 flechas"}});
    hintTable[BUY_BLUE_POTION]      = HintText::Item({Text{"Buy Blue Potion", "Acheter: Potion bleue", "Comprar poción azul"}});
    hintTable[BUY_BOMBCHU_10]       = HintText::Item({Text{"Buy 10 Bombchu", "Acheter: Bombchu (10)", "Comprar 10 bombchus"}});
    hintTable[BUY_BOMBS_10]         = HintText::Item({Text{"Buy 10 Bombs", "Acheter: Bombes (10)", "Comprar 10 bombas"}});
    hintTable[BUY_DEKU_NUT_10]      = HintText::Item({Text{"Buy 10 Deku Nuts", "Acheter: Noix Mojos (10)", "Comprar 10 nueces Deku"}});
    hintTable[BUY_DEKU_STICK_1]     = HintText::Item({Text{"Buy 1 Deku Stick", "Acheter: Bâton Mojo (1)", "Comprar 1 palo Deku"}});
    hintTable[BUY_FAIRYS_SPIRIT]    = HintText::Item({Text{"Buy Fairy", "Acheter: Fée", "Comprar hada"}});
    hintTable[BUY_GREEN_POTION]     = HintText::Item({Text{"Buy Green Potion", "Acheter: Potion verte", "Comprar poción verde"}});
    hintTable[BUY_HEROS_SHIELD]     = HintText::Item({Text{"Buy Hero Shield", "Acheter: Bouclier du Héros", "Comprar el escudo del héroe"}});
    hintTable[BUY_MAGIC_BEAN]       = HintText::Item({Text{"Buy Magic Bean", "Acheter: Haricot Magique", "Comprar habichuela mágica"}});
    hintTable[BUY_RED_POTION]       = HintText::Item({Text{"Buy Red Potion", "Acheter: Potion rouge ", "Comprar poción roja"}});

    /*-----------------------
    |  SOMETIMES HINT TEXT  |
    -----------------------*/
//Clock Tower
    hintTable[CLOCK_TOWER_OCARINA_OF_TIME] = HintText::Sometimes({
            //obscure
            Text{"a #musical instrument# is", "l'#instrument qui t'a été volé# est", "Un instrumento musical"}});
    hintTable[CLOCK_TOWER_SONG_OF_TIME] = HintText::Sometimes({
            //obscure
            Text{"a #timeless song# is", "le #souvenir de la princesse# est", ""}});
    hintTable[HMS_DEKU_MASK] = HintText::Sometimes({
            //obscure
            Text{"a #forest curse removed# rewards", "#lever une malédiction sylvestre# crée", "remover la maldición del bosque otorga"}});
    hintTable[HMS_SONG_OF_HEALING] = HintText::Sometimes({
            //obscure
            Text{"a #masked man's melody# teaches", "la #foire aux masques# enseigne", "la melodía del hombre enmascarado enseña"}});
    hintTable[HMS_BOMBERS_NOTEBOOK] = HintText::Sometimes({
            //obscure
            Text{"a #masked man's gift# rewards", "la #foire aux masque# offre", "el hombre enmascarado otorga"}});
    hintTable[HMS_STARTING_SWORD] = HintText::Sometimes({
            //obscure
            Text{"a #new file# yields", "une #nouvelle partie# procure", "una nueva partida otorga"}});
    hintTable[HMS_STARTING_SHIELD] = HintText::Sometimes({
            //obscure
            Text{"a #new file# yields", "une #nouvelle partie# procure", "una nueva partida otorga"}});
    //PRE_CLOCK_TOWN_CHEST
//Deku Palace
    hintTable[DEKU_PALACE_BEAN_SELLER] = HintText::Sometimes({
            //obscure
            Text{"a #gorging merchant# sells", "un #marchand goulu# vend", "el mercader enterrado vende"}});
    hintTable[DEKU_PALACE_WEST_GARDEN] = HintText::Sometimes({
            //obscure
            Text{"the #home of scrubs# contains", "l'#habitat des pestes# contient", "el hogar de los matorrales contiene"}});
    hintTable[DEKU_PALACE_BUTLER_RACE] = HintText::Sometimes({
            //obscure
            Text{"the #royal servant# rewards", "le #servant royal# offre", "el sirviente real recompensa con"}});
    hintTable[DEKU_PALACE_BEAN_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #merchant's cave# contains", "la #grotte d'un marchand# contient", "la cueva del mercader contiene"}});
    hintTable[DEKU_PALACE_IMPRISONED_MONKEY] = HintText::Sometimes({
            //obscure
            Text{"a #false imprisonment# teaches", "un #détenu innocent# enseigne", "un falso aprisionamiento enseña"}});
//East Clock Town
    hintTable[E_CLOCK_TOWN_AROMA_IN_BAR] = HintText::Sometimes({
            //obscure
            Text{"an #important lady# rewards", "un #rapport fructueux# confère", "una señora importante recompensa con"}});
    hintTable[E_CLOCK_TOWN_ARCHERY_1] = HintText::Sometimes({
            //obscure
            Text{"a #town activity# rewards", "un #habile abattage d'octoroks# octroie", "una actividad en la ciudad recompensa con"}});
    hintTable[E_CLOCK_TOWN_ARCHERY_2] = HintText::Sometimes({
            //obscure
            Text{"a #town activity# rewards", "un #parfait abattage d'octoroks# octroie", "una actividad en la ciudad recompensa con"}});
    hintTable[E_CLOCK_TOWN_MAYOR] = HintText::Sometimes({
            //obscure
            Text{"a #town leader# rewards", "un #homme d'état# offre", "el líder de la ciudad recompensa con"}});
    hintTable[E_CLOCK_TOWN_HONEY_DARLING_3DAYS] = HintText::Sometimes({
            //obscure
            Text{"a #lovers game# rewards", "un #jeu d'amants# offre", "un juego de amantes recompensa con"}});
    hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_GORON] = HintText::Sometimes({
            //obscure
            Text{"a #treasure game# rewards", "un #jeu trésorier# offre", "un juego del tesoro recompensa con"}});
    hintTable[E_CLOCK_TOWN_POSTMAN_FREEDOM] = HintText::Sometimes({
            //obscure
            Text{"a #delivery person# rewards", "un #ex-livreur# offre", "un repartidor recompensa con"}});
    hintTable[E_CLOCK_TOWN_GORMAN] = HintText::Sometimes({
            //obscure
            Text{"a #miserable leader# rewards", "un #homme ivre# offre", "un líder miserable otorga"}});
    hintTable[E_CLOCK_TOWN_AROMA_IN_OFFICE] = HintText::Sometimes({
            //obscure
            Text{"an #important lady# rewards", "une #affectation détective# confie", "una señora importante recompensa con"}});
    hintTable[BOMBERS_HIDEOUT_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #secret hideout# contains", "un #recoin de repaire# recèle", "un escondite secreto contiene"}});
    hintTable[E_CLOCK_TOWN_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #shop roof# contains", "un #toit d'entreprise# contient", "el techo de una tienda contiene"}});
    hintTable[E_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({
            //obscure
            Text{"a #correspondence box# contains", "un #boîte à correspondances# contient", "una caja de correspondencia contiene"}});
    //hintTable[E_CLOCK_TOWN_MILK_BAR_CHATEAU] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "un #spécialiste laitier# vend", "un lugar de copas vende"}});
    //hintTable[E_CLOCK_TOWN_MILK_BAR_MILK] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "un #spécialiste laitier# vend", "un lugar de copas vende"}});
    hintTable[GORMAN_TRACK_MYSTERY_MILK_QUEST] = HintText::Sometimes({
            //obscure
            Text{"an #upset stomach cure# rewards", "#soigner un mal de ventre# produit", "la cura a un mal estomacal recompensa con"}});
    //hintTable[E_CLOCK_TOWN_HONEY_DARLING_ANY_DAY] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "un #jeu d'amants# offre quotidiennement", "un juego de amantes recompensa con"}});
    //hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_HUMAN] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "une #partie à 20 rubis# offre", "un juego del tesoro recompensa con"}});
    //hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_ZORA] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "une #partie à 10 rubis# offre", "un juego del tesoro recompensa con"}});
    //hintTable[E_CLOCK_TOWN_TREASURE_CHEST_GAME_DEKU] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "une #partie à 5 rubis# offre", "un juego del tesoro recompensa con"}});
//Goron Village
    hintTable[GORON_VILLAGE_POWDER_KEG_CHALLENGE] = HintText::Sometimes({
            //obscure
            Text{"a #large goron# rewards", "un #grand goron# confie", "un enorme goron recompensa con"}});
    hintTable[GORON_VILLAGE_SCRUB_PURCHASE] = HintText::Sometimes({
            //obscure
            Text{"a #northern merchant# sells", "un #marchand septentrional# vend", "un mercader en el norte vende"}});
    hintTable[GORON_VILLAGE_LENS_OF_TRUTH_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #lonely peak# contains", "un #pic esseulé# contient", "una cumbre solitaria contiene"}});
    hintTable[GORON_VILLAGE_SCRUB_TRADE] = HintText::Sometimes({
            //obscure
            Text{"a #northern merchant# trades", "un #marchand septentrional# échange", "un mercader en el norte intercambia por"}});
    hintTable[GORON_VILLAGE_LEDGE] = HintText::Sometimes({
            //obscure
            Text{"a #cold ledge# contains", "Un #rebord froid# recèle", "una cornisa fría contiene"}});
    hintTable[GORON_VILLAGE_POWDER_KEG_CHALLENGE_SPRING] = HintText::Sometimes({
            //obscure
            Text{"a #large goron# rewards", "un #grand goron# confie", "un enorme goron recompensa con"}});
    hintTable[GORON_VILLAGE_SCRUB_PURCHASE_SPRING] = HintText::Sometimes({
            //obscure
            Text{"a #northern merchant# sells", "un #marchand septentrional# vend", "un mercader en el norte vende"}});
    hintTable[GORON_VILLAGE_SCRUB_TRADE_SPRING] = HintText::Sometimes({
            //obscure
            Text{"a #northern merchant# trades", "un #marchand septentrional# échange", "un mercader en el norte intercambia por"}});
    hintTable[GORON_VILLAGE_LEDGE_SPRING] = HintText::Sometimes({
            //obscure
            Text{"a #cold ledge# contains", "un #rebord froid# recèle", "una cornisa fría contiene"}});
    hintTable[GORON_VILLAGE_GORON_LULLABY] = HintText::Sometimes({
            //obscure
            Text{"a #lonely child# teaches", "un #enfant délaissé# enseigne", "un niño solitario enseña"}});
    hintTable[LENS_CAVE_RED_RUPEE] = HintText::Sometimes({
            //obscure
            Text{"a #lonely peak# contains", "un #pic esseulé# contient", "una cumbre solitaria contiene"}});
    hintTable[LENS_CAVE_PURPLE_RUPEE] = HintText::Sometimes({
            //obscure
            Text{"a #lonely peak# contains", "un #pic esseulé# contient", "una cumbre solitaria contiene"}});
    hintTable[GORON_SHOP_ITEM_1] = HintText::Sometimes({
            //obscure
            Text{"a #goron shop# sells", "une #boutique minière# vend", "una tienda Goron vende"}});
    hintTable[GORON_SHOP_ITEM_2] = HintText::Sometimes({
            //obscure
            Text{"a #goron shop# sells", "une #boutique minière# vend", "una tienda Goron vende"}});
    hintTable[GORON_SHOP_ITEM_3] = HintText::Sometimes({
            //obscure
            Text{"a #goron shop# sells", "une #boutique minière# vend", "una tienda Goron vende"}});
//Great Bay Coast
    hintTable[GBC_OCEAN_SPIDER_DAY1] = HintText::Sometimes({
            //obscure
            Text{"a #new ocean home owner# rewards", "un #emménagement côtier# octroie", "un nuevo dueño de una casa en el océano recompensa con"}});
    //hintTable[GBC_OCEAN_SPIDER_DAY2] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "une récompense #indisponible en 3D# est", "un nuevo dueño de una casa en el océano recompensa con"}});
    //hintTable[GBC_OCEAN_SPIDER_DAY3] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "une récompense #indisponible en 3D# est", "un nuevo dueño de una casa en el océano recompensa con"}});
    hintTable[GBC_FISHERMAN_GAME] = HintText::Sometimes({
            //obscure
            Text{"an #ocean game# rewards", "un #jeu bondissant# offre", "un juego en el océano recompensa con"}});
    hintTable[GBC_OCEAN_SPIDER_CHEST] = HintText::Sometimes({
            //obscure
            Text{"the #colored masks# contain", "les #masques colorés# protègent", "las máscaras de colores contienen"}});
    hintTable[GBC_LAB_FISH] = HintText::Sometimes({
            //obscure
            Text{"#feeding the fish# rewards", "une #croissance ichtyenne# dévoile", "alimentar a los peces recompensa con"}});
    hintTable[GBC_LEDGE] = HintText::Sometimes({
            //obscure
            Text{"an #ocean ledge# contains", "un #rebord côtier# recèle", "una cornisa en el océano contiene"}});
    hintTable[GBC_MIKAU] = HintText::Sometimes({
            //obscure
            Text{"a #healed spirit# rewards", "l'#apaisement d'un guitariste# crée", "un espíritu curado recompensa con"}});
    hintTable[GBC_BABY_ZORAS] = HintText::Sometimes({
            //obscure
            Text{"the #pirates' loot# teaches", "le #butin des pirates# enseigne", "el botín de los piratas enseña"}});
    hintTable[GBC_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"an #ocean cave# contains", "un #trou côtier# contient", "una cueva en el océano contiene"}});
    hintTable[GBC_GROTTO_COW1] = HintText::Sometimes({
            //obscure
            Text{"a #lost creature# gives", "un #ruminant côtier# prodigue", "una criatura perdida da"}});
    hintTable[GBC_GROTTO_COW2] = HintText::Sometimes({
            //obscure
            Text{"a #lost creature# gives", "un #ruminant côtier# prodigue", "una criatura perdida da"}});
    hintTable[GBC_FISHERMAN_PHOTO] = HintText::Sometimes({
            //obscure
            Text{"a #fisherman# rewards", "un #pêcheur# échange", "un pescador recompensa con"}});
    hintTable[TINGLE_GBC_GB] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende"}});
    hintTable[TINGLE_GBC_ST] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende"}});
//Ikana Canyon
    hintTable[IKANA_CANYON_GREAT_FAIRY] = HintText::Sometimes({
            //obscure
            Text{"the #fairy of kindness# rewards", "la #fée de la bonté# prodigue", "la hada de la bondad recompensa con"}});
    hintTable[IKANA_CANYON_POE_HUT_HP] = HintText::Sometimes({
            //obscure
            Text{"a #game of ghosts# rewards", "une #arène spectrale# remet", "un juego de fantasmas recompensa con"}});
    hintTable[IKANA_CANYON_LEDGE] = HintText::Sometimes({
            //obscure
            Text{"a #canyon ledge# contains", "un #rebord de vallée# recèle", "una repisa en el cañón contiene"}});
    hintTable[IKANA_CANYON_PAMELAS_FATHER] = HintText::Sometimes({
            //obscure
            Text{"a #lost father# rewards", "un #chercheur est maudit par#", "un padre absorto recompensa con"}});
    hintTable[IKANA_CANYON_SECRET_SHRINE_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #waterfall cave# contains", "une #trou de cascade# contient", "una cueva en la cascada contiene"}});
    hintTable[IKANA_CANYON_SCRUB_TRADE] = HintText::Sometimes({
            //obscure
            Text{"an #eastern merchant# trades", "un #marchand oriental# échange", "un mercader del este intercambia por"}});
    hintTable[IKANA_CANYON_SCRUB_PURCHASE] = HintText::Sometimes({
            //obscure
            Text{"an #eastern merchant# sells", "un #marchand oriental# vend", "un mercader del este vende"}});
    hintTable[TINGLE_IKANA_CANYON_ST] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende"}});
    hintTable[TINGLE_IKANA_CANYON_CT] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende"}});
//Ikana Graveyard
    hintTable[IKANA_GRAVEYARD_DAMPE_DIGGING] = HintText::Sometimes({
            //obscure
            Text{"a #fearful basement# contains", "#déterrer trois flammes# révèle", "un sótano aterrorizante contiene"}});
    hintTable[IKANA_GRAVEYARD_IRON_KNUCKLE_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #hollow ground# contains", "une #tombe illusoire# contient", "un suelo hueco contiene"}});
    hintTable[IKANA_GRAVEYARD_CAPTAIN_KEETA_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #skeletal leader# rewards", "un #squelette roupilleur# protège", "un líder esquelético recompensa con"}});
    hintTable[IKANA_GRAVEYARD_DAY_ONE_GRAVE_TABLET] = HintText::Sometimes({
            //obscure
            Text{"a #hollow ground# teaches", "#la requête du compositeur# octroie", "un suelo hueco enseña"}});
    hintTable[IKANA_GRAVEYARD_DAY_ONE_GRAVE_BATS] = HintText::Sometimes({
            //obscure
            Text{"a #cloud of bats# contains", "une #nuée de chauve-souris# protège", "un grupo de murciélagos contiene"}});
    hintTable[IKANA_GRAVEYARD_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #circled cave# contains", "une #grotte encerclée# contient", "una cueva rodeada contiene"}});
//Laundry Pool
    hintTable[LAUNDRY_POOL_KAFEI] = HintText::Sometimes({
            //obscure
            Text{"a #posted letter# rewards", "#rencontrer un disparu# octroie", "una carta enviada recompensa con"}});
    hintTable[LAUNDRY_POOL_CURIOSITY_SHOP_MAN_ONE] = HintText::Sometimes({
            //obscure
            Text{"a #shady dealer# rewards", "un #commerçant suspect# confie", "un comerciante sospechoso recompensa con"}});
    hintTable[LAUNDRY_POOL_CURIOSITY_SHOP_MAN_TWO] = HintText::Sometimes({
            //obscure
            Text{"a #shady dealer# rewards", "un #commerçant suspect# confie", "un comerciante sospechoso recompensa con"}});
    hintTable[LAUNDRY_POOL_GURU_GURU] = HintText::Sometimes({
            //obscure
            Text{"a #musician# gives", "un #musicien ambulant# délègue", "un músico da"}});
    hintTable[LAUNDRY_POOL_SF] = HintText::Sometimes({
            //obscure
            Text{"a #lost fairy# is", "une #fée orange# est", "una hada perdida es"}});
//Milk Road
    hintTable[MILK_ROAD_GORMAN_RACE] = HintText::Sometimes({
            //obscure
            Text{"a #sporting event# rewards", "un #pari hippique# octroie", "un evento deportivo recompensa con"}});
    hintTable[MILK_ROAD_GORMAN_MILK_BUY] = HintText::Sometimes({
            //obscure
            Text{"a #dodgy seller# sells", "un #duo suspect# vend", "un vendedor tramposo vende"}});
    hintTable[MILK_ROAD_KEATON_QUIZ] = HintText::Sometimes({
            //obscure
            Text{"a #mysterious fox# rewards", "un #mystérieux goupil# offre", "un zorro misterioso recompensa con"}});
    hintTable[TINGLE_MILK_ROAD_RR] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende"}});
    hintTable[TINGLE_MILK_ROAD_GB] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende"}});
//Mountain Village
    hintTable[MOUNTAIN_VILLAGE_SMITH_DAY_ONE] = HintText::Sometimes({
            //obscure
            Text{"a #mountain smith# crafts", "un #achat acéré# octroie", "un herrero en la montaña forja"}});
    hintTable[MOUNTAIN_VILLAGE_SMITH_DAY_TWO] = HintText::Sometimes({
            //obscure
            Text{"a #mountain smith# crafts", "#échanger de l'or# octroie", "un herrero en la montaña forja"}});
    hintTable[MOUNTAIN_VILLAGE_FROG_CHOIR] = HintText::Sometimes({
            //obscure
            Text{"a #frog choir# rewards", "une #chorale coassante# offre", "un coro de ranas recompensa con"}});
    hintTable[MOUNTAIN_VILLAGE_KEATON_QUIZ] = HintText::Sometimes({
            //obscure
            Text{"a #mysterious fox# rewards", "un #mystérieux goupil# offre", "un zorro misterioso recompensa con"}});
    hintTable[MOUNTAIN_VILLAGE_DARMANI] = HintText::Sometimes({
            //obscure
            Text{"a #mountain spirit# rewards", "un #esprit montagnard# offre", "un espíritu en la montaña recompensa con"}});
    hintTable[MOUNTAIN_VILLAGE_HUNGRY_GORON] = HintText::Sometimes({
            //obscure
            Text{"a #hungry goron# rewards", "un #goron affamé# a", "un goron hambriento recompensa con"}});
    hintTable[MOUNTAIN_WATERFALL_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #springtime waterfall# contains", "une #chute d'eau printanière# contient", "una cascada en primavera contiene"}});
    hintTable[MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #springtime cave# contains", "une #grotte printanière# contient", "una cueva en primavera contiene"}});
//N Clock Town
    hintTable[N_CLOCK_TOWN_GREAT_FAIRY_DEKU] = HintText::Sometimes({
            //obscure
            Text{"the #fairy of magic# rewards", "la #fée des enchantements# prodigue", "la hada de la magia recompensa con"}});
    //hintTable[N_CLOCK_TOWN_BOMBERS_HIDE_SEEK] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "une récompense #indisponible en 3D# est", "un juego de escondidas recompensa con"}});
    hintTable[N_CLOCK_TOWN_KEATON_QUIZ] = HintText::Sometimes({
            //obscure
            Text{"a #mysterious fox# rewards", "un #mystérieux goupil# offre", "un zorro misterioso recompensa con"}});
    hintTable[N_CLOCK_TOWN_DEKU_PLAYGROUND_3DAYS] = HintText::Sometimes({
            //obscure
            Text{"a #game for scrubs# rewards", "un #pro en vol plané# reçoit", "un campo de juegos para matorrales recompensa con"}});
    hintTable[N_CLOCK_TOWN_TREE] = HintText::Sometimes({
            //obscure
            Text{"a #town playground# contains", "une #aire de jeu citadine# recèle", "un campo de juegos contiene"}});
    hintTable[N_CLOCK_TOWN_OLD_LADY] = HintText::Sometimes({
            //obscure
            Text{"an #old lady's struggle# rewards", "#aider une aînée# octroie", "el forcejeo de una anciana recompensa con"}});
    hintTable[N_CLOCK_TOWN_GREAT_FAIRY_HUMAN] = HintText::Sometimes({
            //obscure
            Text{"the #fairy of magic# rewards", "la #fée des enchantements# prodigue", "la hada de la magia recompensa con"}});
    hintTable[TINGLE_N_CLOCK_TOWN_CT] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende"}});
    hintTable[TINGLE_N_CLOCK_TOWN_WF] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende"}});
    hintTable[N_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({
            //obscure
            Text{"a #correspondence box# contains", "un #boîte a correspondances# contient", "una caja de correspondencia contiene"}});
    //hintTable[N_CLOCK_TOWN_DEKU_PLAYGROUND_ADAY] = HintText::Sometimes({
    //        //obscure
    //        Text{"a #game for scrubs' daily reward# is", "un #jeu pour pestes# offre quotidiennement", "un juego para matorrales contiene"}});
//Road to Snowhead
    hintTable[ROAD_TO_SNOWHEAD_PILLAR] = HintText::Sometimes({
            //obscure
            Text{"a #cold platform# contains", "une #plateforme froide# recèle", "una plataforma fría contiene"}});
    hintTable[ROAD_TO_SNOWHEAD_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #snowy cave# contains", "une #grotte assaillie de neige# contient", "una cueva nevada contiene"}});
//Pinnacle Rock
    hintTable[PINNACLE_ROCK_SEAHORSES] = HintText::Sometimes({
            //obscure
            Text{"a #fishy reunion# rewards", "une #réunion de poissons# octroie", "una reunión acuática recompensa con"}});
    hintTable[PINNACLE_ROCK_UPPER_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #marine trench# contains", "une #tranchée marine# contient", "una fosa marina contiene"}});
    hintTable[PINNACLE_ROCK_LOWER_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #marine trench# contains", "une #tranchée marine# contient", "una fosa marina contiene"}});
    hintTable[PINNACLE_ROCK_ZORA_EGG1] = HintText::Sometimes({
            //obscure
            Text{"in a #marine trench# rests", "une #tranchée marine# héberge", "en una fosa marina espera"}});
    hintTable[PINNACLE_ROCK_ZORA_EGG2] = HintText::Sometimes({
            //obscure
            Text{"in a #marine trench# rests", "une #tranchée marine# héberge", "en una fosa marina espera"}});
    hintTable[PINNACLE_ROCK_ZORA_EGG3] = HintText::Sometimes({
            //obscure
            Text{"in a #marine trench# rests", "une #tranchée marine# héberge", "en una fosa marina espera"}});
//Road to Ikana
    hintTable[ROAD_TO_IKANA_PILLAR_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #high chest# contains", "un #coffre haut-placé# contient", "un cofre en lo alto contiene"}});
    hintTable[ROAD_TO_IKANA_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #blocked cave# contains", "une #grotte bouchée# contient", "una cueva obstruida contiene"}});
//Road to Southern Swamp
    hintTable[ROAD_TO_SS_ARCHERY_1] = HintText::Sometimes({
            //obscure
            Text{"a #swamp game# rewards", "#si tu vises bien comme il faut#, tu gagnes", "un juego en el pantano recompensa con", "", "#s'tu vises bien correc'#, tu gagnes", ""}});
    hintTable[ROAD_TO_SS_ARCHERY_2] = HintText::Sometimes({
            //obscure
            Text{"a #swamp game# rewards", "#si tu vises bien comme il faut#, tu gagnes", "un juego en el pantano recompensa con", "", "#s'tu vises bien correc'#, tu gagnes", ""}});
    hintTable[ROAD_TO_SS_TREE] = HintText::Sometimes({
            //obscure
            Text{"a #batty tree# contains", "un #arbre saigneur# recèle", "un árbol repleto de alas negras tiene"}});
    hintTable[ROAD_TO_SWAMP_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #southern cave# contains", "une #grotte australe# contient", "una cueva en el sur contiene"}});
    hintTable[TINGLE_ROAD_TO_SS_WF] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende"}});
    hintTable[TINGLE_ROAD_TO_SS_SH] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells", "un #cartographe# vend", "un cartógrafo vende"}});
//Romani Ranch
    hintTable[ROMANI_RANCH_ALIEN_DEFENSE] = HintText::Sometimes({
            //obscure
            Text{"a #ranch invasion# rewards", "une #invasion de ranch# octroie", "una invasión al rancho recompensa con"}});
    hintTable[ROMANI_RANCH_DOG_RACE] = HintText::Sometimes({
            //obscure
            Text{"a #sporting event# rewards", "bien comprendre #les chien-chiens# octroie", "un evento deportivo recompensa con"}});
    hintTable[ROMANI_RANCH_GROG] = HintText::Sometimes({
            //obscure
            Text{"a #chicken lover# rewards", "un #amateur de cocottes# offre", "un amante de las gallinas recompensa con"}});
    hintTable[ROMANI_RANCH_CREMIA_ESCORT] = HintText::Sometimes({
            //obscure
            Text{"an #older sister# rewards", "une #grande sœur# détient", "una hermana mayor recompensa con"}});
    hintTable[ROMANI_RANCH_ROMANIS_GAME] = HintText::Sometimes({
            //obscure
            Text{"an #equine reunion# teaches", "une #réunion équestre# enseigne", "una reunión equina recompensa con"}});
    hintTable[ROMANI_RANCH_COW_1] = HintText::Sometimes({
            //obscure
            Text{"a #lost creature# gives", "#leur cible# prodigue", "una criatura perdida da"}});
    hintTable[ROMANI_RANCH_COW_2] = HintText::Sometimes({
            //obscure
            Text{"a #lost creature# gives", "#leur cible# prodigue", "una criatura perdida da"}});
    hintTable[ROMANI_RANCH_COW_3] = HintText::Sometimes({
            //obscure
            Text{"a #lost creature# gives", "#leur cible# prodigue", "una criatura perdida da"}});
    hintTable[DOGGY_RACETRACK_ROOF_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #day at the races# contains", "les #courses sont surplombées# par", "un día en las carreras contiene"}});
//S Clock Town
    hintTable[S_CLOCK_TOWN_SCRUB_TRADE] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# trades", "un #marchant citadin# échange", "un mercader en la ciudad intercambia por"}});
    hintTable[S_CLOCK_TOWN_POSTBOX] = HintText::Sometimes({
            //obscure
            Text{"a #correspondence box# contains", "un #boîte a correspondances# contient", "una caja de correspondencia contiene"}});
    hintTable[S_CLOCK_TOWN_CLOCK_TOWER_ENTRANCE] = HintText::Sometimes({
            //obscure
            Text{"the #tower doors# contain", "un #balcon ponctuel# recèle", "las puertas de la torre contienen"}});
    hintTable[S_CLOCK_TOWN_STRAW_ROOF_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #straw roof# contains", "un #toit de paille# recèle", "un techo de paja contiene"}});
    hintTable[S_CLOCK_TOWN_FINAL_DAY_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #carnival tower# contains", "le #labeur des charpentiers# révèlent", "la torre del carnaval contiene"}});
    hintTable[S_CLOCK_TOWN_BANK_REWARD_1] = HintText::Sometimes({
            //obscure
            Text{"a #keeper of wealth# rewards", "un #début d'épargne# confère", "un guardián de riquezas recompensa con"}});
    hintTable[S_CLOCK_TOWN_BANK_REWARD_2] = HintText::Sometimes({
            //obscure
            Text{"#interest# rewards", "#accumuler quatre chiffres# confère", "una comisión recompensa con"}});
    hintTable[S_CLOCK_TOWN_BANK_REWARD_3] = HintText::Sometimes({
            //obscure
            Text{"#being rich# rewards", "le #plafond de la fortune# confère", "ser rico recompensa con"}});
//Snowhead
    hintTable[SNOWHEAD_GREAT_FAIRY] = HintText::Sometimes({
            //obscure
            Text{"the #fairy of power# rewards", "la #fée de la force# prodigue", "la hada del poder recompensa con"}});
//Southern Swamp
    hintTable[SOUTHERN_SWAMP_MUSIC_STATUE] = HintText::Exclude({
            //obscure
            Text{"a #guiding owl# teaches", "un #sage hibou# enseigne", ""}});
    hintTable[SOUTHERN_SWAMP_KOUME] = HintText::Sometimes({
            //obscure
            Text{"a #witch# rewards", "une #sorcière soignée# octroie", "una bruja recompensa con"}});
    hintTable[SOUTHERN_SWAMP_KOTAKE] = HintText::Sometimes({
            //obscure
            Text{"a #sleeping witch# rewards", "une #sorcière somnolente# confie", "una bruja durmiente recompensa con"}});
    hintTable[SOUTHERN_SWAMP_KOTAKE_IN_WOODS] = HintText::Sometimes({
            //obscure
            Text{"a #witch# rewards", "une #sorcière inquiète# confie", "una bruja recompensa con"}});
    hintTable[SOUTHERN_SWAMP_SCRUB_TRADE] = HintText::Sometimes({
            //obscure
            Text{"a #southern merchant# trades", "un #marchand austral# vend", "un mercader del sur intercambia por"}});
    hintTable[SOUTHERN_SWAMP_PICTOGRAPH_WINNER] = HintText::Sometimes({
            //obscure
            Text{"a #swamp game# rewards", "gagner un #concours marécageux# octroie", "un juego del pantano recompensa con"}});
    hintTable[SOUTHERN_SWAMP_BOAT_ARCHERY] = HintText::Sometimes({
            //obscure
            Text{"a #swamp game# rewards", "#frôler un balai habilement# octroie", "un juego del pantano recompensa con"}});
    hintTable[SWAMP_TOURIST_CENTER_ROOF] = HintText::Sometimes({
            //obscure
            Text{"a #tourist center# contains", "un #toit touristique# recèle", "un centro turístico contiene"}});
    hintTable[SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #swampy cave# contains", "une #grotte marécageuse# contient", "una cueva pantanosa contiene"}});
    hintTable[SOUTHERN_SWAMP_SPIDER_HOUSE_REWARD] = HintText::Sometimes({
            //obscure
            Text{"a #swamp spider man# rewards", "un #homme-araignée# est maudit par", "un hombre araña del pantano recompensa con"}});
    hintTable[SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #mystery cave# contains", "une #grotte ponctuelle# contient", "una cueva misteriosa contiene"}});
    hintTable[SOUTHERN_SWAMP_KOTAKE_MUSHROOM_SALE] = HintText::Sometimes({
            //obscure
            Text{"a #sleeping witch# rewards", "une #apothicaire# échange", "una bruja durmiente recompensa con"}});
    //hintTable[SOUTHERN_SWAMP_PICTOGRAPH_STANDARD] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "un #cliché banal# octroie", "una toma pantanosa recompensa con"}});
    //hintTable[SOUTHERN_SWAMP_PICTOGRAPH_GOOD] = HintText::Sometimes({
    //        //obscure
    //        Text{"**ENGLISH**", "un #cliché convenable# octroie", "una toma pantanosa recompensa con"}});
    hintTable[SOUTHERN_SWAMP_SCRUB_PURCHASE] = HintText::Sometimes({
            //obscure
            Text{"a #southern merchant# sells", "un #marchand austral# vend", "un mercader del sur vende"}});
    hintTable[SOUTHERN_SWAMP_SCRUB_PURCHASE_CLEAR] = HintText::Sometimes({
            //obscure
            Text{"a #southern merchant# sells", "un #marchand austral# vend", "un mercader del sur vende"}});
    hintTable[SOUTHERN_SWAMP_SCRUB_TRADE_CLEAR] = HintText::Sometimes({
            //obscure
            Text{"a #southern merchant# trades", "un #marchand austral# échange", "un mercader del sur intercambia por"}});
    hintTable[SWAMP_TOURIST_CENTER_ROOF_CLEAR] = HintText::Sometimes({
            //obscure
            Text{"a #tourist center# contains", "un #toit touristique# recèle", "un centro turístico contiene"}});
    hintTable[POTION_SHOP_ITEM_1] = HintText::Sometimes({
            //obscure
            Text{"a #potion maker# sells", "une #apothicaire# vend", "una fabricante de pociones vende"}});
    hintTable[POTION_SHOP_ITEM_2] = HintText::Sometimes({
            //obscure
            Text{"a #potion maker# sells", "une #apothicaire# vend", "una fabricante de pociones vende"}});
    hintTable[POTION_SHOP_ITEM_3] = HintText::Sometimes({
            //obscure
            Text{"a #potion maker# sells", "une #apothicaire# vend", "una fabricante de pociones vende"}});
//Stock Pot Inn
    hintTable[STOCKPOTINN_RESERVATION] = HintText::Sometimes({
            //obscure
            Text{"#checking-in# rewards", "#à l'accueil#, M. @-goro recevra", "registrarse recompensa con"}});
    hintTable[STOCKPOTINN_MIDNIGHT_MEETING] = HintText::Sometimes({
            //obscure
            Text{"a #late meeting# rewards", "un #rendez-vous nocturne# octroie", "una reunión tardía recompensa con"}});
    hintTable[STOCKPOTINN_TOILET_HAND] = HintText::Sometimes({
            //obscure
            Text{"a #strange palm# rewards", "une #paume étrange# offre", "una palma extraña recompensa con"}});
    hintTable[STOCKPOTINN_GRANDMA_SHORT_STORY] = HintText::Sometimes({
            //obscure
            Text{"an #old lady# rewards", "#s'instruire sur les traditions# octroie", "una anciana recompensa con"}});
    hintTable[STOCKPOTINN_GRANDMA_LONG_STORY] = HintText::Sometimes({
            //obscure
            Text{"an #old lady# rewards", "#s'instruire sur les traditions# octroie", "una anciana recompensa con"}});
    hintTable[STOCKPOTINN_ANJU_AND_KAFEI] = HintText::Sometimes({
            //obscure
            Text{"a #lovers' reunion# rewards", "une #réunion d'amants# octroie", "una reunión de amantes recompensa con"}});
    hintTable[STOCKPOTINN_STAFF_ROOM_CHEST] = HintText::Sometimes({
            //obscure
            Text{"an #employee room# contains", "les #employés# ont accès exclusif sur", "un cuarto de empleados contiene"}});
    hintTable[STOCKPOTINN_GUEST_ROOM_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #guest bedroom# contains", "une #chambre réservée# contient", "un cuarto de huéspedes contiene"}});
//Stone Tower
    hintTable[STONE_TOWER_INVERTED_RIGHT_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #sky below# contains", "le #ciel-sous-pied# cache", "un cielo por debajo contiene"}});
    hintTable[STONE_TOWER_INVERTED_CENTER_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #sky below# contains", "le #ciel-sous-pied# cache", "un cielo por debajo contiene"}});
    hintTable[STONE_TOWER_INVERTED_LEFT_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #sky below# contains", "le #ciel-sous-pied# cache", "un cielo por debajo contiene"}});
//Termina Field
    hintTable[TERMINA_FIELD_MOONS_TEAR] = HintText::Sometimes({
            //obscure
            Text{"a #falling star# contains", "une #étoile filante# contient", "una estrella fugaz contiene"}});
    hintTable[TERMINA_FIELD_GOSSIP_STONES] = HintText::Sometimes({
            //obscure
            Text{"#mysterious stones# reward", "#mes congénères# offrent", "piedras misteriosas recompensan con"}});
    hintTable[TERMINA_FIELD_BUSINESS_SCRUB] = HintText::Sometimes({
            //obscure
            Text{"a #hidden merchant# sells", "un #marchand furtif# vend", "un mercader oculto vende"}});
    hintTable[TERMINA_FIELD_PEAHAT_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #hollow ground# contains", "vaincre des #feuilles qui tournent# octroie", "un suelo hueco contiene"}});
    hintTable[TERMINA_FIELD_DODONGO_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #hollow ground# contains", "exterminer des #lézards explosifs# octroie", "un suelo hueco contiene"}});
    hintTable[TERMINA_FIELD_BIO_BABA_GROTTO_BEEHIVE] = HintText::Sometimes({
            //obscure
            Text{"a #beehive# contains", "une #ruche# contient", "un panal contiene"}});
    hintTable[TERMINA_FIELD_KAMARO] = HintText::Sometimes({
            //obscure
            Text{"a #dancer# rewards", "une #âme d'artiste# lègue", "un bailarín recompensa con"}});
    hintTable[TERMINA_FIELD_PILLAR_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #hollow pillar# contains", "un #pilier creux# contient", "un pilar hueco"}});
    hintTable[TERMINA_FIELD_GRASS_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #grassy cave# contains", "une #grotte sous des herbes# contient", "una cueva herbosa contiene"}});
    hintTable[TERMINA_FIELD_UNDERWATER_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #sunken chest# contains", "un #coffre inondé des plaines# contient", "un cofre hundido contiene"}});
    hintTable[TERMINA_FIELD_GRASS_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #grassy chest# contains", "un #coffre herbeux# contient", "un cofre herboso contiene"}});
    hintTable[TERMINA_FIELD_STUMP_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #tree chest# contains", "un #coffre-sur-souche# contient", "un cofre en el árbol contiene"}});
    hintTable[TERMINA_FIELD_GROTTO_COW1] = HintText::Sometimes({
            //obscure
            Text{"a #lost creature# gives", "un #bovin des plaines# prodigue", "una criatura perdida da"}});
    hintTable[TERMINA_FIELD_GROTTO_COW2] = HintText::Sometimes({
            //obscure
            Text{"a #lost creature# gives", "un #bovin des plaines# prodigue", "una criatura perdida da"}});
//Twin Islands
    hintTable[HOT_SPRING_WATER_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #steamy grotto# contains", "un #sauna naturel# contient", "una gruta tórrida contiene"}});
    hintTable[TWIN_ISLANDS_GORON_RACE] = HintText::Sometimes({
            //obscure
            Text{"a #sporting event# rewards", "une #compétition épineuse# offre", "un evento deportivo recompensa con"}});
    hintTable[TWIN_ISLANDS_GORON_RACETRACK_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #hidden cave# contains", "la #grotte du conifère solitaire# contient", "una cueva oculta contiene"}});
    hintTable[TWIN_ISLANDS_UNDERWATER_RAMP_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #spring treasure# contains", "un #trésor printanier immergé# contient", "un tesoro de primavera contiene"}});
    hintTable[TWIN_ISLANDS_CAVE_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #sunken springtime treasure# contains", "un #trésor printanier immergé# contient", "un tesoro de primavera hundido contiene"}});
    hintTable[TWIN_ISLANDS_LULLABY_INTRO] = HintText::Sometimes({
            //obscure
            Text{"a #goron elder# teaches", "un #ancien aux doigts froids# enseigne", "un anciano goron enseña"}});
    hintTable[TINGLE_TWIN_ISLANDS_SH] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells ", "un #cartographe# vend", "un cartógrafo vende"}});
    hintTable[TINGLE_TWIN_ISLANDS_RR] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells ", "un #cartographe# vend", "un cartógrafo vende"}});
    hintTable[TINGLE_TWIN_ISLANDS_SH_SPRING] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells ", "un #cartographe# vend", "un cartógrafo vende"}});
    hintTable[TINGLE_TWIN_ISLANDS_RR_SPRING] = HintText::Sometimes({
            //obscure
            Text{"a #map maker# sells ", "un #cartographe# vend", "un cartógrafo vende"}});
//W Clock Town
    hintTable[W_CLOCK_TOWN_BOMB_BAG_BUY] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "l'#artificier citadin# est contraint à vendre", "un mercader de la ciudad vende"}});
    hintTable[W_CLOCK_TOWN_BIG_BOMB_BAG_BUY] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "l'#artificier citadin# compte vendre", "un mercader de la ciudad vende"}});
    hintTable[W_CLOCK_TOWN_POSTMANS_GAME] = HintText::Sometimes({
            //obscure
            Text{"a #delivery person# rewards", "un #livreur concentré# offre", "un repartidor recompensa con"}});
    hintTable[W_CLOCK_TOWN_ROSA_SISTERS] = HintText::Sometimes({
            //obscure
            Text{"#traveling sisters# reward", "#prendre des disciples# octroie", "las hermanas viajeras recompensan con"}});
    hintTable[W_CLOCK_TOWN_SWORDSMANS_SCHOOL] = HintText::Sometimes({
            //obscure
            Text{"a #town game# rewards", "les #fines lames# reçoivent", "un juego en la ciudad recompensa con"}});
    hintTable[W_CLOCK_TOWN_ALL_NIGHT_MASK_BUY] = HintText::Sometimes({
            //obscure
            Text{"a #shady town merchant# sells", "un #commerce suspect# vend", "un mercader sospechoso en la ciudad vende"}});
    hintTable[W_CLOCK_TOWN_BOMB_SHOP_GORON] = HintText::Sometimes({
            //obscure
            Text{"a #town goron merchant# sells", "les #gorons accrédités# peuvent acheter", "un mercader goron en la ciudad vende"}});
    hintTable[W_CLOCK_TOWN_CURIOSITY_BOMB_BAG] = HintText::Sometimes({
            //obscure
            Text{"a #shady town merchant# sells", "un #commerce suspect# peut recevoir", "un mercader sospechoso en la ciudad vende"}});
    //hintTable[W_CLOCK_TOWN_LOTTERY] = HintText::Sometimes({
    //        //obscure
    //        Text{"a #town lucky numbers# game", "un #numéro gagnant# octroie", "un juego de números de suerte en la ciudad recompensa con"}});
    hintTable[TRADING_POST_ITEM_1] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende"}});
    hintTable[TRADING_POST_ITEM_2] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende"}});
    hintTable[TRADING_POST_ITEM_3] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende"}});
    hintTable[TRADING_POST_ITEM_4] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende"}});
    hintTable[TRADING_POST_ITEM_5] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende"}});
    hintTable[TRADING_POST_ITEM_6] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende"}});
    hintTable[TRADING_POST_ITEM_7] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende"}});
    hintTable[TRADING_POST_ITEM_8] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "un #pêcheur retraité# vend", "un mercader en la ciudad vende"}});
    hintTable[BOMB_SHOP_ITEM_1] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "l'#artificier citadin# vend", "un mercader en la ciudad vende"}});
    hintTable[BOMB_SHOP_ITEM_2] = HintText::Sometimes({
            //obscure
            Text{"a #town merchant# sells", "l'#artificier citadin# vend", "un mercader en la ciudad vende"}});
    //hintTable[BOMB_SHOP_ITEM_3] = HintText::Sometimes({
    //        //obscure
    //        Text{"a #town merchant# sells", "l'#artificier citadin# vend", "un mercader en la ciudad vende"}});
//Woodfall
    hintTable[WOODFALL_BRIDGE_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #swamp chest# contains", "un #coffre gardé par une peste# contient", "un cofre en el pantano contiene"}});
    hintTable[WOODFALL_BEHIND_OWL_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #swamp chest# contains", "un #coffre qui surveille un hibou# contient", "un cofre en el pantano contiene"}});
    hintTable[ENTRANCE_TO_WOODFALL_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #swamp chest# contains", "un #coffre au ras du poison# contient", "un cofre en el pantano contiene"}});
    hintTable[WOODFALL_GREAT_FAIRY] = HintText::Sometimes({
            //obscure
            Text{"the #fairy of wisdom# rewards", "la #fée de la sagesse# prodigue", "la hada de la sabiduría recompensa con"}});
//Zora Cape
    hintTable[ZORA_CAPE_GREAT_FAIRY] = HintText::Sometimes({
            //obscure
            Text{"the #fairy of courage# rewards", "la #fée du courage# prodigue", "la hada del valor recompensa con"}});
    hintTable[ZORA_CAPE_BEAVER_RACE_1] = HintText::Sometimes({
            //obscure
            Text{"a #river dweller# rewards", "de #gros rongeurs mouillés# détiennent", "un morador del río recompensa con"}});
    hintTable[ZORA_CAPE_BEAVER_RACE_2] = HintText::Sometimes({
            //obscure
            Text{"a #river dweller# rewards", "de #gros rongeurs mouillés# détiennent", "un morador del río recompensa con"}});
    hintTable[ZORA_CAPE_LIKE_LIKE] = HintText::Sometimes({
            //obscure
            Text{"a #shield eater# contains", "un #mange-écu# contient", "un devorador de escudos resguarda"}});
    hintTable[ZORA_CAPE_LEDGE_NO_TREE] = HintText::Sometimes({
            //obscure
            Text{"a #high place# contains", "#escalader une rivière# dévoile", "un lugar en lo alto contiene"}});
    hintTable[ZORA_CAPE_LEDGE_WITH_TREE] = HintText::Sometimes({
            //obscure
            Text{"a #high place# contains", "#escalader une rivière# dévoile", "un lugar en lo alto contiene"}});
    hintTable[ZORA_CAPE_GROTTO_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #beach cave# contains", "une #grotte de pêcheur# contient", "una cueva en la playa contiene"}});
    hintTable[ZORA_CAPE_UNDERWATER_CHEST] = HintText::Sometimes({
            //obscure
            Text{"a #sunken chest# contains ", "un #coffre côtier submergé# contient", "un cofre hundido contiene"}});
//Zora Hall
    hintTable[ZORA_HALL_SCRUB_TRADE] = HintText::Sometimes({
            //obscure
            Text{"a #western merchant# trades", "un #marchant occidental# échange", "un mercader del oeste intercambia por"}});
    hintTable[ZORA_HALL_EVAN] = HintText::Sometimes({
            //obscure
            Text{"a #musician# rewards", "#se faire voler une chanson# octroie", "un músico recompensa con"}});
    hintTable[ZORA_HALL_LULU_ROOM_LEDGE] = HintText::Sometimes({
            //obscure
            Text{"the #singer's room# contains", "la #chambre d'une chanteuse# contient", "el cuarto de la cantante contiene"}});
    hintTable[ZORA_HALL_SCRUB_PURCHASE] = HintText::Sometimes({
            //obscure
            Text{"a #western merchant# sells", "un #marchant occidental# vend", "un mercader del oeste vende"}});
    //hintTable[ZORA_HALL_STAGE_LIGHTS] = HintText::Sometimes({
    //        //obscure
    //        Text{"a #tech crew# gives", "aider l'#équipe technique# octroie", "un fan"}});
    //hintTable[ZORA_HALL_BAD_PHOTO_LULU] = HintText::Sometimes({
    //        //obscure
    //        Text{"a #fan# gives", "un #fan insatisfait# offre", "un fan"}});
    //hintTable[ZORA_HALL_GOOD_PHOTO_LULU] = HintText::Sometimes({
    //        //obscure
    //        Text{"a #fan# gives", "un #fan satisfait# offre", "un fan"}});
    hintTable[ZORA_SHOP_ITEM_1] = HintText::Sometimes({
            //obscure
            Text{"a #zora merchant# sells", "une #boutique iodée# vend", "un mercader zora vende"}});
    hintTable[ZORA_SHOP_ITEM_2] = HintText::Sometimes({
            //obscure
            Text{"a #zora merchant# sells", "une #boutique iodée# vend", "un mercader zora vende"}});
    hintTable[ZORA_SHOP_ITEM_3] = HintText::Sometimes({
            //obscure
            Text{"a #zora merchant# sells", "une #boutique iodée# vend", "un mercader zora vende"}});

    /*-------------------------
    |  DUNGEON LOCATION TEXT  |
    -------------------------*/
    hintTable[WOODFALL_TEMPLE_HEROS_BOW_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #sleeping temple# contains", "le #temple endormi# contient", "el templo durmiente contiene"}});
    hintTable[WOODFALL_TEMPLE_MAP_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #sleeping temple# contains", "le #temple endormi# contient", "el templo durmiente contiene"}});
    hintTable[WOODFALL_TEMPLE_COMPASS_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #sleeping temple# contains", "le #temple endormi# contient", "el templo durmiente contiene"}});
    hintTable[WOODFALL_TEMPLE_BOSS_KEY_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #sleeping temple# contains", "le #temple endormi# contient", "el templo durmiente contiene"}});
    hintTable[WOODFALL_TEMPLE_SMALL_KEY_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #sleeping temple# contains", "le #temple endormi# contient", "el templo durmiente contiene"}});
    hintTable[WOODFALL_TEMPLE_DEKU_PRINCESS] = HintText::Exclude({
            //obscure
            Text{"the #sleeping temple# rewards", "le #temple endormi# détient", "el templo durmiente contiene"}});
    hintTable[WF_SF_ENTRANCE_FAIRY] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es"}});
    hintTable[WF_SF_ENTRANCE_PLATFORM] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es"}});
    hintTable[WF_SF_MAIN_ROOM_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es"}});
    hintTable[WF_SF_MAIN_ROOM_SWITCH] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es"}});
    hintTable[WF_SF_PRE_BOSS_LOWER_RIGHT_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es"}});
    hintTable[WF_SF_PRE_BOSS_UPPER_RIGHT_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es"}});
    hintTable[WF_SF_PRE_BOSS_UPPER_LEFT_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es"}});
    hintTable[WF_SF_PRE_BOSS_PILLAR_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es"}});
    hintTable[WF_SF_DEKU_BABA] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es"}});
    hintTable[WF_SF_DRAGONFLY_ROOM_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es"}});
    hintTable[WF_SF_SKULLTULA] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es"}});
    hintTable[WF_SF_DARK_ROOM] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es"}});
    hintTable[WF_SF_JAR_FAIRY] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es"}});
    hintTable[WF_SF_BRIDGE_ROOM_BEEHIVE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es"}});
    hintTable[WF_SF_PLATFORM_ROOM_BEEHIVE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée rose# est", "una hada perdida es"}});
    hintTable[ODOLWA_HEART_CONTAINER] = HintText::Exclude({
            //obscure
            Text{"a #masked evil# contains", "occire le #guerrier de la jungle# octroie", "un mal enmascarado contiene"}});
    hintTable[GIANTS_OATH_TO_ORDER] = HintText::Exclude({
            //obscure
            Text{"a #gentile giant# teaches", "un #gentil géant# enseigne", ""}});
//Snowhead Temple
    hintTable[SNOWHEAD_TEMPLE_FIRE_ARROW_CHEST] = HintText::Exclude({
            //obscure
            Text{"an #icy temple# contains", "un #temple enneigé# contient", "un templo helado contiene"}});
    hintTable[SNOWHEAD_TEMPLE_MAP_CHEST] = HintText::Exclude({
            //obscure
            Text{"an #icy temple# contains", "un #temple enneigé# contient", "un templo helado contiene"}});
    hintTable[SNOWHEAD_TEMPLE_COMPASS_CHEST] = HintText::Exclude({
            //obscure
            Text{"an #icy temple# contains", "un #temple enneigé# contient", "un templo helado contiene"}});
    hintTable[SNOWHEAD_TEMPLE_BOSS_KEY_CHEST] = HintText::Exclude({
            //obscure
            Text{"an #icy temple# contains", "un #temple enneigé# contient", "un templo helado contiene"}});
    hintTable[SNOWHEAD_TEMPLE_BLOCK_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"an #icy temple# contains", "un #temple enneigé# contient", "un templo helado contiene"}});
    hintTable[SNOWHEAD_TEMPLE_ICICLE_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"an #icy temple# contains", "un #temple enneigé# contient", "un templo helado contiene"}});
    hintTable[SNOWHEAD_TEMPLE_BRIDGE_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"an #icy temple# contains", "un #temple enneigé# contient", "un templo helado contiene"}});
    hintTable[SH_SF_SNOW_ROOM_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es"}});
    hintTable[SH_SF_CEILING_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es"}});
    hintTable[SH_SF_DINOLFOS_1] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es"}});
    hintTable[SH_SF_DINOLFOS_2] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es"}});
    hintTable[SH_SF_BRIDGE_ROOM_LEDGE_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es"}});
    hintTable[SH_SF_BRIDGE_ROOM_PILLAR_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es"}});
    hintTable[SH_SF_MAP_ROOM_FAIRY] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es"}});
    hintTable[SH_SF_MAP_ROOM_LEDGE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es"}});
    hintTable[SH_SF_BASEMENT] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es"}});
    hintTable[SH_SF_TWIN_BLOCK] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es"}});
    hintTable[SH_SF_ICICLE_ROOM_WALL] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es"}});
    hintTable[SH_SF_MAIN_ROOM_WALL] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es"}});
    hintTable[SH_SF_PILLAR_FREEZARDS] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es"}});
    hintTable[SH_SF_ICE_PUZZLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es"}});
    hintTable[SH_SF_CRATE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée verte# est", "una hada perdida es"}});
    hintTable[GOHT_HEART_CONTAINER] = HintText::Exclude({
            //obscure
            Text{"a #masked evil# contains", "abattre un #gros taureau# détient", "un mal enmascarado contiene"}});
//Great bay Temple
    hintTable[GBT_ICE_ARROW_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #murky watered temple# contains", "le #temple en eaux troubles# contient", "el templo de aguas turbias contiene"}});
    hintTable[GBT_MAP_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #murky watered temple# contains", "le #temple en eaux troubles# contient", "el templo de aguas turbias contiene"}});
    hintTable[GBT_COMPASS_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #murky watered temple# contains", "le #temple en eaux troubles# contient", "el templo de aguas turbias contiene"}});
    hintTable[GBT_BOSS_KEY_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #murky watered temple# contains", "le #temple en eaux troubles# contient", "el templo de aguas turbias contiene"}});
    hintTable[GBT_SMALL_KEY_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #murky watered temple# contains", "le #temple en eaux troubles# contient", "el templo de aguas turbias contiene"}});
    hintTable[GBT_SF_SKULLTULA] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es"}});
    hintTable[GBT_SF_WATER_CONTROL_UNDERWATER_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es"}});
    hintTable[GBT_SF_WATERWHEEL_ROOM_LOWER] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es"}});
    hintTable[GBT_SF_WATERWHEEL_ROOM_UPPER] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es"}});
    hintTable[GBT_SF_GREEN_VALVE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es"}});
    hintTable[GBT_SF_SEESAW_ROOM] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es"}});
    hintTable[GBT_SF_ENTRANCE_TORCHES] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es"}});
    hintTable[GBT_SF_BIO_BABAS] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es"}});
    hintTable[GBT_SF_UNDERWATER_BARREL] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es"}});
    hintTable[GBT_SF_WHIRLPOOL_BARREL] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es"}});
    hintTable[GBT_SF_WHIRLPOOL_JAR] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es"}});
    hintTable[GBT_SF_DEXIHANDS_JAR] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es"}});
    hintTable[GBT_SF_LEDGE_JAR] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es"}});
    hintTable[GBT_SF_PRE_BOSS_ROOM_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es"}});
    hintTable[GBT_SF_PRE_BOSS_ROOM_UNDERWATER_BUBBLE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée violette# est", "una hada perdida es"}});
    hintTable[GYORG_HEART_CONTAINER] = HintText::Exclude({
            //obscure
            Text{"a #masked evil# contains", "abattre un #énorme poisson# octroie", "un mal enmascarado contiene"}});
//Stone Tower Temple
    hintTable[STONE_TOWER_TEMPLE_MAP_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene"}});
    hintTable[STONE_TOWER_TEMPLE_COMPASS_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene"}});
    hintTable[STONE_TOWER_TEMPLE_BOSS_KEY_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene"}});
    hintTable[STONE_TOWER_TEMPLE_ARMOS_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene"}});
    hintTable[STONE_TOWER_TEMPLE_BRIDGE_SWITCH_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene"}});
    hintTable[STONE_TOWER_TEMPLE_UPDRAFT_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene"}});
    hintTable[STONE_TOWER_TEMPLE_DEATH_ARMOS_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene"}});
    hintTable[STONE_TOWER_TEMPLE_UPRIGHT_DEATH_ARMOS_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene"}});
    hintTable[STONE_TOWER_TEMPLE_LIGHT_ARROW_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene"}});
    hintTable[STONE_TOWER_TEMPLE_GIANTS_MASK_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #rocky temple# contains", "un #temple sens dessus dessous# contient", "un templo rocoso contiene"}});
    hintTable[ST_SF_MIRROR_SUN_BLOCK] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es"}});
    hintTable[ST_SF_LAVA_ROOM_LEDGE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es"}});
    hintTable[ST_SF_LAVA_ROOM_FIRE_RING] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es"}});
    hintTable[ST_SF_EYEGORE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es"}});
    hintTable[ST_SF_UPDRAFT_FIRE_RING] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es"}});
    hintTable[ST_SF_MIRROR_SUN_SWITCH] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es"}});
    hintTable[ST_SF_BOSS_WARP] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es"}});
    hintTable[ST_SF_WIZZROBE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es"}});
    hintTable[ST_SF_DEATH_ARMOS] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es"}});
    hintTable[ST_SF_UPDRAFT_FROZEN_EYE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es"}});
    hintTable[ST_SF_THIN_BRIDGE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es"}});
    hintTable[ST_SF_BASEMENT_LEDGE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es"}});
    hintTable[ST_SF_STATUE_EYE] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es"}});
    hintTable[ST_SF_UNDERWATER] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es"}});
    hintTable[ST_SF_BRIDGE_CRYSTAL] = HintText::Exclude({
            //obscure
            Text{"a #lost fairy# is", "une #fée jaune# est", "una hada perdida es"}});
    hintTable[TWINMOLD_HEART_CONTAINER] = HintText::Exclude({
            //obscure
            Text{"a #masked evil# contains", "occire les #mille-pattes jumeaux# octroie", "un mal enmascarado contiene"}});
//Pirate Fortress
    hintTable[PF_INTERIOR_HOOKSHOT_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene"}});
    hintTable[PF_INT_LOWER_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene"}});
    hintTable[PF_INT_UPPER_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene"}});
    hintTable[PF_INT_TANK_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene"}});
    hintTable[PF_INT_GUARD_ROOM_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene"}});
    hintTable[PF_CAGE_ROOM_SHALLOW_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene"}});
    hintTable[PF_CAGE_ROOM_DEEP_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene"}});
    hintTable[PF_MAZE_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene"}});
    hintTable[PF_SEWER_CAGE] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene"}});
    hintTable[PF_EXTERIOR_LOG_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene"}});
    hintTable[PF_EXTERIOR_SAND_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene"}});
    hintTable[PF_EXTERIOR_CORNER_CHEST] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene"}});
    hintTable[PF_INT_INVISIBLE_SOLDIER] = HintText::Exclude({
            //obscure
            Text{"the #home of pirates# contains", "le #foyer des pirates# contient", "el hogar de las piratas contiene"}});
    hintTable[PF_INT_HOOKSHOT_ROOM_ZORA_EGG] = HintText::Exclude({
            //obscure
            Text{"in the #home of pirates# rests", "le #foyer des pirates# héberge", "en el hogar de las piratas yace"}});
    hintTable[PF_INT_GUARD_ROOM_ZORA_EGG] = HintText::Exclude({
            //obscure
            Text{"in the #home of pirates# rests", "le #foyer des pirates# héberge", "en el hogar de las piratas yace"}});
    hintTable[PF_INT_BARREL_MAZE_ZORA_EGG] = HintText::Exclude({
            //obscure
            Text{"in the #home of pirates# rests", "le #foyer des pirates# héberge", "en el hogar de las piratas yace"}});
    hintTable[PF_INT_LAVA_ROOM_ZORA_EGG] = HintText::Exclude({
            //obscure
            Text{"in the #home of pirates# rests", "le #foyer des pirates# héberge", "en el hogar de las piratas yace"}});
//Beneath the Well
    hintTable[BENEATH_THE_WELL_MIRROR_SHIELD_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #frightful exchange# contains", "le #marché des revenants# contient", "un intercambio espantoso contiene"}});
    hintTable[WELL_LEFT_PATH_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #frightful exchange# contains", "le #marché des revenants# contient", "un intercambio espantoso contiene"}});
    hintTable[WELL_RIGHT_PATH_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #frightful exchange# contains", "le #marché des revenants# contient", "un intercambio espantoso contiene"}});
    hintTable[BENEATH_THE_WELL_COW] = HintText::Exclude({
            //obscure
            Text{"a #lost creature# gives", "la #source laitière des puits# prodigue", "una criatura perdida da"}});
//Ikana Castle
    hintTable[IKANA_CASTLE_PILLAR] = HintText::Exclude({
            //obscure
            Text{"a #fiery pillar# contains", "un #pilier enflammé# garde", "un pilar en llamas contiene"}});
    hintTable[IKANA_CASTLE_IKANA_KING] = HintText::Exclude({
            //obscure
            Text{"a #fallen king# teaches", "un #roi déchu# enseigne", "un rey caído enseña"}});
//Secret Shrine
    hintTable[SECRET_SHRINE_DINOLFOS_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #secret place# contains", "#deux fois deux cœurs# débloque", "un lugar secreto contiene"}});
    hintTable[SECRET_SHRINE_WIZZROBE_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #secret place# contains", "#huit cœurs# débloquent", "un lugar secreto contiene"}});
    hintTable[SECRET_SHRINE_WART_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #secret place# contains", "une #douzaine de cœurs# débloquent", "un lugar secreto contiene"}});
    hintTable[SECRET_SHRINE_GARO_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #secret place# contains", "#seize cœurs# débloquent", "un lugar secreto contiene"}});
    hintTable[SECRET_SHRINE_FINAL_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #secret place# contains", "#triompher de moult revanches# octroie", "un lugar secreto contiene"}});
//The Moon
    hintTable[THE_MOON_DEKU_TRIAL_BONUS] = HintText::Exclude({
            //obscure
            Text{"a #masked child's game# contains", "un #cache-cache feuillu# recèle", "un juego de niños enmascarados contiene"}});
    hintTable[THE_MOON_GORON_TRIAL_BONUS] = HintText::Exclude({
            //obscure
            Text{"a #masked child's game# contains", "un #cache-cache roulant# recèle", "un juego de niños enmascarados contiene"}});
    hintTable[THE_MOON_ZORA_TRIAL_BONUS] = HintText::Exclude({
            //obscure
            Text{"a #masked child's game# contains", "un #cache-cache aquatique# recèle", "un juego de niños enmascarados contiene"}});
    hintTable[THE_MOON_LINK_TRIAL_BONUS] = HintText::Exclude({
            //obscure
            Text{"a #masked child's game# contains", "un #cache-cache hostile# recèle", "un juego de niños enmascarados contiene"}});
    hintTable[THE_MOON_GARO_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #masked child's game# contains", "un #cache-cache hostile# recèle", "un juego de niños enmascarados contiene"}});
    hintTable[THE_MOON_IRON_KNUCKLE_CHEST] = HintText::Exclude({
            //obscure
            Text{"a #masked child's game# contains", "un #cache-cache hostile# recèle", "un juego de niños enmascarados contiene"}});
    hintTable[THE_MOON_MAJORA_CHILD] = HintText::Exclude({
            //obscure
            Text{"the #lonely child# rewards", "l'#enfant isolé# décerne", "el niño solitario recompensa con"}});
//Southern Swamp Skulltula House
    hintTable[SSH_MAIN_ROOM_NEAR_CEILING] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_MAIN_ROOM_WATER] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_MAIN_ROOM_LOWER_LEFT_SOIL] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_MAIN_ROOM_LOWER_RIGHT_SOIL] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_MAIN_ROOM_UPPER_SOIL] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_MAIN_ROOM_PILLAR] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_MAIN_ROOM_UPPER_PILLAR] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_MAIN_ROOM_JAR] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_MONUMENT_ROOM_CRATE_1] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_MONUMENT_ROOM_CRATE_2] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_MONUMENT_ROOM_TORCH] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_MONUMENT_ROOM_ON_MONUMENT] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_MONUMENT_ROOM_LOWER_WALL] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_GOLD_ROOM_NEAR_CEILING] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_GOLD_ROOM_PILLAR] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_GOLD_ROOM_BEEHIVE] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_GOLD_ROOM_WALL] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_POT_ROOM_JAR] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_POT_ROOM_POT_1] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_POT_ROOM_POT_2] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_POT_ROOM_BEHIND_VINES] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_POT_ROOM_WALL] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_POT_ROOM_BEEHIVE_1] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_POT_ROOM_BEEHIVE_2] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_TREE_ROOM_TREE_1] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_TREE_ROOM_TREE_2] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_TREE_ROOM_TREE_3] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_TREE_ROOM_GRASS_1] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_TREE_ROOM_GRASS_2] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
    hintTable[SSH_TREE_ROOM_BEEHIVE] = HintText::Exclude({
            //obscure
            Text{"a #swampy gold spider# is", "une #âme d'or marécageuse# est", "una araña dorada es"}});
//Oceanside spider House
    hintTable[OSH_ENTRANCE_LEFT_WALL] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_ENTRANCE_RIGHT_WALL] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_ENTRANCE_WEB] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_LIBRARY_HOLE_BEHIND_PICTURE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_LIBRARY_HOLE_BEHIND_CABINET] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_LIBRARY_ON_CORNER_BOOKSHELF] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_LIBRARY_CEILING_EDGE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_LIBRARY_BEHIND_BOOKCASE_1] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_LIBRARY_BEHIND_BOOKCASE_2] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_LIBRARY_BEHIND_PICTURE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_SECOND_ROOM_CEILING_EDGE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_SECOND_ROOM_CEILING_PLANK] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_SECOND_ROOM_JAR] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_SECOND_ROOM_WEBBED_HOLE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_SECOND_ROOM_WEBBED_POT] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_SECOND_ROOM_UPPER_POT] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_SECOND_ROOM_BEHIND_SKULL_1] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_SECOND_ROOM_BEHIND_SKULL_2] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_SECOND_ROOM_LOWER_POT] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_STORAGE_ROOM_CEILING_WEB] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_STORAGE_ROOM_BEHIND_CRATE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_STORAGE_ROOM_WALL] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_STORAGE_ROOM_CRATE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_STORAGE_ROOM_BARREL] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_COLORED_SKULLS_CEILING_EDGE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_COLORED_SKULLS_CHANDELIER_1] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_COLORED_SKULLS_CHANDELIER_2] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_COLORED_SKULLS_CHANDELIER_3] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_COLORED_SKULLS_BEHIND_PICTURE] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});
    hintTable[OSH_COLORED_SKULLS_POT] = HintText::Exclude({
            //obscure
            Text{"a #coastal gold spider# is", "une #âme d'or côtière# est", "una araña dorada es"}});

    /*----------------------
    |   REGION HINT TEXT   |
    ----------------------*/
    hintTable[LINKS_POCKET] = HintText::Region({Text{"Your Pocket", "tes poches", ""}});
    hintTable[N_CLOCK_TOWN] = HintText::Region({Text{"North Clock Town", "Cadranbourg-Nord", "Norte de la Ciudad Reloj", "", "le nord de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_FAIRY_FOUNTAIN] = HintText::Region({Text{"Clock Town’s Fairy Fountain", "la fontaine de fées de Cadranbourg", "Fuente de las hadas de Ciudad Reloj", "", "la fontaine de fées de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_DEKU_PLAYGROUND] = HintText::Region({Text{"the Deku Playground", "l'aire de jeux des pestes mojo", "Campo de Juegos Deku"}});
    hintTable[E_CLOCK_TOWN] = HintText::Region({Text{"East Clock Town", "Cadranbourg-Est", "Este de la Ciudad Reloj", "", "l'est de Bourg-Clocher", ""}});
    hintTable[STOCKPOTINN] = HintText::Region({Text{"the Stock Pot Inn", "l’Auberge de la Marmite", "Posada del Puchero", "", "l'auberge de Bourg-Clocher", ""}});
    hintTable[STOCKPOTINN_GUEST_ROOM] = HintText::Region({Text{"the Stock Pot Inn", "l’Auberge de la Marmite", "Posada del Puchero", "", "l'auberge de Bourg-Clocher", ""}});
    hintTable[STOCKPOTINN_STAFF_ROOM] = HintText::Region({Text{"the Stock Pot Inn", "l’Auberge de la Marmite", "Posada del Puchero", "", "l'auberge de Bourg-Clocher", ""}});
    hintTable[STOCKPOTINN_GRANDMA_ROOM] = HintText::Region({Text{"the Stock Pot Inn", "l’Auberge de la Marmite", "Posada del Puchero", "", "l'auberge de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_OBSERVATORY] = HintText::Region({Text{"the Astral Observatory", "l'observatoire céleste", "Observatorio Astronónico"}});
    hintTable[CLOCK_TOWN_BAR] = HintText::Region({Text{"the Milk Bar", "le bar laitier", "Bar Lácteo"}});
    hintTable[CLOCK_TOWN_HONEY_DARLING] = HintText::Region({Text{"East Clock Town", "Cadranbourg-Est", "Este de la Ciudad Reloj", "", "l'est de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_TREASURE_CHEST_GAME] = HintText::Region({Text{"East Clock Town", "Cadranbourg-Est", "Este de la Ciudad Reloj", "", "l'est de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_ARCHERY] = HintText::Region({Text{"East Clock Town", "Cadranbourg-Est", "Este de la Ciudad Reloj", "", "l'est de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_MAYOR_HOUSE] = HintText::Region({Text{"East Clock Town", "Cadranbourg-Est", "Este de la Ciudad Reloj", "", "l'est de Bourg-Clocher", ""}});
    hintTable[W_CLOCK_TOWN] = HintText::Region({Text{"West Clock Town", "Cadranbourg-Ouest", "Oeste de la Ciudad Reloj", "", "l'ouest de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_SWORDSMANS_SCHOOL] = HintText::Region({Text{"West Clock Town", "Cadranbourg-Ouest", "Oeste de la Ciudad Reloj", "", "l'ouest de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_POSTMAN_HOUSE] = HintText::Region({Text{"West Clock Town", "Cadranbourg-Ouest", "Oeste de la Ciudad Reloj", "", "l'ouest de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_LOTTERY] = HintText::Region({Text{"West Clock Town", "Cadranbourg-Ouest", "Oeste de la Ciudad Reloj", "", "l'ouest de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_BOMB_SHOP] = HintText::Region({Text{"West Clock Town", "Cadranbourg-Ouest", "Oeste de la Ciudad Reloj", "", "l'ouest de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_TRADING_POST] = HintText::Region({Text{"West Clock Town", "Cadranbourg-Ouest", "Oeste de la Ciudad Reloj", "", "l'ouest de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWN_CURIOSITY_SHOP] = HintText::Region({Text{"West Clock Town", "Cadranbourg-Ouest", "Oeste de la Ciudad Reloj", "", "l'ouest de Bourg-Clocher", ""}});
    hintTable[S_CLOCK_TOWN] = HintText::Region({Text{"South Clock Town", "Cadranbourg-Sud", "Sur de la Ciudad Reloj", "", "le sud de Bourg-Clocher", ""}});
    hintTable[CLOCK_TOWER] = HintText::Region({Text{"the Clock Tower", "la tour du cadran", "Torre del Reloj", "", "la tour du clocher", ""}});
    hintTable[CLOCK_TOWER_ROOF] = HintText::Region({Text{"the Clock Tower’s Roof", "le toit de la tour du cadran", "Cima de la Torre del Reloj", "", "le toit de la tour du clocher", ""}});
    hintTable[LAUNDRY_POOL] = HintText::Region({Text{"the Laundry Pool", "le lavoir", "Lavadero"}});
    hintTable[LAUNDRY_POOL_KAFEI_HIDEOUT] = HintText::Region({Text{"the Laundry Pool", "le lavoir", "Lavadero"}});
    hintTable[TERMINA_FIELD] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa"}});
    hintTable[TERMINA_FIELD_PEAHAT_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa"}});
    hintTable[TERMINA_FIELD_DODONGO_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa"}});
    hintTable[TERMINA_FIELD_BIO_BABA_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa"}});
    hintTable[TERMINA_FIELD_PILLAR_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa"}});
    hintTable[TERMINA_FIELD_GRASS_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa"}});
    hintTable[TERMINA_FIELD_BUSINESS_SCRUB_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa"}});
    hintTable[TERMINA_FIELD_COW_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa"}});
    hintTable[TERMINA_FIELD_GOSSIP_STONES_GROTTO] = HintText::Region({Text{"Termina Field", "la plaine Termina", "Campo de Términa"}});
    hintTable[ROAD_TO_SOUTHERN_SWAMP] = HintText::Region({Text{"the Road to Southern Swamp", "la route des marais du Sud", "Camino al Pantano del Sur"}});
    hintTable[ROAD_TO_SOUTHERN_SWAMP_ARCHERY] = HintText::Region({Text{"the Road to Southern Swamp", "la route des marais du Sud", "Camino al Pantano del Sur"}});
    hintTable[ROAD_TO_SWAMP_GROTTO] = HintText::Region({Text{"the Road to Southern Swamp", "la route des marais du Sud", "Camino al Pantano del Sur"}});
    hintTable[SOUTHERN_SWAMP] = HintText::Region({Text{"the Southern Swamp", "les marais du Sud", "Pantano del Sur"}});
    hintTable[SWAMP_TOURIST_CENTER] = HintText::Region({Text{"the Southern Swamp", "les marais du Sud", "Pantano del Sur"}});
    hintTable[SOUTHERN_SWAMP_HAGS_POTION_SHOP] = HintText::Region({Text{"the Southern Swamp", "les marais du Sud", "Pantano del Sur"}});
    hintTable[MYSTERY_WOODS] = HintText::Region({Text{"the Woods of Mystery", "le boisé mystérieux", "Bosque Misterioso", "", "les bois-mystère", ""}});
    hintTable[SOUTHERN_SWAMP_MYSTERY_WOODS_GROTTO] = HintText::Region({Text{"the Woods of Mystery", "le boisé mystérieux", "Bosque Misterioso", "", "les bois-mystère", ""}});
    hintTable[SOUTHERN_SWAMP_NEAR_SPIDER_HOUSE_GROTTO] = HintText::Region({Text{"the Southern Swamp", "les marais du Sud", "Pantano del Sur"}});
    hintTable[SOUTHERN_SWAMP_TOP] = HintText::Region({Text{"the Southern Swamp", "les marais du Sud", "Pantano del Sur"}});
    hintTable[DEKU_PALACE] = HintText::Region({Text{"the Deku Palace", "le palais mojo", "Palacio Deku"}});
    hintTable[DEKU_PALACE_INTERIOR] = HintText::Region({Text{"the Deku Palace", "le palais mojo", "Palacio Deku"}});
    hintTable[DEKU_PALACE_BEAN_GROTTO] = HintText::Region({Text{"the Deku Palace", "le palais mojo", "Palacio Deku"}});
    hintTable[DEKU_SHRINE] = HintText::Region({Text{"the Deku Palace", "le palais mojo", "Palacio Deku"}});
    hintTable[WOODFALL] = HintText::Region({Text{"Woodfall", "Boisé-les-Cascades", "Bosque Catarata", "", "Bois-Cascade", ""}});
    hintTable[WOODFALL_FAIRY_FOUNTAIN] = HintText::Region({Text{"Woodfall’s Fairy Fountain", "la fontaine des fées de Boisé-les-Cascades", "Fuente de las hadas del Bosque Catarata", "", "la fontaine des fées de Bois-Cascade", ""}});
    hintTable[PATH_TO_MOUNTAIN_VILLAGE] = HintText::Region({Text{"the road to Mountain Village", "la route vers le village dans la montagne", "Camino al Pueblo de la Montaña"}});
    hintTable[MOUNTAIN_VILLAGE] = HintText::Region({Text{"the Mountain Village", "le village dans la montagne", "Pueblo de la Montaña"}});
    hintTable[GORON_GRAVEYARD] = HintText::Region({Text{"the Goron Graveyard", "le cimetière des Gorons", "Cementerio Goron"}});
    hintTable[MOUNTAIN_SMITHY] = HintText::Region({Text{"the Mountain Village", "le village dans la montagne", "Pueblo de la Montaña"}});
    hintTable[MOUNTAIN_VILLAGE_SPRING_WATER_GROTTO] = HintText::Region({Text{"the Mountain Village", "le village dans la montagne", "Pueblo de la Montaña"}});
    hintTable[TWIN_ISLANDS] = HintText::Region({Text{"the road to Goron Village", "la route du village goron", "Islas Gemelas"}});
    hintTable[GORON_RACETRACK] = HintText::Region({Text{"the Goron Racetrack", "la course des Gorons", "Circuito de carreras Goron"}});
    hintTable[TWIN_ISLANDS_GORON_RACETRACK_GROTTO] = HintText::Region({Text{"the road to Goron Village", "la route du village goron", "Islas Gemelas"}});
    hintTable[TWIN_ISLANDS_SPRING_WATER_GROTTO] = HintText::Region({Text{"the road to Goron Village", "la route du village goron", "Islas Gemelas"}});
    hintTable[GORON_VILLAGE] = HintText::Region({Text{"the Goron Village", "le village goron", "Aldea Goron"}});
    hintTable[GORON_VILLAGE_LENS_CAVE] = HintText::Region({Text{"the Goron Village", "le village goron", "Aldea Goron"}});
    hintTable[GORON_VILLAGE_INTERIOR] = HintText::Region({Text{"the Goron Village", "le village goron", "Aldea Goron"}});
    hintTable[GORON_VILLAGE_SHOP] = HintText::Region({Text{"the Goron Village", "le village goron", "Aldea Goron"}});
    hintTable[ROAD_TO_SNOWHEAD] = HintText::Region({Text{"the road to Snowhead", "la route du Pic des neiges", "Camino al Pico Nevado", "", "la route du pic des Neiges", ""}});
    hintTable[ROAD_TO_SNOWHEAD_GROTTO] = HintText::Region({Text{"the road to Snowhead", "la route du Pic des neiges", "Camino al Pico Nevado", "", "la route du pic des Neiges", ""}});
    hintTable[SNOWHEAD] = HintText::Region({Text{"Snowhead", "le Pic des neiges", "Pico Nevado", "", "le pic des Neiges", ""}});
    hintTable[SNOWHEAD_FAIRY_FOUNTAIN] = HintText::Region({Text{"Snowhead’s Fairy Fountain", "la fontaine de fées du Pic des neiges", "Fuente de las hadas del Pico Nevado", "", "la fontaine de fées du pic des Neiges", ""}});
    hintTable[MILK_ROAD] = HintText::Region({Text{"Milk Road", "la route du lait", "Camino Lácteo"}});
    hintTable[GORMAN_TRACK] = HintText::Region({Text{"the Gorman Track", "la piste des Gorman", "Circuito de Gorman"}});
    hintTable[ROMANI_RANCH] = HintText::Region({Text{"Romani Ranch", "le ranch Romani", "Rancho Romani"}});
    hintTable[DOGGY_RACETRACK] = HintText::Region({Text{"Romani Ranch", "le ranch Romani", "Rancho Romani"}});
    hintTable[CUCCO_SHACK] = HintText::Region({Text{"Romani Ranch", "le ranch Romani", "Rancho Romani"}});
    hintTable[ROMANI_RANCH_HOUSE] = HintText::Region({Text{"Romani Ranch", "le ranch Romani", "Rancho Romani"}});
    hintTable[ROMANI_RANCH_BARN] = HintText::Region({Text{"Romani Ranch", "le ranch Romani", "Rancho Romani"}});
    hintTable[GREAT_BAY_COAST] = HintText::Region({Text{"Great Bay Coast", "la côte de la Grande Baie", "Costa de la Gran Bahía"}});
    hintTable[GREAT_BAY_COAST_MARINE_LAB] = HintText::Region({Text{"Great Bay Coast", "la côte de la Grande Baie", "Costa de la Gran Bahía"}});
    hintTable[GREAT_BAY_COAST_GROTTO] = HintText::Region({Text{"Great Bay Coast", "la côte de la Grande Baie", "Costa de la Gran Bahía"}});
    hintTable[GREAT_BAY_COAST_COW_GROTTO] = HintText::Region({Text{"Great Bay Coast", "la côte de la Grande Baie", "Costa de la Gran Bahía"}});
    hintTable[FISHERMAN_HUT] = HintText::Region({Text{"Great Bay Coast", "la côte de la Grande Baie", "Costa de la Gran Bahía"}});
    hintTable[PINNACLE_ROCK] = HintText::Region({Text{"Pinnacle Rock", "le Pic de pierre", "Roca Pináculo", "", "le puits de pierre", ""}});
    hintTable[ZORA_CAPE] = HintText::Region({Text{"Zora Cape", "le cap des Zoras", "Cabo Zora"}});
    hintTable[WATERFALL_RAPIDS] = HintText::Region({Text{"Zora Cape", "le cap des Zoras", "Cabo Zora"}});
    hintTable[GREAT_BAY_FAIRY_FOUNTAIN] = HintText::Region({Text{"Zora Cape’s Fairy Fountain", "la fontaine des fées du cap des Zoras", "Fuente de las hadas de la Gran Bahía"}});
    hintTable[ZORA_CAPE_GROTTO] = HintText::Region({Text{"Zora Cape", "le cap des Zoras", "Cabo Zora"}});
    hintTable[ZORA_HALL] = HintText::Region({Text{"Zora Hall", "le théâtre des Zoras", "Salón Zora"}});
    hintTable[ZORA_HALL_EVANS_ROOM] = HintText::Region({Text{"Zora Hall", "le théâtre des Zoras", "Salón Zora"}});
    hintTable[ZORA_HALL_LULUS_ROOM] = HintText::Region({Text{"Zora Hall", "le théâtre des Zoras", "Salón Zora"}});
    hintTable[ZORA_HALL_JAPAS_ROOM] = HintText::Region({Text{"Zora Hall", "le théâtre des Zoras", "Salón Zora"}});
    hintTable[ZORA_HALL_TIJOS_ROOM] = HintText::Region({Text{"Zora Hall", "le théâtre des Zoras", "Salón Zora"}});
    hintTable[ZORA_HALL_SHOP] = HintText::Region({Text{"Zora Hall", "le théâtre des Zoras", "Salón Zora"}});
    hintTable[ZORA_HALL_BACK_ENTRANCE] = HintText::Region({Text{"Zora Hall", "le théâtre des Zoras", "Salón Zora"}});
    hintTable[ROAD_TO_IKANA] = HintText::Region({Text{"the road to Ikana", "la route d'Ikana", "Camino a Ikana"}});
    hintTable[ROAD_TO_IKANA_GROTTO] = HintText::Region({Text{"the road to Ikana", "la route d'Ikana", "Camino a Ikana"}});
    hintTable[IKANA_GRAVEYARD] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana"}});
    hintTable[IKANA_GRAVEYARD_GROTTO] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana"}});
    hintTable[IKANA_GRAVEYARD_BELOW_GRAVE1] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana"}});
    hintTable[IKANA_GRAVEYARD_BATS_ROOM] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana"}});
    hintTable[IKANA_GRAVEYARD_TABLET_ROOM] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana"}});
    hintTable[IKANA_GRAVEYARD_BELOW_GRAVE2] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana"}});
    hintTable[IKANA_GRAVEYARD_PRE_IRON_KNUCKLE_ROOM] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana"}});
    hintTable[IKANA_GRAVEYARD_IRON_KNUCKLE_ROOM] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana"}});
    hintTable[IKANA_GRAVEYARD_BELOW_GRAVE3] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana"}});
    hintTable[DAMPES_HUT] = HintText::Region({Text{"Ikana Graveyard", "le cimetière d'Ikana", "Cementerio de Ikana"}});
    hintTable[IKANA_CANYON] = HintText::Region({Text{"Ikana Canyon", "le canyon d'Ikana", "Cañón de Ikana", "", "la vallée d'Ikana", ""}});
    hintTable[IKANA_CANYON_UPPER] = HintText::Region({Text{"Ikana Canyon", "le canyon d'Ikana", "Cañón de Ikana", "", "la vallée d'Ikana", ""}});
    hintTable[IKANA_CANYON_CAVE] = HintText::Region({Text{"Ikana Canyon", "le canyon d'Ikana", "Cañón de Ikana", "", "la vallée d'Ikana", ""}});
    hintTable[SAKONS_HIDEOUT] = HintText::Region({Text{"Ikana Canyon", "le canyon d'Ikana", "Cañón de Ikana", "", "la vallée d'Ikana", ""}});
    hintTable[MUSIC_BOX_HOUSE] = HintText::Region({Text{"Ikana Canyon", "le canyon d'Ikana", "Cañón de Ikana", "", "la vallée d'Ikana", ""}});
    hintTable[IKANA_CANYON_POE_HUT] = HintText::Region({Text{"Ikana Canyon", "le canyon d'Ikana", "Cañón de Ikana", "", "la vallée d'Ikana", ""}});
    hintTable[IKANA_CANYON_GREAT_FAIRY_FOUNTAIN] = HintText::Region({Text{"Ikana Canyon’s Fairy Fountain", "la fontaine des fées du canyon d'Ikana", "Fuente de las hadas del Cañón de Ikana", "", "la fontaine des fées de la vallée d'Ikana", ""}});
    hintTable[IKANA_CANYON_SECRET_SHRINE_GROTTO] = HintText::Region({Text{"Ikana Canyon", "le canyon d'Ikana", "Cañón de Ikana", "", "la vallée d'Ikana", ""}});
    hintTable[STONE_TOWER] = HintText::Region({Text{"Stone Tower", "la forteresse de pierre", "Torre de Piedra"}});
    hintTable[INVERTED_STONE_TOWER] = HintText::Region({Text{"Stone Tower", "la forteresse de pierre", "Torre de Piedra"}});

    /*---------------------
    |   JUNK HINT TEXT    |
    ---------------------*/
    hintTable[JUNK01] = HintText::Junk({Text{"That's no moon.", "C'est pas une lune, ce truc.", "Esa no es una luna"}});
    hintTable[JUNK02] = HintText::Junk({Text{"The moon is haunted.", "La lune est hantée.", "La luna está embrujada"}});
    hintTable[JUNK03] = HintText::Junk({Text{"Majora has sick dance moves.", "Majora est une bête sur le dance floor.", "Majora baila como Chayanne"}});
    hintTable[JUNK04] = HintText::Junk({Text{"Making hints is hard.", "C'est dur de faire des indices.", "Hacer pistas es dificil"}});
    hintTable[JUNK05] = HintText::Junk({Text{"May the way of the Hero lead to the Triforce.", "Que la Triforce guide les pas du héros.", "Que la senda del héroe lleve a la Trifuerza"}});
    hintTable[JUNK06] = HintText::Junk({Text{"They say that the final item you're looking for can be found somewhere in Termina.", "Selon moi, l'objet qui t'élude se terre en Termina.", "Dicen que el objeto final que buscas se puede encontrar en algún lado en Termina"}});
    hintTable[JUNK07] = HintText::Junk({Text{"They say that 85 percent of statistics are made up", "On raconte que 85 pourcent des statistiques sortent de nulle part.", "Dicen que el 85 por ciento de las estadísticas son inventadas"}});
    hintTable[JUNK08] = HintText::Junk({Text{"They say the golden dog is picked as the winner most often", "Il paraît que le chien doré gagne plus souvent que les autres.", "Dicen que el perro dorado es seleccionado como el ganador más comunmente"}});
    hintTable[JUNK09] = HintText::Junk({Text{"Be patient young grasshopper", "Patience, petit scarabée!&...Pourquoi je ris, cette blague est&nulle! Peut-être dans une autre&langue ça veut dire un truc...", "Tenga paciencia, pequeño grillo"}});
    hintTable[JUNK10] = HintText::Junk({Text{"The Ikana King used to be quite handsome", "Le roi d'Ikana était assez beau gosse, autrefois.", "El Rey de Ikana solía ser muy apuesto"}});
    hintTable[JUNK11] = HintText::Junk({Text{"If the Goron Elder is frozen how does he move each day", "L'Ancêtre goron est gelé, non? Comment il fait pour changer de place chaque jour?", "El Anciano Goron está congelado. ¿Como se mueve cada día...?"}});
    hintTable[JUNK12] = HintText::Junk({Text{"The Owl's feathers lead the way", "Les plumes du hibou montrent la voie.", "Las plumas del búho marcan el camino"}});
    hintTable[JUNK13] = HintText::Junk({Text{"The Happy Mask Salesman doesn't sleep", "Le propriétaire de la foire aux masques ne dors jamais.", "El vendedor de las máscaras no duerme"}});
    hintTable[JUNK14] = HintText::Junk({Text{"why do they call it oven when you of in the cold food of out hot eat the food", "Les lave-linges durent plus longtemps avec Ganon! ♪", "Le dicen desayuno porque rompes el ayuno"}});
    hintTable[JUNK15] = HintText::Junk({Text{"It seems Link has difficulties remembering music without the help of a fairy.", "On dirait qu'un @ sans fée n'a aucune mémoire musicale.", "Parece que Link tiene dificultades para recordar música sin ayuda de un hada."}});
    hintTable[JUNK16] = HintText::Junk({Text{"Pickle.", "Cornichon.", "Esperpento."}});
    hintTable[JUNK17] = HintText::Junk({Text{"Why is it called The Legend of Zelda Majora's Mask when Zelda isn't here?", "Si c'est toujours la Légende de Zelda, elle est où Zelda?", "¿Por qué se llama The Legend of Zelda Majora's Mask cuando Zelda no está aquí?"}});
    hintTable[JUNK18] = HintText::Junk({Text{"They say you can find the Star Fox cast in your mask inventory screen.", "Il paraît que le casting de Star Fox peut se trouver dans l'inventaire.", "Dicen que puedes encontrar al elenco de Star Fox en tu inventario de máscaras."}});
    hintTable[JUNK19] = HintText::Junk({Text{"They say #L# is Real 2401.", "La musique du moulin te dis pas quelque chose? C'est juste moi?", "Dicen que #L# es real 2401"}});
    hintTable[JUNK20] = HintText::Junk({Text{"They say #The Moon# blinks if you stare long enough", "Il paraît que la lune cligne des yeux si on la regarde assez longtemps.", "Dicen que #La Luna# parpadea si miras lo suficiente"}});
    hintTable[JUNK21] = HintText::Junk({Text{"They say bunnies have a really good sense of time.", "Il paraît que les lapins ont un bon sens du temps.", "Dicen que los conejos tienen muy buen sentido del tiempo"}});
    hintTable[JUNK22] = HintText::Junk({Text{"They say this game has a method of infinitely jumping.", "Il paraît qu'on peut sauter indéfiniment si on est assez motivé.", "Dicen que hay un método para saltar infinitamente en este juego"}});
    hintTable[JUNK23] = HintText::Junk({Text{"According to all known laws of aviation there is no way a Zora should be able to fly.", "#Sauvegarder# votre progression à-&...Ah, non! Désolé!&& ", "Según todas las leyes conocidas de la aviación, es imposible que un Zora pueda volar."}});
    hintTable[JUNK24] = HintText::Junk({Text{"Why is Zelda green?", "Pourquoi qu'il est vert, Zelda?", "¿Por qué Zelda es verde?"}});
    hintTable[JUNK25] = HintText::Junk({Text{"Did you know for the first time in 23 years, in 2023 Waluigi didn't star in a game?", "Savais-tu que la première année en 23 ans sans apparition de Waluigi dans un jeu était en 2023?", "¿Sabías que por primera vez en 23 años, Waluigi no protagonizo ningún juego en 2023?"}});
    hintTable[JUNK26] = HintText::Junk({Text{"Here's a hint, @. Don't be bad.", "Un conseil, @. Soit bon.", "Aquí hay una pista, @. Git gud."}});
    hintTable[JUNK27] = HintText::Junk({Text{"They say this randomizer actually took longer to develop than the original Majora's Mask.", "Il paraît que la conception de ce randomiseur fut plus longue que celle du Majora's Mask original.", "Dicen que este randomizer tomó más tiempo de desarrollar que el Majora's Mask original"}});
    hintTable[JUNK28] = HintText::Junk({Text{"They say pirates are allergic to #bees#.", "Il paraît que les pirates sont allergiques aux #abeilles#.", "Dicen que las piratas son alérgicas a las #abejas#"}});
    hintTable[JUNK29] = HintText::Junk({Text{"Ocean man, take me by the hand.", "Biggoron pue des pieds.", "Dale, Zelda dale. Pásame la trifuerza que tengo hambre."}});
    hintTable[JUNK30] = HintText::Junk({Text{"Special shoutouts to ennopp who plays piano during this cutscene", "[VOTRE BLAGUE OU RÉFÉRENCE ICI]", "Saludos a ennopp, que toca piano en esta escena"}});
    hintTable[JUNK31] = HintText::Junk({Text{"Did you know it's actually surprisingly easy to mod a 3DS?", "Il paraît que hacker une 3DS est un jeu d'enfant.", "¿Sabías que es sorprendentemente fácil hackear un 3DS?"}});
    hintTable[JUNK32] = HintText::Junk({Text{"Zora eggs are quite delicious.", "J'adore les œufs de Zora. Surtout avec de la mayo.", "Los huevos zora son una delicia"}});
    hintTable[JUNK33] = HintText::Junk({Text{"Zabora and Gabora have gotten better at making swords that stay sharp.", "Zabora et Gabora forgent des lames bien plus pérennes qu'avant.", "Zubora y Gabora hacen mejores espadas ahora"}});
    hintTable[JUNK34] = HintText::Junk({Text{"They say Tacoman369 has never defeated Majora.", "On raconte que Tacoman369 n'a jamais vaincu Majora.", "Dicen que Tacoman369 nunca ha derrotado a Majora."}});
    hintTable[JUNK35] = HintText::Junk({Text{"L2P @.", "Sois gentil avec les cocottes.", "Aserejé a dejeb"}});
    hintTable[JUNK36] = HintText::Junk({Text{"They say the #Majora's Mask 3D Randomizer# developers are cool people.", "Ils paraît que les développeurs du #Majora's Mask 3D Randomizer# sont des gens cools.", "Dicen que los desarrolladores de #Majora's Mask 3D Randomizer# son gente cool."}});
    hintTable[JUNK37] = HintText::Junk({Text{"Also try #Ocarina of Time 3D Randomizer#!", "Essayez aussi #Ocarina of Time 3D Randomizer#!", "También prueba el #Ocarina of Time 3D Randomizer#!"}});
    hintTable[JUNK38] = HintText::Junk({Text{"The single rupee is a unique item.", "Le rubis vert est un objet unique.", "La rupia es única en su tipo"}});
    hintTable[JUNK39] = HintText::Junk({Text{"Hey, listen!", "Hey! Listen!", "¡Dale, con la silla!"}});
    hintTable[JUNK40] = HintText::Junk({Text{"They say even the Hero of Time can't help everyone.", "Il paraît que même le Héros du Temps ne peut pas aider tout le monde.", "Dicen que incluso el Héroe del Tiempo no puede ayudar a todos"}});
    hintTable[JUNK41] = HintText::Junk({Text{"The dirt around here tastes really good.", "La terre par ici est délicieuse.", "Dile, que, que... ¡Que coma tierra!"}});
    hintTable[JUNK42] = HintText::Junk({Text{"Talk to me again for the best hint.", "Réessaie pour voir, j'aurai peut-être un meilleur indice.", "Háblame de nuevo para una mejor pista"}});
    hintTable[JUNK43] = HintText::Junk({Text{"They say Gorons discovered a method of space travel.", "Il paraît que les gorons ont découvert une méthode de voyage spatial.", "Dicen que los Goron descubrieron la manera de viajar al espacio"}});
    hintTable[JUNK44] = HintText::Junk({Text{"I AM ERROR", "I AM ERROR", "ALL YOUR BASE ARE BELONG TO US"}});
    hintTable[JUNK45] = HintText::Junk({Text{"Real 3DS ZELDA players use motion controls.", "Les vrais pros jouent avec les capteurs de mouvement.", "Los verdaderos jugadores de ZELDA 3DS usan el Gyro"}});
    hintTable[JUNK46] = HintText::Junk({Text{"Real ZELDA players use HOLD targeting.", "Régler la visée L sur \"Maintenir\" dans les options est super cool.", "Los verdaderos jugadores de ZELDA usan Mantener para fijar el blanco"}});
    hintTable[JUNK47] = HintText::Junk({Text{"They say items are random...", "Il paraît que les objets sont tout mélangés.", "Dicen que los objetos son aleatorios..."}});
    hintTable[JUNK48] = HintText::Junk({Text{"Dear Mario, please come to the castle. I've baked a cake for you. Yours truly, Princess Toadstool, Peach", "Mon très cher Mario: Viens vite au château, je t'ai préparé un délicieux gâteau...                         À bientôt, &Princesse Toadstool, Peach.", "Lo siento, Mario. ¡Tu princesa está en otro castillo!"}});
    hintTable[JUNK49] = HintText::Junk({Text{"They say the key to victory is beating the game...", "Il paraît que la clé de la victoire est de finir le jeu.", "Un tip: Para ganar, acaba el juego"}});
    hintTable[JUNK50] = HintText::Junk({Text{"They say the gold dog cheats.", "Selon moi, le chien doré est un sale tricheur.", "El perro dorado es un tramposo"}});
    hintTable[JUNK51] = HintText::Junk({Text{"They say @ drowned.", "Comment on débloque le masque de Mario?", "Dicen que @ se ahogó"}});
    hintTable[JUNK52] = HintText::Junk({Text{"Goodbye then.", "OK, à plus.", "Adiosito"}});
    hintTable[JUNK53] = HintText::Junk({Text{"You've met with a terrible hint, haven't you?", "Jeune garçon, tu es confronté a un terrible indice, n'est-ce pas?", "Te has encontrado con una pista terrible, no es así?"}});
    hintTable[JUNK54] = HintText::Junk({Text{"I'm stoned. Get it?", "Ces histoires me laissent de marbre.&...Hahah...", "Me dicen Pedro. ¿Lo entiendes?"}});
    hintTable[JUNK55] = HintText::Junk({Text{"One who doesn't have all the masks will not get a #special reward#", "Seuls ceux qui détiennent tout les masques recevront une #récompense spéciale#.", "Quien no tenga todas las máscaras no recibirá una #super duper recompensa#."}});
    hintTable[JUNK56] = HintText::Junk({Text{"They say the #blue dog# will win a race some day...", "Il paraît que le #chien bleu# a déjà gagné une course.", "Algún día el perro azul ganará la carrera...."}});
    hintTable[JUNK57] = HintText::Junk({Text{"Remember to check your 3DS battery level and save often.", "Pense bien à garder le console chargée et sauvegarder souvent.", "Recuerda revisar la batería de tu 3DS y guardar seguido"}});
    hintTable[JUNK58] = HintText::Junk({Text{"Just be a rock.", "#Atchoum!#", "Beep boop, soy un robot"}});
    hintTable[JUNK59] = HintText::Junk({Text{"I can't feel my legs!", "Je sens pas mes jambes!", "¡No puedo sentir mis piernas!"}});
    hintTable[JUNK60] = HintText::Junk({Text{"What are you staring at?", "Tu veux ma photo?", "¿Qué me ves?"}});
    hintTable[JUNK61] = HintText::Junk({Text{"Glitches are a pathway to many abilities some consider to be... Unnatural.", "Les cartes sont assez abordables, non?&Je m'attendais à pire en voyant le vendeur.", "Haz un par de maromas o algo."}});
    hintTable[JUNK62] = HintText::Junk({Text{"You ever just feel like smashing that $ button?", "Appuyer sur $ fait grimper plus vite.", "¡Apachúrrale starp!"}});
    hintTable[JUNK63] = HintText::Junk({Text{"I think the Mask of Truth has it's uses!", "Il paraît que le masque de vérité a des effets #secrets#.", "Dicen que la Máscara de la verdad tiene usos"}});
    hintTable[JUNK64] = HintText::Junk({Text{"There's a lot of eyes here, isn't there?", "Ça en fait des yeux, dis-donc.", "Hay demasiados ojos aquí, ¿no crees?"}});
    hintTable[JUNK65] = HintText::Junk({Text{"I think that #large object in the sky# hasn't moved in a few days.", "Ce #gros machin# dans le ciel n'a plus bougé depuis quelque jours, si?", "Mi novia se convirtió en la luna"}});
    hintTable[JUNK66] = HintText::Junk({Text{"Watch out for that #large object in the sky!#", "Le #ciel# nous tombe sur la tête!!", "Cuidado con la cabeza"}});
    hintTable[JUNK67] = HintText::Junk({Text{"#Tingle Tingle Kooloo Limpah!#", "#Tingle Tingle Kooloolin... Pah!#", "Dicen que Ganondorf iba a ser un pescador en Términa"}});
    hintTable[JUNK68] = HintText::Junk({Text{"They say if you have three specific items, you can zoom across Termina.", "Il parait qu'on peut tracer à travers Termina avec trois objets précis.", "Dicen que con tres objetos específicos, puedes dispararte por Términa"}});
    hintTable[JUNK69] = HintText::Junk({Text{"They say the powder keg can remain fairly elusive.", "Il paraît que le baril de poudre peut s'avérer assez élusif.", "Dicen que el Barril de Pólvora puede ser dificil de encontrar"}});
    hintTable[JUNK70] = HintText::Junk({Text{"It's pretty cold here, would you mind warming me up, @?", "Fais frisquet dites-moi... N'auriez vous point de quoi me réchauffer, messire?", "¡Prepárense para los problemas, y mas vale que teman!"}});
    hintTable[JUNK71] = HintText::Junk({Text{"These hints can be quite useful. This is an exception.", "Il paraît que ces indices peuvent s'avérer utiles.&Celui-ci n'en est pas la preuve.", "Freezer mintió cuando dijo que Namekuseí explotará en 5 minutos"}});
    hintTable[JUNK72] = HintText::Junk({Text{"Turns are more effective when you tilt the whole console.", "Pencher la console aide à négocier les virages serrés. Si si, j'te jure!", "Caminar hacia atrás es más efectivo que rodar"}});
    hintTable[JUNK73] = HintText::Junk({Text{"You ever been in a cockpit before?", "Je m'demande ce que Ganon est en train de faire!", "Si te ataco con un diccionario, ¿se considera agresión física o verbal?"}});
    hintTable[JUNK74] = HintText::Junk({Text{"It's a secret to everybody", "Il est écrit: Seul Link peut vaincre Ganon.", "¡NOOOO! ¡TORITO!"}});
    hintTable[JUNK75] = HintText::Junk({Text{"You found me!", "Nom d'un caillou! Tu m'as trouvé!", "¡Tenía que ser el chavo del ocho!"}});
    hintTable[JUNK76] = HintText::Junk({Text{"I have it on my post-it note somewhere.", "Ah oui, ton indice! Attends, je crois bien l'avoir mis quelque part...", "¡Hola! Me has atrapado medio #SUAVEMENTE#."}});
    hintTable[JUNK77] = HintText::Junk({Text{"Follow the rainbow.", "Laisssse-moi!&Laisssse-moi!&&Laisssse-moitranquille!", "Sigue el arcoíris"}});

    /*------------------------
    |   DUNGEON HINT TEXT    |
    ------------------------*/
    hintTable[WOODFALL_TEMPLE] = HintText::DungeonName({
            //obscure
            Text{"the sleeping temple", "le temple endormi", "el templo durmiente"}
        },  //clear
            Text{"the Woodfall Temple", "le temple de Boisé-les-Cascades", "el Templo del Bosque Catarata", "", "le temple de Bois-Cascade", ""}
    );
    hintTable[SNOWHEAD_TEMPLE] = HintText::DungeonName({
            //obscure
            Text{"an icy temple", "un temple glacé", "el templo helado"}
        },  //clear
            Text{"the Snowhead Temple", "le temple du Pic des neiges", "el Templo del Pico Nevado", "", "le temple du pic des Neiges", ""}
    );
    hintTable[GREAT_BAY_TEMPLE] = HintText::DungeonName({
            //obscure
            Text{"the murky watered temple", "le temple en eaux troubles", "el templo de aguas turbias"}
        },  //clear
            Text{"the Great Bay Temple", "le temple de la Grande Baie", "el Templo de la Gran Bahía"}
    );
    hintTable[STONE_TOWER_TEMPLE] = HintText::DungeonName({
            //obscure
            Text{"a rocky temple", "un temple sens dessus dessous", "el templo rocoso"}
        },  //clear
            Text{"the Stone Tower Temple", "le temple de la forteresse de pierre", "el Templo de la Torre de Piedra"}
    );
    hintTable[PIRATE_FORTRESS] = HintText::DungeonName({
            //obscure
            Text{"the home of pirates", "le foyer des pirates", "el hogar de las piratas"}
        },  //clear
            Text{"the Pirates' Fortress", "la forteresse des pirates", "la Fortaleza Pirata"}
    );
    hintTable[BENEATH_THE_WELL] = HintText::DungeonName({
            //obscure
            Text{"an empty watering hole", "un abreuvoir vide", "un abrevadero en sequía"}
        },  //clear
            Text{"Beneath the Well", "le fond du puits", "Bajo el Pozo"}
    );
    hintTable[IKANA_CASTLE] = HintText::DungeonName({
            //obscure
            Text{"a fallen castle", "un château déchu", "un castillo rendido"}
        },  //clear
            Text{"the Ancient Castle of Ikana", "les vestiges du château d'Ikana", "el Antiguo Castillo de Ikana"}
    );
    hintTable[SECRET_SHRINE] = HintText::DungeonName({
            //obscure
            Text{"a mini boss run area", "une zone à mini boss", "donde se congregan los jefes menores"}
        },  //clear
            Text{"the Secret Shrine", "le sanctuaire secret", "el Santuario Secreto"}
    );
    hintTable[SSH] = HintText::DungeonName({
            //obscure
            Text{"a home to muddy spiders", "un nid puant d'araignées", "un hogar para arañas lodosas"}
        },  //clear
            Text{"the Swamp Spider House", "la maison des araignées des marais", "la Casa de las Arañas del Pantano"}
    );
    hintTable[OSH] = HintText::DungeonName({
            //obscure
            Text{"a home To swimming spiders", "un nid poussiéreux d'araignées", "un hogar para arañas nadadoras"}
        },  //clear
            Text{"the Ocean Spider House", "la maison des araignées de la côte", "la Casa de las Arañas de la Playa"}
    );
    hintTable[THE_MOON] = HintText::DungeonName({
            //obscure
            Text{"a dungeon out of this world", "un donjon d'un autre monde", "un calabozo fuera de éste mundo"}
        },  //clear
            Text{"the Moon", "la lune", "la Luna"}
    );

    /*-----------------------
    |    BOSS HINT TEXT     |
    -----------------------*/
    hintTable[ODOLWA] = HintText::Boss({
            //obscure
            Text{"a #masked jungle warrior# holds", "un #guerrier de la jungle masqué# détient", "un guerrero salvaje enmascarado"}});
    hintTable[GOHT] = HintText::Boss({
            //obscure
            Text{"a #masked mechanical monster# holds", "une #chimère mécanique masquée# détient", "un monstruo mecánico enmascarado"}});
    hintTable[GYORG] = HintText::Boss({
            //obscure
            Text{"a #gargantuan masked fish# holds", "un #léviathan gargantuesque masqué# détient", "un pez colosal enmascarado"}});
    hintTable[TWINMOLD] = HintText::Boss({
            //obscure
            Text{"a #giant masked insect# holds", "un #double insecte géant masqué# détient", "un insecto gigante enmascarado"}});
    hintTable[MAJORA] = HintText::Boss({
            //obscure
            Text{"a #cursed mask# holds", "un #masque maléfique# détient", "una máscara maldita"}});


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
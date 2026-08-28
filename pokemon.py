"""
Pokémon Data Module
فئة البوكيمون ونظام الإحصائيات
"""

class Pokemon:
    def __init__(self, name, ptype, level, hp, attack, defense, sp_attack, sp_defense, speed, moves=None):
        self.name = name
        self.ptype = ptype
        self.level = level
        self.hp = hp
        self.max_hp = hp
        self.attack = attack
        self.defense = defense
        self.sp_attack = sp_attack
        self.sp_defense = sp_defense
        self.speed = speed
        self.moves = moves or []
        self.exp = 0
        self.status = "صحي"  # صحي، مشلول، نوم، حرق، سم

    def take_damage(self, damage):
        self.hp = max(0, self.hp - damage)
        return self.hp

    def heal(self):
        self.hp = self.max_hp
        self.status = "صحي"

    def is_alive(self):
        return self.hp > 0

    def display_stats(self):
        return f"""
{self.name} (المستوى {self.level})
النوع: {self.ptype}
الصحة: {self.hp}/{self.max_hp}
الحالة: {self.status}
الهجوم: {self.attack} | الدفاع: {self.defense}
الهجوم الخاص: {self.sp_attack} | الدفاع الخاص: {self.sp_defense}
السرعة: {self.speed}
"""

# جميع بوكيمونات اللعبة
ALL_POKEMON = {
    "Pikachu": Pokemon("بيكاشو", "كهربائي", 50, 120, 95, 80, 110, 90, 140, ["Thunderbolt", "Quick Attack", "Thunder Wave", "Iron Tail"]),
    "Charizard": Pokemon("تشاريزارد", "نار/طائر", 55, 156, 186, 166, 171, 166, 166, ["Flamethrower", "Fly", "Dragon Claw", "Earthquake"]),
    "Blastoise": Pokemon("بلاستويس", "ماء", 55, 158, 146, 186, 166, 176, 126, ["Hydro Pump", "Ice Beam", "Earthquake", "Flash Cannon"]),
    "Venusaur": Pokemon("فينوسور", "عشبي/سم", 55, 156, 136, 146, 186, 186, 126, ["Solar Beam", "Sludge Bomb", "Earthquake", "Leech Seed"]),
    "Dragonite": Pokemon("دراجونايت", "نين/طائر", 56, 158, 198, 158, 186, 146, 146, ["Dragon Dance", "Outrage", "Earthquake", "Superpower"]),
    "Alakazam": Pokemon("ألاكازام", "نفسي", 55, 111, 106, 106, 211, 146, 186, ["Psychic", "Focus Blast", "Shadow Ball", "Dazzling Gleam"]),
    "Machamp": Pokemon("ماشامب", "قتالي", 55, 158, 211, 156, 106, 156, 126, ["Dynamic Punch", "Stone Edge", "Earthquake", "Superpower"]),
    "Golem": Pokemon("جوليم", "صخري/أرضي", 55, 156, 186, 211, 106, 106, 106, ["Earthquake", "Stone Edge", "Explosion", "Heavy Slam"]),
    "Arcanine": Pokemon("أركانين", "نار", 54, 156, 186, 146, 146, 146, 166, ["Wild Charge", "Extreme Speed", "Close Combat", "Flare Blitz"]),
    "Gyarados": Pokemon("جايرادوس", "ماء/طائر", 55, 158, 196, 146, 146, 156, 126, ["Earthquake", "Stone Edge", "Waterfall", "Dragon Dance"]),
    "Lapras": Pokemon("لابراس", "ماء/جليد", 55, 181, 146, 166, 166, 166, 110, ["Hydro Pump", "Ice Beam", "Earthquake", "Dragon Dance"]),
    "Snorlax": Pokemon("سنورلاكس", "عادي", 55, 241, 156, 146, 106, 156, 76, ["Body Slam", "Earthquake", "Crunch", "Rest"]),
    "Articuno": Pokemon("أرتيكونو", "جليد/طائر", 55, 154, 136, 166, 151, 176, 121, ["Hurricane", "Ice Beam", "Ancient Power", "Roost"]),
    "Zapdos": Pokemon("زابدوس", "كهربائي/طائر", 55, 154, 146, 156, 176, 141, 151, ["Hurricane", "Thunderbolt", "Volt Switch", "Roost"]),
    "Moltres": Pokemon("مولتريس", "نار/طائر", 55, 154, 166, 146, 176, 151, 151, ["Hurricane", "Fire Blast", "Solar Beam", "Roost"]),
    "Mewtwo": Pokemon("ميوتو", "نفسي", 60, 166, 166, 166, 221, 166, 196, ["Psychic", "Aura Sphere", "Ice Beam", "Calm Mind"]),
    "Mew": Pokemon("ميو", "نفسي", 60, 166, 166, 166, 166, 166, 166, ["Psychic", "Swords Dance", "Earthquake", "Dragon Dance"]),
    "Nidoking": Pokemon("نيدوكينج", "سم/أرضي", 55, 145, 176, 136, 146, 136, 136, ["Earthquake", "Sludge Bomb", "Stone Edge", "Superpower"]),
    "Raichu": Pokemon("رايتشو", "كهربائي", 53, 126, 136, 106, 151, 106, 166, ["Thunderbolt", "Earthquake", "Volt Switch", "Nasty Plot"]),
    "Persian": Pokemon("بيرسيان", "عادي", 50, 100, 130, 90, 80, 85, 140, ["Slash", "Knock Off", "Sucker Punch", "U-turn"]),
    "Hypno": Pokemon("هيبنو", "نفسي", 53, 113, 86, 103, 131, 103, 97, ["Psychic", "Focus Blast", "Shadow Ball", "Dazzling Gleam"]),
    "Ninetales": Pokemon("ناينتيلز", "نار", 52, 99, 111, 92, 131, 107, 121, ["Nasty Plot", "Fire Blast", "Solar Beam", "Dazzling Gleam"]),
    "Rapidash": Pokemon("رابيداش", "نار/أرضي", 52, 103, 140, 90, 120, 95, 140, ["Earthquake", "Bounce", "Fire Blast", "Close Combat"]),
    "Steelix": Pokemon("ستيليكس", "فولاذي/أرضي", 55, 130, 166, 211, 76, 91, 76, ["Earthquake", "Iron Head", "Stone Edge", "Flash Cannon"]),
    "Kingdra": Pokemon("كينجدرا", "ماء/نين", 55, 122, 134, 115, 166, 95, 85, ["Hydro Pump", "Dragon Pulse", "Outrage", "Focus Blast"]),
    "Gengar": Pokemon("جينجار", "幽灵/سم", 55, 120, 75, 103, 181, 110, 166, ["Shadow Ball", "Focus Blast", "Sludge Bomb", "Substitute"]),
    "Sandking": Pokemon("سندكينج", "أرضي", 55, 120, 156, 166, 116, 146, 120, ["Earthquake", "Stone Edge", "Stealth Rock", "Toxic Spikes"]),
    "Dugtrio": Pokemon("دوجتريو", "أرضي", 50, 67, 151, 106, 86, 96, 166, ["Earthquake", "Stone Edge", "Aerial Ace", "Sucker Punch"]),
    "Vileplume": Pokemon("فايلبلوم", "عشبي/سم", 53, 141, 111, 106, 146, 116, 76, ["Solar Beam", "Sludge Bomb", "Dazzling Gleam", "Synthesis"]),
    "Victreebel": Pokemon("فيكتريبل", "عشبي/سم", 53, 130, 141, 92, 146, 106, 121, ["Solar Beam", "Sludge Bomb", "Close Combat", "Sleep Powder"]),
}

"""
Trainers Module - المدربين والخصوم والمناطق الجديدة
يتضمن الخصوم والجيم ليدرز الجدد والمناطق المختلفة والنخبة الأربعة
"""

from pokemon import ALL_POKEMON

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
        self.status = "صحي"
        self.base_hp = hp

    def take_damage(self, damage):
        self.hp = max(0, self.hp - damage)
        return self.hp

    def heal(self):
        self.hp = self.max_hp
        self.status = "صحي"

    def is_alive(self):
        return self.hp > 0


class Trainer:
    def __init__(self, name, team, level, title="مدرب"):
        self.name = name
        self.team = team
        self.level = level
        self.title = title
        self.pokemons = []
        self.current_pokemon_index = 0
        self.money = 0
        self.load_team()

    def load_team(self):
        """تحميل فريق البوكيمون"""
        for pokemon_name in self.team:
            if pokemon_name in ALL_POKEMON:
                pokemon_copy = ALL_POKEMON[pokemon_name]
                new_pokemon = Pokemon(
                    pokemon_copy.name,
                    pokemon_copy.ptype,
                    self.level,
                    pokemon_copy.hp * self.level // 50,
                    pokemon_copy.attack,
                    pokemon_copy.defense,
                    pokemon_copy.sp_attack,
                    pokemon_copy.sp_defense,
                    pokemon_copy.speed,
                    pokemon_copy.moves
                )
                self.pokemons.append(new_pokemon)

    def get_current_pokemon(self):
        """الحصول على البوكيمون الحالي"""
        if self.current_pokemon_index < len(self.pokemons):
            return self.pokemons[self.current_pokemon_index]
        return None

    def switch_pokemon(self):
        """تبديل إلى البوكيمون التالي"""
        self.current_pokemon_index += 1
        if self.current_pokemon_index >= len(self.pokemons):
            return False
        return True

    def has_active_pokemon(self):
        """التحقق من وجود بوكيمون نشط حي"""
        for pokemon in self.pokemons:
            if pokemon.is_alive():
                return True
        return False

    def display_info(self):
        return f"""
{self.title}: {self.name}
المستوى: {self.level}
عدد البوكيمونات: {len(self.pokemons)}
الفريق: {', '.join([p.name for p in self.pokemons])}
"""


class GymLeader(Trainer):
    def __init__(self, name, team, level, gym_type, badge_name, region):
        super().__init__(name, team, level, "قائد الصالة")
        self.gym_type = gym_type
        self.badge_name = badge_name
        self.region = region

    def display_info(self):
        return f"""
🏆 قائد الصالة: {self.name}
المنطقة: {self.region}
الصالة: {self.gym_type}
الشارة: {self.badge_name}
المستوى: {self.level}
الفريق: {', '.join([p.name for p in self.pokemons])}
"""


class EliteFourMember(Trainer):
    def __init__(self, name, team, level, specialty, rank):
        super().__init__(name, team, level, "عضو النخبة الأربعة")
        self.specialty = specialty
        self.rank = rank

    def display_info(self):
        return f"""
⭐ {self.rank}: {self.name}
التخصص: {self.specialty}
المستوى: {self.level}
الفريق: {', '.join([p.name for p in self.pokemons])}
"""


class Champion(Trainer):
    def __init__(self, name, team, level, region):
        super().__init__(name, team, level, "بطل المنطقة")
        self.wins = 0
        self.record = "0-0"
        self.region = region

    def display_info(self):
        return f"""
👑 بطل المنطقة: {self.name}
المنطقة: {self.region}
المستوى: {self.level}
السجل: {self.record}
الفريق: {', '.join([p.name for p in self.pokemons])}
"""


# ===== منطقة كانتو (Kanto) =====
KANTO_GYM_LEADERS = {
    "بروك": GymLeader("بروك", ["Steelix", "Golem", "Onix"], 12, "صالة الصخور", "شارة البولدر", "كانتو"),
    "ميسي": GymLeader("ميسي", ["Lapras", "Blastoise", "Gyarados"], 19, "صالة الماء", "شارة القطرة", "كانتو"),
    "إيكان": GymLeader("إيكان", ["Vileplume", "Victreebel", "Venusaur"], 21, "صالة النبات", "شارة الأوراق", "كانتو"),
    "إياب": GymLeader("إياب", ["Rapidash", "Arcanine", "Charizard"], 24, "صالة النار", "شارة الحريق", "كانتو"),
    "سابرينا": GymLeader("سابرينا", ["Alakazam", "Espeon", "Gengar"], 28, "صالة النفسي", "شارة العقل", "كانتو"),
    "جينجي": GymLeader("جينجي", ["Raichu", "Electrode", "Magneton"], 33, "صالة الكهرباء", "شارة البرق", "كانتو"),
    "ليسانفيل": GymLeader("ل��سانفيل", ["Lapras", "Cloyster", "Slowbro"], 40, "صالة الجليد", "شارة الجليد", "كانتو"),
    "بليماي": GymLeader("بليماي", ["Arcanine", "Golem", "Dragonite"], 48, "صالة الأرض", "شارة الأرض", "كانتو"),
}

# ===== منطقة جوتو (Johto) =====
JOHTO_GYM_LEADERS = {
    "فالك": GymLeader("فالك", ["Pidgeot", "Rapidash", "Crobat"], 16, "صالة الطائر", "شارة النسر", "جوتو"),
    "باجا": GymLeader("باجا", ["Ampharos", "Electrode", "Raichu"], 25, "صالة الكهرباء", "شارة الوميض", "جوتو"),
    "ويتني": GymLeader("ويتني", ["Miltank", "Azumarill", "Cloyster"], 30, "صالة الحيوان", "شارة الحيوية", "جوتو"),
    "مورتي": GymLeader("مورتي", ["Gengar", "Misdreavus", "Gengar"], 32, "صالة الأشباح", "شارة الشبح", "جوتو"),
    "تشاك": GymLeader("تشاك", ["Heracross", "Ursaring", "Machamp"], 38, "صالة القتالي", "شارة القتال", "جوتو"),
    "جاسمين": GymLeader("جاسمين", ["Steelix", "Magneton", "Scizor"], 40, "صالة الفولاذ", "شارة الحديد", "جوتو"),
    "برايس": GymLeader("برايس", ["Sealeo", "Lapras", "Piloswine"], 42, "صالة الجليد", "شارة الندفة", "جوتو"),
    "كلان": GymLeader("كلان", ["Kingdra", "Gyarados", "Lapras"], 46, "صالة البحار", "شارة الموجة", "جوتو"),
}

# ===== منطقة هوين (Hoenn) =====
HOENN_GYM_LEADERS = {
    "روكسي": GymLeader("روكسي", ["Nosepass", "Sandslash", "Steelix"], 19, "صالة الصخور", "شارة الحجر", "هوين"),
    "بيبي": GymLeader("بيبي", ["Dewgong", "Lapras", "Sealeo"], 22, "صالة الجليد", "شارة الثلج", "هوين"),
    "واتسون": GymLeader("واتسون", ["Magneton", "Raichu", "Electrode"], 24, "صالة الكهرباء", "شارة البرق", "هوين"),
    "نورمان": GymLeader("نورمان", ["Slaking", "Snorlax", "Porygon2"], 28, "صالة عادي", "شارة التوازن", "هوين"),
    "تاتي": GymLeader("تاتي", ["Solrock", "Lunatone", "Claydol"], 30, "صالة النفسي", "شارة العقل", "هوين"),
    "جوان": GymLeader("جوان", ["Swampert", "Milotic", "Cradily"], 34, "صالة الماء", "شارة الموجة", "هوين"),
    "والاس": GymLeader("والاس", ["Gyarados", "Crobat", "Luvdisc"], 40, "صالة العشبي", "شارة الإزهار", "هوين"),
    "فوان": GymLeader("فوان", ["Blaziken", "Arcanine", "Typhlosion"], 43, "صالة النار", "شارة الحريق", "هوين"),
}

# ===== منطقة سينوه (Sinnoh) =====
SINNOH_GYM_LEADERS = {
    "روراك": GymLeader("روراك", ["Geodude", "Golem", "Steelix"], 16, "صالة الصخور", "شارة الحجر", "سينوه"),
    "جاردينيا": GymLeader("جاردينيا", ["Roserade", "Vileplume", "Victreebel"], 20, "صالة النبات", "شارة الأوراق", "سينوه"),
    "فانيسا": GymLeader("فانيسا", ["Medicham", "Heracross", "Machamp"], 22, "صالة القتالي", "شارة القتال", "سينوه"),
    "مايرز": GymLeader("مايرز", ["Manectric", "Electrode", "Pikachu"], 25, "صالة الكهرباء", "شارة البرق", "سينوه"),
    "كاناتا": GymLeader("كاناتا", ["Gengar", "Mismagius", "Spiritomb"], 27, "صالة الأشباح", "شارة الشبح", "سينوه"),
    "كيستون": GymLeader("كيستون", ["Bronzong", "Magnezone", "Porygon2"], 32, "صالة الفولاذ", "شارة الحديد", "سينوه"),
    "شيرلي": GymLeader("شيرلي", ["Lapras", "Dewgong", "Piloswine"], 35, "صالة الجليد", "شارة الندفة", "سينوه"),
    "فولكنر": GymLeader("فولكنر", ["Pidgeot", "Crobat", "Salamence"], 47, "صالة الطائر", "شارة الريشة", "سينوه"),
}

# ===== منطقة أونيما (Unova) =====
UNOVA_GYM_LEADERS = {
    "تيريج": GymLeader("تيريج", ["Gigalith", "Probopass", "Steelix"], 20, "صالة الصخور", "شارة الحجر", "أونيما"),
    "إيليسا": GymLeader("إيليسا", ["Ampharos", "Magnezone", "Rotom"], 24, "صالة الكهرباء", "شارة البرق", "أونيما"),
    "كلاي": GymLeader("كلاي", ["Excadrill", "Sandslash", "Golem"], 26, "صالة الأرض", "شارة الأرض", "أونيما"),
    "إيليت": GymLeader("إيليت", ["Medicham", "Heracross", "Throh"], 29, "صالة القتالي", "شارة القتال", "أونيما"),
    "شيراه": GymLeader("شيراه", ["Heatmor", "Blaziken", "Infernape"], 31, "صالة النار", "شارة الحريق", "أونيما"),
    "جيم": GymLeader("جيم", ["Swampert", "Empoleon", "Samurott"], 33, "صالة الماء", "شارة الموجة", "أونيما"),
    "شومانت": GymLeader("شومانت", ["Serperior", "Venusaur", "Vileplume"], 35, "صالة النبات", "شارة الأوراق", "أونيما"),
    "آيريس": GymLeader("آيريس", ["Haxorus", "Salamence", "Dragonite"], 43, "صالة النين", "شارة النين", "أونيما"),
}

# ===== النخبة الأربعة (Elite Four) =====
ELITE_FOUR = {
    "لوريليي": EliteFourMember("لوريليي", ["Articuno", "Lapras", "Cloyster"], 54, "متخصصة الجليد", "🥈 الأولى"),
    "برونو": EliteFourMember("برونو", ["Machamp", "Golem", "Heracross"], 55, "متخصص القتالي", "🥈 الثانية"),
    "أجاذا": EliteFourMember("أجاذا", ["Gengar", "Arcanine", "Alakazam"], 56, "متخصصة المتنوع", "🥈 الثالثة"),
    "لورينس": EliteFourMember("لورينس", ["Dragonite", "Gyarados", "Salamence"], 58, "متخصص النين", "🥈 الرابعة"),
}

# ===== أبطال المناطق (Region Champions) =====
CHAMPIONS = {
    "كانتو": Champion("أحمر", ["Pikachu", "Charizard", "Blastoise", "Venusaur", "Dragonite", "Mewtwo"], 65, "كانتو"),
    "جوتو": Champion("سوبا", ["Typhlosion", "Feraligatr", "Meganium", "Tyranitar", "Lugia", "Ho-Oh"], 62, "جوتو"),
    "هوين": Champion("والاس", ["Swampert", "Milotic", "Cradily", "Salamence", "Rayquaza", "Kyogre"], 60, "هوين"),
    "سينوه": Champion("سينثيا", ["Garchomp", "Lucario", "Roserade", "Spiritomb", "Togekiss", "Milotic"], 62, "سينوه"),
    "أونيما": Champion("آيريس", ["Haxorus", "Salamence", "Dragonite", "Garchomp", "Druddigon", "Emolga"], 60, "أونيما"),
}

# ضبط إحصائيات الأبطال
for champion in CHAMPIONS.values():
    champion.record = f"{champion.level * 2}-1"
    champion.wins = champion.level * 2

# ===== المنافسين الأوائل (Rivals) =====
RIVALS = {
    "أحمر": Trainer("أحمر", ["Pikachu", "Charizard", "Dragonite"], 5, "منافس"),
    "أزرق": Trainer("أزرق", ["Pidgeot", "Raichu", "Alakazam"], 8, "عدو"),
    "الأخت": Trainer("مايا", ["Pikachu", "Rapidash", "Ninetales"], 7, "عدو"),
}

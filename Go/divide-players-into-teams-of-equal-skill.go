func dividePlayers(skill []int) int64 {
	sum := 0
	skillMap := map[int]int{}
	for _, s := range skill {
		skillMap[s]++
		sum += s
	}
	teams := len(skill) / 2
	if sum%teams != 0 {
		return -1
	}
	teamSkill := sum / teams
	sumPairs := int64(0)
	for k := range skillMap {
		if skillMap[k] == 0 {
			continue
		}
		other := teamSkill - k
		if skillMap[other] == 0 || skillMap[k] != skillMap[other] {
			return -1
		}
		sumPairs += int64(k) * int64(other) * int64(skillMap[k])
	}
	return sumPairs / 2
}
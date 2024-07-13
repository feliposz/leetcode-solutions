func survivedRobotsHealths(positions []int, healths []int, directions string) []int {
	robots := make([]robot, len(positions))
	for i := range robots {
		direction := 1
		if directions[i] == 'L' {
			direction = -1
		}
		robots[i] = robot{
			i + 1,
			positions[i],
			healths[i],
			direction,
		}
	}
	slices.SortFunc(robots, func(a, b robot) int {
		return a.pos - b.pos
	})

    stack := []int{}
    for i := range robots {
        if robots[i].dir == 1 {
            stack = append(stack, i)
        } else {
            for len(stack) > 0 {
                top := stack[len(stack)-1]
                stack = stack[:len(stack)-1]
                if robots[top].health > robots[i].health {
                    robots[top].health--
                    robots[i].health = 0
                    if robots[top].health > 0 {
                        stack = append(stack, top)
                        break                        
                    }
                } else if robots[top].health < robots[i].health {
                    robots[i].health--
                    robots[top].health = 0
                    if robots[i].health == 0 {
                        break
                    }
                } else {
                    robots[i].health = 0
                    robots[top].health = 0
                    break
                }
            }
        }
    }
    slices.SortFunc(robots, func(a, b robot) int {
		return a.id - b.id
	})
    res := []int{}
	for i := range robots {
        if robots[i].health > 0 {
		    res = append(res, robots[i].health)
        }
	}
	return res
}

func TLE_survivedRobotsHealths(positions []int, healths []int, directions string) []int {
	robots := make([]robot, len(positions))
	for i := range robots {
		direction := 1
		if directions[i] == 'L' {
			direction = -1
		}
		robots[i] = robot{
			i + 1,
			positions[i],
			healths[i],
			direction,
		}
	}
	slices.SortFunc(robots, func(a, b robot) int {
		return a.pos - b.pos
	})
	// count := 100
	canCollide := true
	for canCollide && len(robots) > 0 {
		// count--
		// if count == 0 {
		// 	break
		// }
		// fmt.Printf("%v\n", robots)
		canCollide = false
		hadCollision := false
		for i := 1; i < len(robots); i++ {
			if robots[i-1].dir == 1 && robots[i].dir == -1 {
				canCollide = true
			} else {
                continue
            }
			if robots[i-1].pos == robots[i].pos ||
				(robots[i-1].pos+1 == robots[i].pos &&
					robots[i-1].dir == 1 &&
					robots[i].dir == -1) {
				if robots[i-1].health < robots[i].health {
					robots[i-1].health = 0
					robots[i].health--
				} else if robots[i-1].health > robots[i].health {
					robots[i-1].health--
					robots[i].health = 0
				} else {
					robots[i-1].health = 0
					robots[i].health = 0
				}
				hadCollision = true
			}
		}
		if hadCollision {
			robots = slices.DeleteFunc(robots, func(r robot) bool {
				return r.health <= 0
			})
		} else {
			for i := range robots {
				robots[i].pos += robots[i].dir
			}
		}
	}
	slices.SortFunc(robots, func(a, b robot) int {
		return a.id - b.id
	})
	res := make([]int, len(robots))
	for i := range robots {
		res[i] = robots[i].health
	}
	return res
}

type robot struct {
	id, pos, health, dir int
}
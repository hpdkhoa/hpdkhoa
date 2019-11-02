package LeetCode

import "math"

func reverse(x int) int {
	result := 0
	for{
		if v:= x/10; v != 0{
			result = result * 10 + x % 10
			x = v
		} else{
			result = result * 10 + x
			if result <= int(math.Pow(2,31)) - 1 && result >= -int(math.Pow(2,31)){
				return result
			} else{
				return 0
			}
		}
	}
}
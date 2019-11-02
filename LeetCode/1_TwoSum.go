package LeetCode

func TwoSum (nums [] int, target int) [] int {
	for i := 0; i<= len(nums) - 1; i++ {
		for j := i; j <= len(nums); j++{
			if nums[i] + nums[j] == target {
				return []int{nums[i],nums[j]}
			}
		}
	}
	return []int{-1}
}

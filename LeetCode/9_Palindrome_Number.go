package LeetCode

func isPalindrome(x int) bool {
	if x < 0 {
		return false;
	}
	temp := x;
	reverse := 0;
	for temp > 0{
		reverse = reverse * 10 + temp % 10;
		temp /= 10;
	}
	temp =x;
	for reverse != 0 {
		if reverse % 10 == temp % 10 {
			reverse /= 10;
			temp /= 10;
		} else {
			return false;
		}
	}
	return true;
}
}

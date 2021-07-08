package main

import "fmt"

func main() {
	nums := []int{4, 5, 6, 7, 0, 1, 2}
	fmt.Println("0", search(nums, 4))
	fmt.Println("1", search(nums, 5))
	fmt.Println("2", search(nums, 6))
	fmt.Println("3", search(nums, 7))
	fmt.Println("4", search(nums, 0))
	fmt.Println("5", search(nums, 1))
	fmt.Println("6", search(nums, 2))
	fmt.Println("-1", search(nums, 3))
	fmt.Println("-1", search(nums, 3000))
	fmt.Println("-------")

	nums = []int{4, 5, 6, 7, 8, 1, 2, 3}
	fmt.Println("4", search(nums, 8))
	fmt.Println("-------")

	nums = []int{8, 1, 2, 3, 4, 5, 6, 7}
	fmt.Println("6", search(nums, 6))
	fmt.Println("-------")

	nums = []int{5, 1, 2, 3, 4}
	fmt.Println("0", search(nums, 5))
	fmt.Println("1", search(nums, 1))
	fmt.Println("2", search(nums, 2))
	fmt.Println("3", search(nums, 3))
	fmt.Println("4", search(nums, 4))
	fmt.Println("-------")

	nums = []int{1, 2, 3, 4, 5}
	fmt.Println("1", search(nums, 2))
	fmt.Println("-------")

	nums = []int{8, 9, 2, 3, 4}
	fmt.Println("1", search(nums, 9))
	fmt.Println("-------")

}

func search(nums []int, target int) int {

	start := 0
	end := len(nums) - 1

	return binarySearch(nums, target, start, end)

}

func binarySearch(nums []int, target int, start, end int) int {

	if start > end {
		return -1
	}

	if target == nums[start] {
		return start
	} else if target == nums[end] {
		return end
	}
	mid := start + (end-start)/2

	if nums[mid] == target {
		return mid
	}
	if start == end {
		return -1
	}
	if nums[start] > nums[end] {
		if nums[mid] > target {
			if nums[start] < target || nums[mid] < nums[end] {
				return binarySearch(nums, target, start, mid-1)
			} else {
				return binarySearch(nums, target, mid+1, end)
			}
		} else {
			if nums[end] > target || nums[mid] > nums[end] {
				return binarySearch(nums, target, mid+1, end)
			} else {
				return binarySearch(nums, target, start, mid-1)
			}
		}

	} else {
		if nums[mid] > target {
			return binarySearch(nums, target, start, mid-1)
		} else {
			return binarySearch(nums, target, mid+1, end)

		}
	}

	return -1

}

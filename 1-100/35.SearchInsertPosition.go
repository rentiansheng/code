package main

import "fmt"

func main() {
	nums := []int{1, 3, 5, 6}
	fmt.Println("0", searchInsert(nums, 0))
	fmt.Println("0", searchInsert(nums, 1))
	fmt.Println("1", searchInsert(nums, 2))
	fmt.Println("1", searchInsert(nums, 3))
	fmt.Println("2", searchInsert(nums, 4))
	fmt.Println("2", searchInsert(nums, 5))
	fmt.Println("3", searchInsert(nums, 6))
	fmt.Println("4", searchInsert(nums, 7))

	nums = []int{1, 3, 5, 6, 10}
	fmt.Println("0", searchInsert(nums, 0))
	fmt.Println("0", searchInsert(nums, 1))
	fmt.Println("1", searchInsert(nums, 2))
	fmt.Println("1", searchInsert(nums, 3))
	fmt.Println("2", searchInsert(nums, 4))
	fmt.Println("2", searchInsert(nums, 5))
	fmt.Println("3", searchInsert(nums, 6))
	fmt.Println("4", searchInsert(nums, 7))
	fmt.Println("5", searchInsert(nums, 11))
}

func searchInsert(nums []int, target int) int {
	end := len(nums) - 1
	if nums[0] > target {
		return 0
	}
	if nums[end] < target {
		return end + 1
	}
	return searchInsertIndex(nums, target, 0, end)
}

func searchInsertIndex(nums []int, target int, start, end int) int {
	mid := start + (end-start)/2

	if nums[mid] == target {
		return mid
	}
	if start > end {
		return start
	}
	if nums[mid] > target {
		return searchInsertIndex(nums, target, start, mid-1)
	}
	if nums[end] < target {
		return end + 1
	}

	return searchInsertIndex(nums, target, mid+1, end)
}

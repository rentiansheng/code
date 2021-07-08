package main

import (
	"fmt"
)

func main() {
	nums := []int{5, 7, 7, 8, 8, 10}
	fmt.Println("[3,4]", searchRange(nums, 8))
	fmt.Println("-------")

	nums = []int{2, 2}
	fmt.Println("[0,1]", searchRange(nums, 2))
	fmt.Println("-------")

}

func searchRange(nums []int, target int) []int {
	return searchRangeStep(nums, target, 0, len(nums)-1)
}

func searchRangeStep(nums []int, target int, start, end int) []int {
	if start > end {
		return []int{-1, -1}
	}

	mid := start + (end-start)/2

	if nums[mid] == target {
		left := searchRangeStepPart(nums, target, start, mid, true)
		right := searchRangeStepPart(nums, target, mid, end, false)
		return []int{left, right}
	} else if nums[mid] > target {
		return searchRangeStep(nums, target, start, mid-1)
	} else {
		return searchRangeStep(nums, target, mid+1, end)
	}

	return []int{-1, -1}
}

func searchRangeStepPart(nums []int, target, start, end int, isLeft bool) int {

	if start > end {
		return -1
	}
	mid := start + (end-start)/2
	if nums[mid] == target {
		index := -1
		if isLeft {
			index = searchRangeStepPart(nums, target, start, mid-1, isLeft)

		} else {
			index = searchRangeStepPart(nums, target, mid+1, end, isLeft)
		}
		if index == -1 {
			index = mid
		}
		return index
	} else if nums[mid] > target {
		return searchRangeStepPart(nums, target, start, mid-1, isLeft)
	} else {
		return searchRangeStepPart(nums, target, mid+1, end, isLeft)
	}

	return -1
}

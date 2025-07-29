func specialTriplets(nums []int) int {
    count := 0
    before := map[int]int{}
    after := map[int]int{}
    for i := 0; i < len(nums); i++ {
         after[nums[i]]++
    }
    for i := 0; i < len(nums); i++ {
        after[nums[i]]--
        count = (count + (before[nums[i]*2] * after[nums[i]*2]))%1000000007
        before[nums[i]]++
    }
    return count
}
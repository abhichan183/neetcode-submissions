class Solution {
    public boolean hasDuplicate(int[] nums) {
        List<Integer> dup=new ArrayList<>();
        for(int i:nums){
            if(dup.contains(i)) return true;
            else dup.add(i);
        }
        return false;
    }
}
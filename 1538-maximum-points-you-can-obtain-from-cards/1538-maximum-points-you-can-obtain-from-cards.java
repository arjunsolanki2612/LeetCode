class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int leftSum = 0, rightSum=0, maxSum = 0;

        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
            maxSum=leftSum;

           

        }

         int rightIdx = cardPoints.length - 1;

            for(int j = k-1; j>=0;  j--){
                leftSum-=cardPoints[j];
                rightSum = rightSum + cardPoints[rightIdx];
                rightIdx--;
                maxSum = Math.max(maxSum,rightSum+leftSum);
            }

        return maxSum;
    }
}
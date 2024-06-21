class Solution:
    def temperatureTrend(self, temperatureA: List[int], temperatureB: List[int]) -> int:
        max_cnt = 0
        cur_cnt = 0
        
        n = len(temperatureA)
        for i in range(1, n):
            if (temperatureA[i]>temperatureA[i-1] and temperatureB[i]>temperatureB[i-1]) or \
                (temperatureA[i] == temperatureA[i-1] and temperatureB[i] == temperatureB[i-1]) or \
                (temperatureA[i]<temperatureA[i-1] and temperatureB[i]<temperatureB[i-1]):
                print(i)
                cur_cnt += 1
            else:
                max_cnt = max(max_cnt, cur_cnt)
            
                cur_cnt = 0
                
        max_cnt = max(max_cnt, cur_cnt)

        return max_cnt
        

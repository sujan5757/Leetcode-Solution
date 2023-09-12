class Solution {
    public int minDeletions(String s) {
        Map<Character, Integer> charFrequency = new HashMap<>();
        
        Set<Integer> existingFrequencies = new HashSet<>();
        
        for (char c : s.toCharArray()) {
            charFrequency.put(c, charFrequency.getOrDefault(c, 0) + 1);
        }

        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);

        for (int freq : charFrequency.values()) {
            maxHeap.offer(freq);
        }

        int deletions = 0;
        while (!maxHeap.isEmpty()) {
            int curFreq = maxHeap.poll();
            
            while (curFreq > 0 && existingFrequencies.contains(curFreq)) {
                curFreq--;
                deletions++;
            }
            
            existingFrequencies.add(curFreq);
        }
        return deletions;
    }
}
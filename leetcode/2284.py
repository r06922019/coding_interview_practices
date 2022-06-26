class Solution:
    def largestWordCount(self, messages: List[str], senders: List[str]) -> str:
        counter = {}
        for i in range(len(messages)):
            if senders[i] not in counter:
                counter[senders[i]] = 0
            counter[senders[i]] += len(messages[i].split())
        max_count = max(counter.values())
        return max([name for name in counter if counter[name] == max_count])

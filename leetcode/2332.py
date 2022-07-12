class Solution:
    def latestTimeCatchTheBus(self, buses: List[int], passengers: List[int], capacity: int) -> int:
        passengers.sort()
        passengers_set = set(passengers)
        buses.sort()
        p_index = 0
        people = []
        for bus in buses:
            people = []
            while len(people) < capacity and p_index < len(passengers) and passengers[p_index] <= bus:
                people.append(passengers[p_index])
                p_index += 1
        ans = buses[-1] if len(people) < capacity else people[-1]-1
        while ans in passengers_set:
            ans -= 1
        return ans

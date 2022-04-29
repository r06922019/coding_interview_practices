class Data:
    total_time: int
    count: int

    def __init__(self):
        self.total_time = 0
        self.count = 0

    def include_new_data(self, diff_t: int) -> None:
        self.total_time += diff_t
        self.count += 1

    def get_average(self) -> float:
        return float(self.total_time) / self.count


class UndergroundSystem:
    id_to_start: Dict[str, Tuple[str, int]]
    start_station_to_end_station_total_time_and_count: Dict[str,
                                                            Dict[str, Data]]

    def __init__(self):
        self.id_to_start_station_time = {}
        self.start_station_to_end_station_total_time_and_count = {}

    def checkIn(self, id: int, station_name: str, t: int) -> None:
        self.id_to_start_station_time[id] = (station_name, t)

    def checkOut(self, id: int, end_station_name: str, end_t: int) -> None:
        start_station_name, start_t = self.id_to_start_station_time.pop(id)

        if start_station_name not in self.start_station_to_end_station_total_time_and_count:
            self.start_station_to_end_station_total_time_and_count[start_station_name] = {
            }

        if end_station_name not in self.start_station_to_end_station_total_time_and_count[start_station_name]:
            self.start_station_to_end_station_total_time_and_count[start_station_name][end_station_name] = Data(
            )

        self.start_station_to_end_station_total_time_and_count[start_station_name][end_station_name].include_new_data(
            end_t - start_t)

    def getAverageTime(self, start_station_name: str, end_station_name: str) -> float:
        return self.start_station_to_end_station_total_time_and_count[start_station_name][end_station_name].get_average()

# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)

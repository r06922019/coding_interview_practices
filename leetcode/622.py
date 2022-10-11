class MyCircularQueue:

    def __init__(self, k: int):
        self.q = [-1] * k
        self.k = k
        self.f = self.r = 0
        self.cur = 0

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        self.q[self.r] = value
        self.cur += 1
        self.r += 1
        if self.r == self.k:
            self.r = 0
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.q[self.f] = -1
        self.f += 1
        if self.f == self.k:
            self.f = 0
        self.cur -= 1
        return True

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self.q[self.f]

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        if self.r == 0:
            return self.q[self.k-1]
        else:
            return self.q[self.r-1]

    def isEmpty(self) -> bool:
        return self.cur == 0

    def isFull(self) -> bool:
        return self.cur == self.k


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()

class BrowserHistory:

    def __init__(self, homepage: str):
        self.history = [homepage]
        self.cur = 0

    def visit(self, url: str) -> None:
        self.history = self.history[:self.cur+1] + [url]
        self.cur += 1

    def back(self, steps: int) -> str:
        self.cur -= steps
        self.cur = max(self.cur, 0)
        return self.history[self.cur]

    def forward(self, steps: int) -> str:
        self.cur += steps
        self.cur = min(self.cur, len(self.history)-1)
        return self.history[self.cur]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)

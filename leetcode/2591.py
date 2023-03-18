class Solution:
    def distMoney(self, money: int, children: int) -> int:
        if money < children:
            return -1
        eights = money // 8
        remaining = money % 8
        if eights > children:
            return children - 1
        if eights == children and remaining > 0:
            return eights - 1
        if children == eights + 1 and remaining == 4:
            return eights-1
        while children-eights > remaining:
            eights -= 1
            remaining += 8
        return eights

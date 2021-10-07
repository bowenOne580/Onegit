# 双人简易斗地主
import random as r  # 导入随机数库
# 创建牌的数组
list = ['KING', 'SMALL', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A']
# 记录牌的次数
time = [1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4]

myCard = []
enemyCard = []
score = 100  # 基础分
a = 0  # 随机牌
b = 1  # 统计分发次数
boss = []  # 地主牌

# 随机发牌
while b != 38:
    a = r.randint(0, 14)
    if time[a] == 0:
        b -= 1
        pass
    elif b <= 17:
        myCard.append(list[a])
        time[a] -= 1
    elif 17 < b <= 20:
        boss.append(list[a])
        time[a] -= 1
    elif 20 < b <= 37:
        enemyCard.append(list[a])
        time[a] -= 1
    b += 1


# 创建排序方法（便于出牌）
def sort(a):
    l = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for i in range(len(a)):
        if a[i] == 'KING':
            l[14] += 1
        elif a[i] == '2':
            l[12] += 1
        elif a[i] == 'SMALL':
            l[13] += 1
        elif a[i] == 'K':
            l[10] += 1
        elif a[i] == 'Q':
            l[9] += 1
        elif a[i] == 'J':
            l[8] += 1
        elif a[i] == 'A':
            l[11] += 1
        else:
            a[i] = int(a[i])
            l[a[i] - 3] += 1
        # 将牌变为数字，便于比较
    j = 0
    for i in range(len(l)):
        while l[i] != 0:
            if i == 14:
                a[j] = 'KING'
            elif i == 13:
                a[j] = 'SMALL'
            elif i == 12:
                a[j] = '2'
            elif i == 11:
                a[j] = 'A'
            elif i == 10:
                a[j] = 'K'
            elif i == 9:
                a[j] = 'Q'
            elif i == 8:
                a[j] = 'J'
            else:
                a[j] = str(i + 3)
            l[i] -= 1
            j += 1
    return a


def sort2(a):  # 不同之处在于数组是整形的，输出的也是整形
    l = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for i in range(len(a)):
        if a[i] == 17:
            l[14] += 1
        elif a[i] == 15:
            l[12] += 1
        elif a[i] == 16:
            l[13] += 1
        elif a[i] == 13:
            l[10] += 1
        elif a[i] == 12:
            l[9] += 1
        elif a[i] == 11:
            l[8] += 1
        elif a[i] == 14:
            l[11] += 1
        else:
            l[a[i] - 3] += 1
        # 将牌变为数字，便于比较
    j = 0
    for i in range(len(l)):
        while l[i] != 0:
            if i == 14:
                a[j] = 17
            elif i == 13:
                a[j] = 16
            elif i == 12:
                a[j] = 15
            elif i == 11:
                a[j] = 14
            elif i == 10:
                a[j] = 13
            elif i == 9:
                a[j] = 12
            elif i == 8:
                a[j] = 11
            else:
                a[j] = i + 3
            l[i] -= 1
            j += 1
    return a  # b


# 找牌（在判断牌是否出错时要用）
def find(num, listName, start):
    flagTmp = 0
    for i in range(len(listName)):
        if listName[i] == num and i >= start and len(num) == len(listName[i]):
            flagTmp = 1
    if flagTmp == 0:
        return False
    else:
        return True


# 也是找牌（不同的是返回了牌的位置）
def find2(num, listName, start):
    i = 0
    flagTmp = 1
    for j in range(len(listName)):
        if listName[j] == num and j >= start and len(num) == len(listName[j]):
            flagTmp = 0
            break
        i += 1
    if flagTmp == 0:
        return i
    else:
        return False



d = 1  # 判断是否出牌变量

flag1 = 0
flag5 = 0
length = 0

def beat(c, d):  # 机器人打牌方法（较笨）
    global flag1, score, length
    length = len(c)
    enemyCard2 = []  # 存储整数型数组
    for i in range(len(c)):
        if c[i] == 'KING':
            c[i] = 17
        elif c[i] == '要不起':
            c[i] = 0
        elif c[i] == 'SMALL':
            c[i] = 16
        elif c[i] == '2':
            c[i] = 15
        elif c[i] == 'A':
            c[i] = 14
        elif c[i] == 'K':
            c[i] = 13
        elif c[i] == 'Q':
            c[i] = 12
        elif c[i] == 'J':
            c[i] = 11
        else:
            c[i] = int(c[i])
    # 输入的数组转为整数
    for i in range(len(enemyCard)):
        if enemyCard[i] == 'KING':
            enemyCard2.append(17)
        elif enemyCard[i] == 'SMALL':
            enemyCard2.append(16)
        elif enemyCard[i] == '2':
            enemyCard2.append(15)
        elif enemyCard[i] == 'A':
            enemyCard2.append(14)
        elif enemyCard[i] == 'K':
            enemyCard2.append(13)
        elif enemyCard[i] == 'Q':
            enemyCard2.append(12)
        elif enemyCard[i] == 'J':
            enemyCard2.append(11)
        else:
            enemyCard2.append(int(enemyCard[i]))
    # 敌方牌转为整数
    sort(enemyCard)
    sort2(enemyCard2)
    sort2(c)
    j = 1
    if length == 1:  # 应对出单张牌
        for i in range(len(enemyCard2)):
            if enemyCard2[i] > c[0]:
                print(enemyCard[i])
                enemyCard.pop(i)
                enemyCard2.pop(i)
                d = 0
                flag1 = 1
                break
    # 应对对子
    elif length == 2:
        if c[0] == 17 and c[1] == 16 or c[0] == 16 and c[1] == 17:
            score *= 5
        for i in range(len(enemyCard2) - 1):
            if enemyCard[i] == enemyCard[i + 1] and enemyCard2[i] > c[0]:
                print(enemyCard[i] + enemyCard[i + 1])
                enemyCard.pop(i + 1)
                enemyCard.pop(i)
                enemyCard2.pop(i + 1)
                enemyCard2.pop(i)
                d = 0
                flag1 = 1
                break
    # 应对三不带
    elif length == 3:
        for i in range(len(enemyCard2) - 2):
            if enemyCard2[i] == enemyCard2[i + 2] and enemyCard2[i] > c[0]:
                print(enemyCard[i] + enemyCard[i + 1] + enemyCard[i + 2])
                enemyCard.pop(i + 2)
                enemyCard.pop(i + 1)
                enemyCard.pop(i)
                enemyCard2.pop(i + 2)
                enemyCard2.pop(i + 1)
                enemyCard2.pop(i)
                d = 0
                flag1 = 1
                break
    # 应对三带一或者炸弹
    elif length == 4:
        for i in range(len(enemyCard2) - 1):
            if enemyCard2[i] == enemyCard2[i + 1] and enemyCard2[i] >= c[1]:
                j += 1
            else:
                j = 1
            if j == 3:
                flag1 = 1
                if c[0] != c[3]:
                    if enemyCard2[0] != enemyCard2[i] and enemyCard2[0] > c[0]:  # 三带一
                        print(enemyCard[i - 1] + enemyCard[i] + enemyCard[i + 1] + enemyCard[0])
                        enemyCard.pop(i + 1)
                        enemyCard.pop(i)
                        enemyCard.pop(i - 1)
                        enemyCard.pop(0)
                        enemyCard2.pop(i + 1)
                        enemyCard2.pop(i)
                        enemyCard2.pop(i - 1)
                        enemyCard2.pop(0)
                        d = 0
                        break

                    elif enemyCard2[i] > c[0] and i - 2 >= 0:
                        print(enemyCard[i - 1] + enemyCard[i] + enemyCard[i + 1] + enemyCard[i - 2])
                        enemyCard.pop(i + 1)
                        enemyCard.pop(i)
                        enemyCard.pop(i - 1)
                        enemyCard.pop(i - 2)
                        enemyCard2.pop(i + 1)
                        enemyCard2.pop(i)
                        enemyCard2.pop(i - 1)
                        enemyCard2.pop(i - 2)
                        d = 0
                        break

                    elif enemyCard2[i] == c[0] and i + 2 < length:
                        print(enemyCard[i - 1] + enemyCard[i] + enemyCard[i + 1] + enemyCard[i + 2])
                        enemyCard.pop(i + 2)
                        enemyCard.pop(i + 1)
                        enemyCard.pop(i)
                        enemyCard.pop(i - 1)
                        enemyCard2.pop(i + 2)
                        enemyCard2.pop(i + 1)
                        enemyCard2.pop(i)
                        enemyCard2.pop(i - 1)
                        d = 0
                        if enemyCard2[i + 2] == enemyCard2[i]:
                            score *= 2
                        break

                else:
                    if enemyCard2[i + 2] == enemyCard2[i + 1]:
                        print(enemyCard[i - 1] + enemyCard[i] + enemyCard[i + 1] + enemyCard[i + 2])
                        enemyCard.pop(i + 2)
                        enemyCard.pop(i + 1)
                        enemyCard.pop(i)
                        enemyCard.pop(i - 1)
                        enemyCard2.pop(i + 2)
                        enemyCard2.pop(i + 1)
                        enemyCard2.pop(i)
                        enemyCard2.pop(i - 1)
                        d = 0
                        score *= 2  # 炸弹积分
                        break

                    elif enemyCard[len(enemyCard) - 1] == 'KING' and enemyCard[len(enemyCard) - 2] == 'SMALL':
                        print(enemyCard[len(enemyCard)-1]+enemyCard[len(enemyCard)-2])
                        enemyCard.pop(len(enemyCard) - 1)
                        enemyCard.pop(len(enemyCard) - 2)
                        enemyCard2.pop(len(enemyCard) - 1)
                        enemyCard2.pop(len(enemyCard) - 2)
                        d = 0
                        score *= 5  # 炸弹积分
                        break
    # 大于四张是顺子，三带二或连对
    elif length > 4:
        flag1 = 1
        if c[0] + 1 == c[1]:  # 判断是否是顺子
            a = c[0] + 1  # 从敌方牌下限开始找起
            times = 0  # 存储连续牌的数量
            while times != length:  # 一直到与出的牌数相同为止
                if a == 15:
                    break
                if find(a, enemyCard2, 0):
                    times += 1
                else:
                    times = 0
                a += 1
            a -= 1
            if times == length:
                i = 0
                while i != length:
                    j = find2(a - length + i + 1, enemyCard2, 0)
                    print(enemyCard[j], end="")
                    enemyCard.pop(j)
                    enemyCard2.pop(j)
                    i += 1
                d = 0
                print()
        # 此处是三带二，尚未完善
        '''
        elif length == 5 and c[0] == c[1]:
        '''

    # 不出牌
    if d == 1:
        print("要不起")


def wrong(c3, c2, aa, flag):
    global flag5, length
    if flag5 == 0:
        length = len(c3)
        flag5 = 1
    if c3 != '要不起':  # 只能处理int类型的变量
        # 若有人知道python里面数组到底存储的是什么，请留言，谢谢
        i = -1
        for j in range(len(c2)):
            if j != 0:
                if c2[j] < c2[j - 1]:
                    i = -1
            ifFind = find(c2[j], myCard, i + 1)
            if c2[j] == c2[j - 1]:
                i = find2(c2[j], myCard, i + 1)
            if not ifFind:
                aa = 0
    else:
        aa = 2
    if len(c3) != length:
        k = 1
        for i in range(len(c3)):
            if i>0:
                if c3[i] != c3[i-1]:
                    k = 0
        if k == 0:
            aa = 0
    if c3 == '':
        print('你还没有输入')
        return
    if flag == 2:
        aa = 2
    if aa == 1:
        for p in range(len(c2)):
            myCard.pop(find2(c2[p], myCard, 0))
        beat(c2, d)
    elif aa == 2:
        for p in range(len(c2)):
            if find(c2[p], myCard, 0):
                myCard.pop(find2(c2[p], myCard, 0))
        beat(c2, d)
    else:
        print("牌出错了")


sort(enemyCard)
sort(myCard)

now = "start"

ki=1

while ki == 1:
    print("1:开始")
    print("2.帮助")
    print("3.关于")
    print("4.退出")
    uc = input()
    if uc == '1': now = "ingame"
    if uc == '2': now = "help"
    if uc == '3': now = "about"
    if uc == '4': break
    if now == 'ingame':
        # 看自己得到的牌
        print(sort(myCard))
        # 地主牌分发
        f = input("叫地主吗? 1.3分 2.2分 3.1分 4.不叫")
        if f == '1' or f == '2' or f == '3':
            for i in range(len(boss)):
                myCard.append(boss[i])
            score *= int(f) * 2
        else:
            for i in range(len(boss)):
                enemyCard.append(boss[i])
        # 开发人员模式
        usrAns = input("此次是否开启DEV模式（无视牌出错限制）？")
        flag = 0
        isFinish = 0
        isSee = 0
        if usrAns != 'y' and 'Y' and 'yes' and 'YES':
            flag = 1
        if flag == 0:
            print("开发人员模式已开启")
            flag = 2
            isFinish = 1
            isSee = 1
        sort(myCard)
        while len(myCard) != 0 and len(enemyCard) != 0:
            aa = 1
            bb = 0
            c2 = []  # c2存储字符串型列表（数组）
            if d == 1:  # d判断是否是出牌时机
                print(myCard)
                if isSee == 1:
                    print("ENEMY:")
                    print(enemyCard)
                # 输入牌到出牌组中
                c3 = input("请出牌")
                if c3 == '要不起':
                    c2.append('要不起')
                    # 特殊情况，无法用数字表示
                elif c3 == 'Ter' or c3 == 'ter' and isFinish == 1:
                    ki = 0
                    break
                    # 开启开发模式后可用立即终止出牌功能，以便测试特殊数据
                else:
                    i = 0
                    while i < len(c3):  # 遍历数组写入c2
                        if c3[i] == '1':
                            if len(c3) == 1:
                                c2.append('1')
                            else:
                                c2.append('10')
                        elif c3[i] == '0':
                            if c3[i-1] == '1':
                                pass
                            else:
                                c2.append('0')
                        elif c3[i] == 'I':
                           c2.pop()
                           c2.append('KING')
                           i += 2
                           bb += 1
                           pass
                        elif c3[i] == 'S' and len(c3) > 1:
                            c2.append('SMALL')
                            i += 4
                            bb += 1
                            pass
                        else:
                            c2.append(c3[i])
                        i += 1
                # 判断牌是否出错
                wrong(c3, c2, aa, flag)
                enemyCard = sort(enemyCard)
                d = 1
    if now == 'help':
        print("该游戏由三人个玩一副牌，地主是一方，其余两家为另一方，双方对战，先出完的一方胜。"+"\n"
        +"如叫牌，可为自己增加三张牌"+"\n"+"出牌时，牌的张数要与上家出牌张数相同，且牌的大小要大于上家出牌大小"+"\n"+"可以出三带一，炸弹")
    elif now == 'about':
        print("Release Date:1/31/2021"+"\n"+"Written by wbw"+"\n"+"Edition:Spring Second Edition(2.1.1)")

# 最后输出谁胜利
if len(myCard) == 0:
    print('你赢了')
elif len(enemyCard) == 0:
    print('你输了')
if flag1 == 0:
    score *= 10
print('你的得分:' + str(score))

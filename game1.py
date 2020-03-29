# 双人简易斗地主
import random as r  # 导入随机数库

# 创建牌的数组
list = ['KING', 'SMALL', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A']
# 记录牌的次数
time = [1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4]

myCard = []
enemyCard = []
score = 100
a = 0  # 随机牌
b = 1  # 统计分发次数
boss = []  # 地主牌

# 随机发牌
while b != 38:
    a = r.randint(0, 14)
    if time[a] == 0:
        b -= 1
        pass
    if time[a] != 0 and b <= 17:
        myCard.append(list[a])
        time[a] -= 1
    elif 17 < b <= 20 and time[a] != 0:
        boss.append(list[a])
        time[a] -= 1
    elif 20 < b <= 37 and time[a] != 0:
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


# 找牌（在判断牌是否出错时要用）
def find(num, listName, start):
    aaa = 0
    for i in range(len(listName)):
        if listName[i] == num and i >= start:
            aaa = 1
    if aaa == 0:
        return False
    else:
        return True


# 也是找牌（不同的是返回了牌的位置）
def find2(num, listName, start):
    i = 0
    aaa = 1
    for j in range(len(listName)):
        if listName[j] == num and j >= start:
            aaa = 0
            break
        i += 1
    if aaa == 0:
        return i
    else:
        return False


# 看自己得到的牌
print(sort(myCard))
# 地主牌分发
f = input("叫地主吗? 1.3分 2.2分 3.1分 4.不叫")
if f == '1' or f == '2' or f == '3':
    for i in range(len(boss)):
        myCard.append(boss[i])
    score *= f * 2  # 分数方法现未完善
else:
    for i in range(len(boss)):
        enemyCard.append(boss[i])

d = 1  # 判断是否出牌变量


def beat(c, d, score):  # 机器人打牌方法（较笨）
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
    sort(enemyCard2)
    for i in range(len(enemyCard2)):
        if enemyCard2[i] == 'KING':
            enemyCard2.append(17)
        elif enemyCard2[i] == 'SMALL':
            enemyCard2.append(16)
        elif enemyCard2[i] == '2':
            enemyCard2.append(15)
        elif enemyCard2[i] == 'A':
            enemyCard2.append(14)
        elif enemyCard2[i] == 'K':
            enemyCard2.append(13)
        elif enemyCard2[i] == 'Q':
            enemyCard2.append(12)
        elif enemyCard2[i] == 'J':
            enemyCard2.append(11)
        else:
            enemyCard2.append(int(enemyCard2[i]))
    for i in range(int(len(enemyCard2) / 2)):
        enemyCard2.pop(0)
    j = 1
    if length == 1:  # 应对出单张牌
        for i in range(len(enemyCard2)):
            if enemyCard2[i] > c[0]:
                print(enemyCard[i])
                enemyCard.pop(i)
                enemyCard2.pop(i)
                d = 0
                break
    # 应对对子
    elif length == 2:
        if c[0] == 'KING':
            score *= 5
        for i in range(len(enemyCard2) - 1):
            if enemyCard2[i] == enemyCard2[i + 1] and enemyCard2[i] > c[0]:
                print(enemyCard[i] + enemyCard[i + 1])
                enemyCard.pop(i + 1)
                enemyCard.pop(i)
                enemyCard2.pop(i + 1)
                enemyCard2.pop(i)
                d = 0
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
                break
    # 应对三带一或者炸弹
    elif length == 4:
        for i in range(len(enemyCard2) - 1):
            if enemyCard2[i] == enemyCard2[i + 1] and enemyCard2[i] > c[0]:
                j += 1
            else:
                j = 0

            if j == 2:
                if c[0] != c[3]:
                    if enemyCard2[0] != enemyCard2[i]:
                        print(enemyCard[i - 1] + enemyCard[i] + enemyCard[i + 1] + enemyCard[0])
                        enemyCard.pop(i + 1)
                        enemyCard.pop(i)
                        enemyCard.pop(i - 1)
                        enemyCard.pop(0)
                        enemyCard2.pop(i + 1)
                        enemyCard2.pop(i)
                        enemyCard2.pop(i - 1)
                        enemyCard2.pop(0)
                        break

                    elif enemyCard2[i + 2] != enemyCard2[i]:
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
                        break

                    else:
                        print(enemyCard[i - 1] + enemyCard[i] + enemyCard[i + 1] + enemyCard[i + 3])
                        enemyCard.pop(i + 3)
                        enemyCard.pop(i + 1)
                        enemyCard.pop(i)
                        enemyCard.pop(i - 1)
                        enemyCard2.pop(i + 3)
                        enemyCard2.pop(i + 1)
                        enemyCard2.pop(i)
                        enemyCard2.pop(i - 1)
                        d = 0
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
                        print('王炸')
                        enemyCard.pop(len(enemyCard) - 1)
                        enemyCard.pop(len(enemyCard) - 2)
                        enemyCard2.pop(len(enemyCard) - 1)
                        enemyCard2.pop(len(enemyCard) - 2)
                        d = 0
                        score *= 5  # 炸弹积分
                        break
    # 大于四张是顺子，现未完善
    '''
    elif length>4:
        if c[0]+1==c[1]:
            a=c[0]+1
            times=0
            boo=0
            while a+length-1!=15:
                if boo==1:
                    print('ok')
                    if find2(a-1,enemyCard2):
                        i=find2(a-1,enemyCard2)
                        while i<=i+length:
                            print(enemyCard[i])
                            enemyCard.pop(i)
                            enemyCard2.pop(i)
                        d=0
                        break
                times=0
                while times!=length:
                    if find(a,enemyCard2):
                        boo=1
                    else:
                        boo=0
                    times+=1
                a+=1
    '''
    # 不出牌
    if d == 1:
        print("要不起")


while len(myCard) != 0 and len(enemyCard) != 0:
    aa = 1
    c2 = []  # c2存储字符串型列表（数组）
    if d == 1:  # d判断是否是出牌时机
        print(sort(myCard))
        # 输入牌到出牌组中
        c3 = input("请出牌")
        if c3 == '要不起':
            c2.append('要不起')
            # 特殊情况，无法用数字表示
        else:
            for i in range(len(c3)):  # 遍历数组写入c2
                if c3[i] == '1':
                    c2.append('10')
                elif c3[i] == '0':
                    pass
                elif c3[i] == 'K' and c3[i + 1] == 'I':
                    c2.append('KING')
                    i += 3
                elif c3[i] == 'S' and c3[i + 1] == 'M':
                    c2.append('SMALL')
                    i += 4
                else:
                    c2.append(c3[i])
        # 判断牌是否出错
        if c3 != '要不起':  # 只能处理int类型的变量
            # 若有人知道python里面数组到底存储的是什么，请留言，谢谢
            i = -1
            for j in range(len(c2)):
                ifFind = find(c2[j], myCard, i + 1)
                i = find2(c2[j], myCard, i + 1)
                if not ifFind:
                    aa = 0
        if aa == 1:
            for p in range(len(c2)):
                myCard.pop(find2(p, myCard, 0))
            beat(c2, d, score)
        else:
            print("牌出错了")
    enemyCard=sort(enemyCard)
    d = 1

# 最后输出谁胜利
if len(myCard) == 0:
    print('你赢了')
elif len(enemyCard) == 0:
    print('你输了')
print('你的得分:' + str(score))
# 注意：删除牌模块待完善，现在不可用
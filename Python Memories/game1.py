# 双人简易斗地主
import random as r  # 导入随机数库
import tkinter as tk  # 导入tkinterGUI模块

# 创建window窗口
# 初始化窗口
window = tk.Tk()  # 实例化，创建窗口
window.title("斗地主")  # 窗口的标题
window.geometry('600x480')  # 窗口的大小

# 定义所有是否碰到按钮变量
ifAbout = False  # 关于函数变量
ifStart = False  # 开始函数变量
ifQuit = False  # 退出函数变量
ifJump = False
ifEnter = False

var = 4  # 测试用途（和1,2,3区分开来）


# 定义函数


# 1.关于函数
def bAbout():
    global ifAbout
    if not ifAbout:
        ifAbout = True
        ab["text"] = "版本：v1.1.8(测试版本)" + "\n" + "Release Date:1/28/2021" + "\n" + "Written by wbw"
    else:
        ifAbout = False
        ab["text"] = ''


entry1 = tk.Entry(window, show=None)  # 叫分框


# 2.开始函数
def start():
    global ifStart, var
    if not ifStart:
        ifStart = True
        r1.pack()
        r2.pack()
        r3.pack()
        r4.pack()
        r5.pack()
        enter()
        confirm.pack()
        st["text"] = '结束游戏'
        window.title = '叫分'
    else:
        ifStart = False
        r1.pack_forget()
        r2.pack_forget()
        r3.pack_forget()
        r4.pack_forget()
        r5.pack_forget()
        entry1.pack_forget()
        confirm.pack_forget()
        st["text"] = '开始游戏'
        window.title = '斗地主'


def enter():
    global var
    entry1.pack()


# 跳转出牌界面函数
def jump():
    global ifJump, var, myCard, enemyCard, boss
    if not ifJump:
        ifJump = True
        r1.pack_forget()
        r2.pack_forget()
        r3.pack_forget()
        r4.pack_forget()
        r5.pack_forget()
        var = entry1.get()
        entry1.pack_forget()
        confirm.pack_forget()
        see()
    else:
        ifJump = False


# 此处叫分完毕

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
    aaa = 0
    for i in range(len(listName)):
        if listName[i] == num and i >= start and len(num) == len(listName[i]):
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
        if listName[j] == num and j >= start and len(num) == len(listName[j]):
            aaa = 0
            break
        i += 1
    if aaa == 0:
        return i
    else:
        return False


if var == '1' or var == '2' or var == '3':
    for i in range(len(boss)):
        myCard.append(boss[i])
else:
    for i in range(len(boss)):
        enemyCard.append(boss[i])
d = 1  # 判断是否出牌变量


def see():
    global ifJump
    if ifJump:
        sort(myCard)
        for i in range(0, 17):
            myCardShow.pack()
            myCardShow["text"] += myCard[i] + " "


def qu():
    global ifQuit
    if not ifQuit:
        ifQuit = True
        quit()
    else:
        ifQuit = False


# 以下为标签内容显示以及命令执行，写在函数下面是因为python执行顺序是从前往后的
# 参数说明：1.窗口对象名 2.显示的文本名 3.背景颜色 4.字体及字号 5.窗口宽度 6.窗口高度

# 此为欢迎文字的打印
l = tk.Label(window, text='欢迎来到斗地主', font=('Consolas', 14), width=20, height=2)

# 关于函数中的文字打印
ab = tk.Label(window)

myCardShow = tk.Label(window, text='', font=('Consolas', 14), width=50, height=3)

r1 = tk.Label(window, text='3分')
r2 = tk.Label(window, text='2分')
r3 = tk.Label(window, text='1分')
r4 = tk.Label(window, text='不叫（填0）')
r5 = tk.Label(window, text='您的选择：')

# 退出
q = tk.Button(window, text='退出', font=('Consolas', 12), width=10, height=1, command=qu)

# 开始按钮的打印
st = tk.Button(window, text='开始游戏', font=('Consolas', 12), width=10, height=1, command=start)

# 关于按钮的打印
b = tk.Button(window, text='关于', font=('Consolas', 12), width=10, height=1, command=bAbout)

# 确定按钮的打印
confirm = tk.Button(window, text='确定', font=('Consolas', 12), width=10, height=1, command=jump)

# 以下为放置标签 放置的顺序控制显示顺序
# 放置标签方式：1.标签名.pack 2.标签名.place
# 放置方式好像还有个grid，但区别未知

l.pack()
st.pack()
q.pack(side='bottom')
b.pack(side='bottom')
ab.pack(side='bottom')
print(var)
window.mainloop()  # 主窗口循环，类似于while True
# 地主牌分发
# print(var)
'''
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
    sort(enemyCard)
    sort2(enemyCard2)
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
            if enemyCard[i] == enemyCard[i + 1] and enemyCard2[i] > c[0]:
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
    # 大于四张是顺子，三带二或连对
    elif length > 4:
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
                j = 0
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
# elif length == 5 and c[0] == c[1]:
'''
    # 不出牌
    if d == 1:
        print("要不起")
def wrong(c3, c2, aa, flag):
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
    if c3 == '':
        aa = 0
    if flag == 2:
        aa = 2
    if aa == 1:
        for p in range(len(c2)):
            myCard.pop(find2(c2[p], myCard, 0))
        beat(c2, d, score)
    elif aa == 2:
        beat(c2, d, score)
    else:
        print("牌出错了")
# 开发人员模式
usrans = input("此次是否开启DEV模式（无视牌出错限制）？")
flag = 0
if usrans != 'y' and 'Y' and 'yes' and 'YES':
    flag = 1
if flag == 0:
    print("开发人员模式已开启")
    flag = 2
while len(myCard) != 0 and len(enemyCard) != 0:
    aa = 1
    bb = 0
    c2 = []  # c2存储字符串型列表（数组）
    if d == 1:  # d判断是否是出牌时机
        print(sort(myCard))
        # 输入牌到出牌组中
        c3 = input("请出牌")
        if c3 == '要不起':
            c2.append('要不起')
            # 特殊情况，无法用数字表示
        else:
            i = 0
            while i < len(c3):  # 遍历数组写入c2
                if c3[i] == '1':
                    c2.append('10')
                elif c3[i] == '0':
                    pass
                elif c3[i] == 'K' and len(c3) > 1:
                    c2.append('KING')
                    i += 3
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
# 最后输出谁胜利
if len(myCard) == 0:
    print('你赢了')
elif len(enemyCard) == 0:
    print('你输了')
print('你的得分:' + str(score))
'''



# a, b, c, d就是它的形式参数
def func_1(a, b, c, d):
    print("a=%d;b=%d;c=%d;d=%d;" %(a,b,c,d))
# x, y, z, w就是它的实际参数，可以跟上面的形参重名
x, y ,z, w =[1,2,3,4]
func_1(x,y,z,w)
#在函数体执行前就会形成a = x  b = y c =z d =w

#关键字实参同样由逗号分隔，区别在于要在实参前加上形参名=这样的前缀，从而实现了一种显式的参数匹配效果，
func_1(d=x,a=y,b=w,c=z)

'''
限定位置形参
从Python 3.8开始，p限定位置形参将可正式用于自定义函数中，它们必须放在形参表的最前面
，并在后面使用斜杠/（独占一个参数位）与普通形参分隔，比如下面这样# a, b, c成为限定位置形参

def func_2(a, b, c, /, d):
    pass
'''


'''
限定关键字形参（常叫命名关键字参数）为了限制后面几个参数只能按关键字传递，
这往往是因为后面几个形参名具有十分明显的含义，显式写出有利于可读性；
或者后面几个形参随着版本更迭很可能发生变化，强制关键字形式有利于保证跨版本兼容性。
'''
def func_3(x,y, *, kw1, kw2):
    print(x+y)
    print(kw1)
    print(kw2)

func_3(1,2,kw1=3,kw2=4)
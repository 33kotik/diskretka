# This is a sample Python script.

def make_set(name):
    name=list()
    return (name)


def new_set():
    print("Введите элементы множества в строчку через пробел")
    my_set=list(input())
    return my_set
def list_diference( list1, list2):
    ans=list()
    for element in list1:
        if element not in list2:
            ans.append(element)
    return ans
def rec_show (my_set,  permutations):
    if len(my_set) ==len(permutations):
        print(*permutations,sep=" ")
        # permutations=list()
        return
    # print(list_diference(my_set,permutations))
    for element in list_diference(my_set,permutations):
        next_step=permutations.copy()
        next_step.append(element)
        rec_show(my_set,next_step)

if __name__ == '__main__':
    my_set=("1","2","3","4")
    print( "множество по умолчанию 1 2 3 4 ")
    while True:
        print( "нажмите 1 для задания нового множества ")
        print("нажмите 2 для демонстрации всех пререстановок в лексекографическом порядке")
        print("нажмите 3 для демонстрации текущего множества")
        print("нажмите 4 для выхода")
        comand=input();
        if comand=="1":
            my_set=new_set()
            my_set=my_set.sort()

        if comand=="2":
            rec_show(my_set,list())
        if comand == "3":
            print(my_set)


    print('PyCharm')
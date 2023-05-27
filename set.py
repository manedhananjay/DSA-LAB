class SetOperations:
    def create(self,p):
        global set1
        set1=set()
        for i in range(p):
            n1=int(input("\n Enter elements to the set :"))
            set1.add(n1)
    #create(2)

    def insert(self,ele):
        set1.add(ele)
        for i in set1:
            print(i)
    #insert(12)

    def display(self):
        for i in set1:
            print("Elements in set1 are :",i)

    def remove(self,ele):
        if len(set1) == 0:
            print("\n Given set is empty")
        elif ele in set1:
            set1.remove(ele)
            print("\n Removed element is",ele)
        else:
            print("\n Element does not present in the set1")
        for i in set1:
            print(i)
    
    def union1(self,p):
        global set2
        set2=set()
        set3=set()
        for i in range(p):
            n1=int(input("\n Enter elements to the set2 :"))
            set2.add(n1)
        for i in set2:
            for j in set1:
                set3.add(i)
                set3.add(j)
        print("\n Union of set1 and set2 is :")
        for j in set3:
            print(j)

    def intersection_of_set(self):
        set3=set()
        for i in set2:
            for j in set1:
                if i==j:
                    set3.add(i)
        print("\n Intersection of set1 and set2 is :")
        for j in set3:
            print(j)

    def subset(self):
        for i in set2:
            if i in set1:
                print("\n It is subset")
            else:
                print("\n It is not subest")
    #remove(12)

import set
object=set.SetOperations()
choice=0
while choice!=7:
    print("\n ....MENU....")
    print("\n1.Create \n2.Add \n3.Remove \n4.Union \n5.Intersection \n6.Subset  \n7.Display ")
    choice=int(input("\n Enter your choice :"))
    if choice == 1:
        p=int(input("\n Enter size of set :"))
        object.create(p)
    
    elif choice == 2:
        ele=int(input("\n Enter the element do you want to add in the set :"))
        object.insert(ele)
      
    elif choice ==3:
        ele=int(input("\n Enter the element do you want to remove from the set :"))
        object.remove(ele)
    
    elif choice ==4:
        p=int(input("\n Enter size of set :"))
        object.union1(p)

    elif choice ==5:
        object.intersection_of_set()
    
    elif choice==6:
        object.subset()
    
    elif choice==7:
        object.display()
    else:
        print("\n Please enter correct choice :")
class HashDemo:
    #Hash table has been initialized
    def __init__(self):
        self.size=int(input("\n Enter size of table :"))
        self.HashTable=list(0 for i in range(self.size))
        self.HashTable2=list(0 for i in range(self.size))
        self.num_of_elements=0
        self.comparisons=0
    
    #Checking table is full or not here 
    def isTableFull(self):
        if self.num_of_elements==self.size:
            return True
        else:
            return False
    
    # Hash function that returns key
    def HashFunction(self,element):
        return element%self.size
    
    # Inseting element into the hash function
    def Insert_Element(self,element,name):
        if self.isTableFull():
            print("\n Hash Table is full ")
            return False

        OccupiedStatus=False

        position=self.HashFunction(element)

        #Checking if the position is empty or not 
        if self.HashTable[position]==0:
            self.HashTable[position]=element
            self.HashTable2[position]=name
            print("Telephone Number :"+str(element) +" at position "+str(position))
            OccupiedStatus=True
            self.num_of_elements+=1
        else:
            print("\n Collision has occured for Telephone Number "+str(element)+"at index "+str(position))
            position=self.LinearProbing(element,position)
            self.HashTable[position]=element
            self.HashTable2[position]=name
            OccupiedStatus=True
            self.num_of_elements+=1
        return OccupiedStatus
    
    def LinearProbing(self,element,position):
        while(self.HashTable[position]!=0):
            
            if position <self.size:
               position+=1
            else:
                position=0
        return position
    
    # def Doublehashing(self,element,position):
    #     position=self.HashFunction(element)
    #     u=self.size-(self.HashFunction(element))
    #     for j in range(self.size):
    #         position=(position+(u*j))%self.size
    #         if(self.HashTable[position]==0):
    #             self.HashTable[position]=element
    #             self.HashTable2[position]=name

    
    def search(self,element):
        found=False

        position=self.HashFunction(element)
        self.comparisons+=1

        if(self.HashTable[position]==element):
            return position
            print("\n Element found at position :"+position)
            found=True
        
        else:
            temp=position-1
            while position<self.size:
                if self.HashTable[position]!=element:
                    position+=1
                    self.comparisons+=1
                else:
                    return position
            
            position =temp
            while position>=0:
                if self.HashTable[position]!=element:
                    position-=1
                    self.comparisons+=1
                else:
                    return position
                
            if not found:
                print("\n Element not found")
                return False
    
    def display(self):
        print("\n")
        print("\n Position \t Phone Number \tPerson Name \n")
        for i in range(self.size):
            print(" "+str(i)+"\t\t"+str(self.HashTable[i])+"\t\t"+str(self.HashTable2[i]))


#Main function
hash_object=HashDemo()
choice=0
while(choice!=2):
    print("\n 1.Create \n2.Display \n3.Search \n4.Exit")
    choice=int(input("\n Enter your choice :"))

    if choice==1:
        p=int(input("\n Enter phone number to insert :"))
        n=input("\n Enter Person Name :")
        hash_object.Insert_Element(p,n)
    
    if choice ==2:
        hash_object.display()
    
    if choice==3:
        search=int(input("\n Enter Element Do you want to search :"))
        hash_object.search(search)



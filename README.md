# linked_list
class node():
    def __init__(self,value):
        self.data=value
        self.next=None

class Linked_list():
    def __init__(self):
        self.head=None
    
    def append(self,value):
        if self.head is None:
            self.head=node(value)
        else:
            current_node=self.head
            while current_node.next is not None:
                current_node=current_node.next
            current_node.next=node(value)
            
    def prntList(self):
        current_node=self.head
        while current_node is not None:
            print(current_node.data)
            current_node=current_node.next
            
    def reverse(self):
        if self.head is None:
            print("Empty linked_list")
            return 
        else:
            current_node=self.head
            prev_node=None
            while current_node is not None:
                next_node=current_node.next
                current_node.next=prev_node
                prev_node=current_node
                current_node=next_node
            self.head=prev_node
    
                
l1=Linked_list()
T=1
while(T):
    if (T):
        value=int(input("enter value: "))
        l1.append(value)
    T=int(input("Enter True or False: "))
l1.prntList()
l1.reverse()
print("After reversing : ")
l1.prntList()
    
    
    

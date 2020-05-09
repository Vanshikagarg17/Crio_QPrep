class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

def createList(numbers):
	if(len(numbers) == 0):
		return None

	head = ListNode(numbers[0])
	node = head
	for i in range(1, len(numbers)):
		node.next = ListNode(numbers[i])
		node = node.next

	return head

def extractList(head):
	arr = []

	while(head):
		arr.append(head.val)
		head = head.next

	return arr

def generateLinkedListWithCycle(numbers, pos):
	List = createList(numbers)
	if pos == -1:
		return List

	head = List
	tail = List
	while pos > 0:
		pos -= 1
		head = head.next
	while(tail.next):
		tail = tail.next
	tail.next = head
	return List

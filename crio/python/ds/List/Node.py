class Node:
	def __init__(self, _val, _next, _random):
		self.val = _val
		self.next = _next
		self.random = _random

def MakeList(numbers, random):
	if(len(numbers) == 0):
		return None

	head = None
	trav = None
	Map = {}
	for i in range(len(numbers)):
		trav = Node(numbers[i], None, None)
		Map[i] = trav
		if i > 0:
			prev = Map[i - 1]
			prev.next = trav
		else:
			head = trav

	trav = head
	for i in random:
		if i != 'null':
			trav.random = Map[i - 1]
		trav = trav.next

	return head

def Print(head):
	trav = head
	while(trav):
		if trav.random:
			print(trav.val, " ", trav.random.val)
		else:
			print(trav.val, " null")
		trav = trav.next

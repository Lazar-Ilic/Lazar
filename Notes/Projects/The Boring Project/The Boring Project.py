# OKOKOK we will move some very simple boring examples from books which appear in my library such as Python 3 Object Oriented Programming and level up all the way through all of the basic elementary abstract algebra needed for this and furthermore maybe examine compilers and precise details about what occurs at compile time and run time in the C++ programming language especially.

# Recall of course that one can skim like an AP Computer Science text book, study guide, practice tests, and solutions to brush up review on the most basic basics of basics.

import math
class Point:
	def move(self, x, y):
		self.x = x
		self.y = y
	def reset(self):
		self.move(0, 0)
	def calculate_distance(self, other_point):
		return math.sqrt(
			(self.x - other_point.x)**2 +
			(self.y - other_point.y)**2)
# How to use it:
point1 = Point()
point2 = Point()
point1.reset()
point2.move(5,0)
print(point2.calculate_distance(point1))
assert (point2.calculate_distance(point1) ==
	point1.calculate_distance(point2))
point1.move(3,4)
print(point1.calculate_distance(point2))
print(point1.calculate_distance(point1))

# 5.0
# 4.472135955
# 0.0

# The example code at the end shows how to call a method with arguments; simply include the arguments inside the parentheses, and use the same dot notation to access the method. I just picked some random positions to test the methods. The test code calls each method and prints the results on the console. The assert function is a simple test tool; the program will bail if the statement after assert is False (or zero, empty, or None). In this case, we use it to ensure that the distance is the same regardless of which point called the other point's calculate_distance method.

class Point:
	def __init__(self, x, y):
		self.move(x, y)
	def move(self, x, y):
		self.x = x
		self.y = y
	def reset(self):
		self.move(0, 0)
# Constructing A Point
point = Point(3, 5)
print(point.x, point.y)

# Now, our point can never go without a y coordinate! If we try to construct a point without including the proper initialisation parameters, it will fail with a not enough arguments error similar to the one we received earlier when we forgot the self argument.

# As usual.

class Point:
	def __init__(self, x=0, y=0):
		self.move(x, y)

# The constructor function is called __new__ as opposed to __init__, and accepts exactly one argument, the class that is being constructed (it is called before the object is constructed, so there is no self argument). It also has to return the newly created object. This has interesting possibilities when it comes to the complicated art of meta-programming, but is not very useful in day-to-day programming. In practice, you will rarely, if ever, need to use __new__, and __init__ will be sufficient.

# Now that we know how to create classes and instantiate objects, it is time to think about organizing them. For small programs, we can just put all our classes into one file and put some code at the end of the file to start them interacting. However, as our projects grow, it can become difficult to find one class that needs to be edited among the many classes we've defined. This is where modules come in. Modules are simply Python files, nothing more. The single file in our small program is a module. Two Python files are two modules. If we have two files in the same folder, we can load a class from one module for use in the other module.

import database
db = database.Database()

# Do queries on db

# OKOKOK

from database import Database
db = Database()
# Do queries on db

# If, for some reason, products already has a class called Database, and we don't want the two names to be confused, we can rename the class when used inside the products module:

from database import Database as DB
db = DB()
# Do queries on db.

# Organising the modules.

# As a project grows into a collection of more and more modules, we may find that we want to add another level of abstraction, some kind of nested hierarchy on our modules' levels. But we can't put modules inside modules; one file can only hold one file, after all, and modules are nothing more than Python files. Files, however, can go in folders and so can modules. A package is a collection of modules in a folder. The name of the package is the name of the folder. All we need to do to tell Python that a folder is a package and place a (normally empty) file in the folder named __init__.py. If we forget this file, we won't be able to import modules from that folder.

# OKOKOK maybe stop copying and pasting copy righted texts to avoid getting like hit with an actual law suit here over this content. Maybe I para phrase a little bit.

parent_directory/
	main.py
	ecommerce/
		__init__.py
		database.py
		products.py
		payments/
			__init__.py
			paypal.py
			authorizenet.py
	
# Absolute Imports

import ecommerce.products
product = ecommerce.products.Product()

# or

from ecommerce.products import Product
product = Product()

# or

from ecommerce import products
product = products.Product()

# Relative Imports

from .database import Database

from ..database import Database

from ..contact.email import send_mail

class Database:
	# The database implementation.
	pass
database = Database()

from ecommerce.database import database

# Suboptimal as the database object is created immediately upon the module being first imported.

class Database:
	# The database implementation.
	pass
database = None
def initialize_database():
	global database
	database = Database()

# We want for our code function to be executed if and only if we know we are executing as a script, not when being imported in from a different script.

class UsefulClass:
	'''This class might be useful to other modules.'''
	pass
def main():
	'''creates a useful class and does something with it for our module.'''
	useful = UsefulClass()
	print(useful)
if __name__== "__main__":
	main()

# OK

def format_string(string, formatter=None):
	'''Format a string using the formatter object, which is expected to have a format() method that accepts a string.'''
	class DefaultFormatter:
		'''Format a string in title case.'''
		def format(self, string):
			return str(string).title()
	if not formatter:
		formatter = DefaultFormatter()
	return formatter.format(string)
hello_string = "hello world, how are you today?"
print(" input: " + hello_string)
print("output: " + format_string(hello_string))

# input: hello world, how are you today?
# output: Hello World, How Are You Today?

class SecretString:
	'''A not-at-all secure way to store a secret string.'''
	def __init__(self, plain_string, pass_phrase):
		self.__plain_string = plain_string
		self.__pass_phrase = pass_phrase
	def decrypt(self, pass_phrase):
		'''Only show the string if the pass_phrase is correct.'''
		if pass_phrase == self.__pass_phrase:
			return self.__plain_string
		else:
			return ''

parent_directory/
	notebook.py
	menu.py
	command_option.py

# OK

import datetime

# Store the next available id for all new notes.
last_id = 0

class Note:
	'''Represent a note in the notebook. Match against a string in searches and store tags for each note.'''
	def __init__(self, memo, tags=''):
		'''initialise a note with memo and optional space-separated tags. Automatically set the note's creation date and a unique id.'''
		self.memo = memo
		self.tags = tags
		self.creation_date = datetime.date.today()
		global last_id
		last_id += 1
		self.id = last_id
	def match(self, filter):
		'''Determine if this note matches the filter text. Return True if it matches, False otherwise. Search is case sensitive and matches both text and tags.'''
		return filter in self.memo or filter in self.tags

>>> from notebook import Note
>>> n1 = Note("hello first")
>>> n2 = Note("hello again")
>>> n1.id
1
>>> n2.id
2
>>> n1.match('hello')
True
>>> n2.match('second')
False
>>> 

# OK

class Notebook:
	'''Represent a collection of notes that can be tagged, modified, and searched.'''
	def __init__(self):
		'''Initialise a notebook with an empty list.'''
		self.notes = []
	def new_note(self, memo, tags=''):
		'''Create a new note and add it to the list.'''
		self.notes.append(Note(memo, tags))
	def modify_memo(self, note_id, memo):
		'''Find the note with the given id and change its memo to the given value.'''
		for note in self.notes:
			if note.id == note_id:
				note.memo = memo
				break
	def modify_tags(self, note_id, tags):
		'''Find the note with the given id and change its tags to the given value.'''
		for note in self.notes:
			if note.id == note_id:
				note.tags = tags
				break
def search(self, filter):
	'''Find all notes that match the given filter string.'''
	return [note for note in self.notes if
		note.match(filter)]

>>> from notebook import Note, Notebook
>>> n = Notebook()
>>> n.new_note("hello world")
>>> n.new_note("hello again")
>>> n.notes
[<notebook.Note object at 0xb730a78c>, <notebook.Note object at 0xb73103ac>]
>>> n.notes[0].id
1
>>> n.notes[1].id
2
>>> n.notes[0].memo
'hello world'
>>> n.search("hello")
[<notebook.Note object at 0xb730a78c>, <notebook.Note object at 0xb73103ac>]
>>> n.search("world")
[<notebook.Note object at 0xb730a78c>]
>>> n.modify_memo(1, "hi world")
>>> n.notes[0].memo
'hi world'
>>> 

# OK

def _find_note(self, note_id):
	'''Locate the note with the given id.'''
	for note in self.notes:
		if note.id == note_id:
			return note
	return None
def modify_memo(self, note_id, memo):
	'''Find the note with the given id and change its memo to the given value.'''
	self._find_note(note_id).memo = memo

# OK

# Ooh yay menu interface to present a menu and allow the user to input choices that sounds cool, fun, interesting, and kind of useless to trading applications but OK I will learn this and not forget it.

import sys
from notebook import Notebook, Note

class Menu:
	'''Display a menu and respond to choices when run.'''
	def __init__(self):
		self.notebook = Notebook()
		self.choices = {
			"1": self.show_notes,
			"2": self.search_notes,
			"3": self.add_note,
			"4": self.modify_note,
			"5": self.quit
			}
	def display_menu(self):
		print("""
Notebook Menu
1. Show all Notes
2. Search Notes
3. Add Note
4. Modify Note
5. Quit
""")
	def run(self):
		'''Display the menu and respond to choices.'''
		while True:
			self.display_menu()
			choice = input("Enter an option: ")
			action = self.choices.get(choice)
			if action:
				action()
			else:
				print("{0} is not a valid choice".format(choice))
	def show_notes(self, notes=None):
		if not notes:
			notes = self.notebook.notes
		for note in notes:
			print("{0}: {1}\n{2}".format(
				note.id, note.tags, note.memo))
	def search_notes(self):
		filter = input("Search for: ")
		notes = self.notebook.search(filter)
		self.show_notes(notes)
	def add_note(self):
		memo = input("Enter a memo: ")
		self.notebook.new_note(memo)
		print("Your note has been added.")
	def modify_note(self):
		id = input("Enter a note id: ")
		memo = input("Enter a memo: ")
		tags = input("Enter tags: ")
		if memo:
			self.notebook.modify_memo(id, memo)
		if tags:
			self.notebook.modify_tags(id, tags)
	def quit(self):
		print("Thank you for using your notebook today.")
		sys.exit(0)
	if __name__ == "__main__":
		Menu().run()

# Should never trust our users to enter correct data. OK we need to check that right and patch the implicit security vulnerability right there too of course if they like feed in some malicious code which leads to an execution somehow or something maligned occurs. Even if we enter a correct ID, it will crash because the note IDs are integers... but our menu is passing a string.

def _find_note(self, note_id):
	'''Locate the note with the given id.'''
	for note in self.notes:
		if str(note.id) == str(note_id):
			return note
	return None

def modify_memo(self, note_id, memo):
	'''Find the note with the given id and change its memo to the given value.'''
	note = self._find_note(note_id)
	if note:
		note.memo = memo
		return True
	return False

# OKOKOK the Exercises instructs me to go actually do something so I might need to base bare minimum actually go and design a bigger project with like folders and package and module importing syntax. Transporting and importing functions and modules.

# Summary

# In this chapter, we learned how simple it is to create classes and assign properties and methods in Python. We also covered access control and different levels of scope (packages, modules, classes, and functions). In particular, we covered:

# Class Syntax
# Attributes And Methods
# Initialisers And Constructors
# Modules And Packages
# Relative And Absolute Imports
# Access Control And Its Limitations

# In the next chapter, we'll learn how to share implementation using inheritance.

# When Objects Are Alike

# In the programming world, duplicate code is considered evil. We should not have multiple copies of the same, or similar code in different places.

# If we don't explicitly inherit from a different class, our classes will automatically inherit from object. However, we can openly state that our class derives from object using the following syntax:

class MySubClass(object):
	pass

# How do we apply inheritance in practice? The simplest and most obvious use of inheritance is to add functionality to an existing class. Let's start with a simple contact manager that tracks the name and e-mail address of several people. The contact class is responsible for maintaining a list of all contacts in a class variable, and for initializing the name and address, in this simple class:

class Contact:
	all_contacts = []

	def __init__(self, name, email):
		self.name = name
		self.email = email
		Contact.all_contacts.append(self)

# This is a very simple class that allows us to track a couple pieces of data about our contacts. But what if some of our contacts are also suppliers that we need to order supplies from? We could add an order method to the Contact class, but that would allow people to accidentally order things from contacts who are customers or family friends. Instead, let's create a new Supplier class that acts like a Contact, but has an additional order method:

class Supplier(Contact):
	def order(self, order):
		print("If this were a real system we would send "
			"{} order to {}".format(order, self.name))

# OK

>>> c = Contact("Some Body", "somebody@example.net")
>>> s = Supplier("Sup Plier", "supplier@example.net")
>>> print(c.name, c.email, s.name, s.email)
Some Body somebody@example.net Sup Plier supplier@example.net
>>> c.all_contacts
[<__main__.Contact object at 0xb7375ecc>,
 <__main__.Supplier object at 0xb7375f8c>]
>>> c.order("Ineed pliers")
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
AttributeError: 'Contact' object has no attribute 'order'
>>> s.order("I need pliers")
If this were a real system we would send I need pliers order to
Supplier
>>> 

# Extending Built Ins

class ContactList(list):
	def search(self, name):
		'''Return all contacts that contain the search value in their name.'''
		matching_contacts = []
		for contact in self:
			if name in contact.name:
				matching_contacts.append(contact)
		return matching_contacts
class Contact:
	all_contacts = ContactList()

	def __init__(self, name, email):
		self.name = name
		self.email = email
		self.all_contacts.append(self)

# OK

# New ContactList class that extends the build in list. Then instantiate this subclass as our all_contacts list.

>>> c1 = Contact("John A", "johna@example.net")
>>> c2 = Contact("John B", "johnb@example.net")
>>> c3 = Contact("Jenna C", "jennac@example.net")
>>> [c.name for c in Contact.all_contacts.search('John')]
['John A', 'John B']
>>> 

>>> [] == list()
True

# We can extend the dict class, which is the long way of creating a dictionary file.

class LongNameDict(dict):
	def longest_key(self):
		longest = None
		for key in self:
			if not longest or len(key) > len(longest):
				longest = key
		return longest

# Easy to test in the interactive interpreter:

>>> longkeys = LongNameDict()
>>> longkeys['hello'] = 1
>>> longkeys['longest yet'] = 5
>>> longkeys['hello2'] = 'world'
>>> longkeys.longest_key()
'longest yet'

# Over Riding And Super

class Friend(Contact):
	def __init__(self, name, email, phone):
		self.name = name
		self.email = email
		self.phone = phone

# Need a way to call code in the parent class. Ah hah. OK so that is the super function, it returns the object as an instance of the parent class.

class Friend(Contact):
	def __init__(self, name, email, phone):
		super().__init__(name, email)
		self.phone = phone

# Super classy super class we are going to have a lot of room for the mix ins mixins. A mixin is generally a superclass that is not meant to exist on its own, but is meant to be inherited by some other class to provide extra functionality.

class MailSender:
	def send_mail(self, message):
		print("Sending mail to " + self.email)
		# Add e-mail logic here.

# Electronic mail letter logic see the smtplib module in the Python standard library.

class EmailableContact(Contact, MailSender):
	pass

# OK

>>> e = EmailableContact("John Smith", "jsmith@example.net")
>>> Contact.all_contacts
[<__main__.EmailableContact object at 0xb7205fac>]
>>> e.send_mail("Hello, test e-mail here")
Sending mail to jsmith@example.net

# Inheritance is a viable solution.

class AddressHolder:
	def __init__(self, street, city, state, code):
		self.street = street
		self.city = city
		self.state = state
		self.code = code

# The Diamond Problem

class Friend(Contact, AddressHolder):
	def __init__(self, name, email, phone,
			street, city, state, code):
		Contact.__init__(self, name, email)
		AddressHolder.__init__(
			self, street, city, state, code)
		self.phone = phone

# Base Class, Left Subclass, Right Subclass, Subclass

class BaseClass:
	num_base_calls = 0
	def call_me(self):
		print("Calling method on Base Class")
		self.num_base_calls += 1

class LeftSubclass(BaseClass):
	num_left_calls = 0
	def call_me(self):
		BaseClass.call_me(self)
		print("Calling method on Left Subclass")
		self.num_left_calls += 1

class RightSubclass(BaseClass):
	num_right_calls = 0
	def call_me(self):
		BaseClass.call_me(self)
		print("Calling method on Right Subclass")
		self.num_right_calls += 1

class Subclass(LeftSubclass, RightSubclass):
	num_sub_calls = 0
	def call_me(self):
		LeftSubclass.call_me(self)
		RightSubclass.call_me(self)
		print("Calling method on Subclass")
		self.num_sub_calls += 1

# OK

>>> s = Subclass()
>>> s.call_me()
Calling method on Base Class
Calling method on Left Subclass
Calling method on Base Class
Calling method on Right Subclass
Calling method on Subclass
>>> print(s.num_sub_calls, s.num_left_calls, s.num_right_calls,
s.num_base_calls)
1 1 1 2
>>> 

# OK

# Multiple inheritance we only want to call the "next" method in the class hierarchy, not the "parent" method.

class BaseClass:
	num_base_calls = 0
	def call_me(self):
		print("Calling method on Base Class")
		self.num_base_calls += 1

class LeftSubclass(BaseClass):
	num_left_calls = 0
	def call_me(self):
		super().call_me()
		print("Calling method on Left Subclass")
		self.num_left_calls += 1

class RightSubclass(BaseClass):
	num_right_calls = 0
	def call_me(self):
		super().call_me()
		print("Calling method on Right Subclass")
		self.num_right_calls += 1

class Subclass(LeftSubclass, RightSubclass):
	num_sub_calls = 0
	def call_me(self):
		super().call_me()
		print("Calling method on Subclass")
		self.num_sub_calls += 1

# OK

>>> s = Subclass()
>>> s.call_me()
Calling method on Base Class
Calling method on Right Subclass
Calling method on Left Subclass
Calling method on Subclass
>>> print(s.num_sub_calls, s.num_left_calls, s.num_right_calls, s.num_base_calls)
1 1 1 1

# Different Sets Of Arguments

Contact.__init__(self, name, email)
AddressHolder.__init__(self, street, city, state, code)

# Multiple Inheritance Code

class Contact:
	all_contacts = []
	def __init__(self, name='', email='', **kwargs):
		super().__init__(**kwargs)
		self.name = name
		self.email = email
		self.all_contacts.append(self)

class AddressHolder:
	def __init__(self, street='', city='', state='', code='',**kwargs):
		super().__init__(**kwargs)
		self.street = street
		self.city = city
		self.state = state
		self.code = code

class Friend(Contact, AddressHolder):
	def __init__(self, phone='', **kwargs):
		super().__init__(**kwargs)
		self.phone = phone

# Polymorphism

audio_file.play()

# Inheritance with polymorphism to simplify the design.

class AudioFile:
	def __init__(self, filename):
		if not filename.endswith(self.ext):
			raise Exception("Invalid file format")
		self.filename = filename

class MP3File(AudioFile):
	ext = "mp3"
	def play(self):
		print("playing {} as mp3".format(self.filename))

class WavFile(AudioFile):
	ext = "wav"
	def play(self):
		print("playing {} as wav".format(self.filename))

class OggFile(AudioFile):
	ext = "ogg"
	def play(self):
		print("playing {} as ogg".format(self.filename))

# OK

>>> ogg = OggFile("myfile.ogg")
>>> ogg.play()
playing myfile.ogg as ogg
>>> mp3 = MP3File("myfile.mp3")
>>> mp3.play()
playing myfile.mp3 as mp3
>>> not_an_mp3 = MP3File("myfile.ogg")
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
 File "polymorphic_audio.py", line 4, in __init__
 raise Exception("Invalid file format")
Exception: Invalid file format

# Laugh Out Loud at the topicality re Inanity.txt

class FlacFile:
	def __init__(self, filename):
		if not filename.endswith(".flac"):
			raise Exception("Invalid file format")
		self.filename = filename
	def play(self):
		print("playing {} as flac".format(self.filename))

# Our media player can play this object just as easily as one that extends AudioFile.

# Case Study

# The trickiest aspects of these classes is going to be ensuring superclass methods get called in the inheritance hierarchy.

class Property:
	def __init__(self, square_feet='', beds='',
			baths='', **kwargs):
		super().__init__(**kwargs)
		self.square_feet = square_feet
		self.num_bedrooms = beds
		self.num_baths = baths
	def display(self):
		print("PROPERTY DETAILS")
		print("================")
		print("square footage: {}".format(self.square_feet))
		print("bedrooms: {}".format(self.num_bedrooms))
		print("bathrooms: {}".format(self.num_baths))
		print()
	def prompt_init():
		return dict(square_feet=input("Enter the square feet: "),
			beds=input("Enter number of bedrooms: "),
			baths=input("Enter number of baths: "))
	prompt_init = staticmethod(prompt_init)

# Multiple inheritance is messy business, even at the design stage.

class Property:
	def __init__(self, square_feet='', beds='',
			baths='', **kwargs):
		super().__init__(**kwargs)
		self.square_feet = square_feet
		self.num_bedrooms = beds
		self.num_baths = baths
	def display(self):
		print("PROPERTY DETAILS")
		print("================")
		print("square footage: {}".format(self.square_feet))
		print("bedrooms: {}".format(self.num_bedrooms))
		print("bathrooms: {}".format(self.num_baths))
		print()
	def prompt_init():
		return dict(square_feet=input("Enter the square feet: "),
			beds=input("Enter number of bedrooms: "),
			baths=input("Enter number of baths: "))
	prompt_init = staticmethod(prompt_init)

# The Apartment class extends Property, and is similar in structure:

class Apartment(Property):
	valid_laundries = ("coin", "ensuite", "none")
	valid_balconies = ("yes", "no", "solarium")
	def __init__(self, balcony='', laundry='', **kwargs):
		super().__init__(**kwargs)
		self.balcony = balcony
		self.laundry = laundry
	def display(self):
		super().display()
		print("APARTMENT DETAILS")
		print("laundry: %s" % self.laundry)
		print("has balcony: %s" % self.balcony)
		parent_init = Property.prompt_init()
		laundry = ''
		while laundry.lower() not in \
				Apartment.valid_laundries:
			laundry = input("What laundry facilities does "
					"the property have? ({})".format(
					", ".join(Apartment.valid_laundries))
		balcony = ''
		while balcony.lower() not in \
				Apartment.valid_balconies:
			balcony = input(
				"Does the property have a balcony? "
				"({})".format(
				", ".join(Apartment.valid_balconies))
		parent_init.update({
			"laundry": laundry,
			"balcony": balcony
		})
		return parent_init
	prompt_init = staticmethod(prompt_init)

# OK

def get_valid_input(input_string, valid_options):
	input_string += " ({}) ".format(", ".join(valid_options))
	response = input(input_string)
	while response.lower() not in valid_options:
		response = input(input_string)
	return response

# OK

>>> get_valid_input("what laundry?", ("coin", "ensuite", "none"))
what laundry? (coin, ensuite, none) hi
what laundry? (coin, ensuite, none) COIN
'COIN'

# OK

def prompt_init():
	parent_init = Property.prompt_init()
	laundry = get_valid_input(
			"What laundry facilities does "
			"the property have? ",
			Apartment.valid_laundries)
	balcony = get_valid_input(
		"Does the property have a balcony? ",
		Apartment.valid_balconies)
	parent_init.update({
		"laundry": laundry,
		"balcony": balcony
	})
	return parent_init
prompt_init = staticmethod(prompt_init)

# OK House class.

class House(Property):
	valid_garage = ("attached", "detached", "none")
	valid_fenced = ("yes", "no")
	def __init__(self, num_stories='',
			garage='', fenced='', **kwargs):
		super().__init__(**kwargs)
		self.garage = garage
		self.fenced = fenced
		self.num_stories = num_stories
	def display(self):
		super().display()
		print("HOUSE DETAILS")
		print("# of stories: {}".format(self.num_stories))
		print("garage: {}".format(self.garage))
		print("fenced yard: {}".format(self.fenced))
	def prompt_init():
		parent_init = Property.prompt_init()
		fenced = get_valid_input("Is the yard fenced? ",
		House.valid_fenced)
		garage = get_valid_input("Is there a garage? ",
		House.valid_garage)
		num_stories = input("How many stories? ")
		parent_init.update({
			"fenced": fenced,
			"garage": garage,
			"num_stories": num_stories
		})
		return parent_init
	prompt_init = staticmethod(prompt_init)

# Purchase And Rental Classes

class Purchase:
	def __init__(self, price='', taxes='', **kwargs):
		super().__init__(**kwargs)
		self.price = price
		self.taxes = taxes
	def display(self):
		super().display()
		print("PURCHASE DETAILS")
		print("selling price: {}".format(self.price))
		print("estimated taxes: {}".format(self.taxes))
	def prompt_init():
		return dict(
			price=input("What is the selling price? "),
			taxes=input("What are the estimated taxes? "))
	prompt_init = staticmethod(prompt_init)

class Rental:
	def __init__(self, furnished='', utilities='',
			rent='', **kwargs):
		super().__init__(**kwargs)
		self.furnished = furnished
		self.rent = rent
		self.utilities = utilities
	def display(self):
		super().display()
		print("RENTAL DETAILS")
		print("rent: {}".format(self.rent))
		print("estimated utilities: {}".format(
			self.utilities))
		print("furnished: {}".format(self.furnished))
	def prompt_init():
		return dict(
			rent=input("What is the monthly rent? "),
			utilities=input(
				"What are the estimated utilities? "),
			furnished = get_valid_input(
				"Is the property furnished? ",
					("yes", "no")))
	prompt_init = staticmethod(prompt_init)

# Combine the functionality of these 4 classes in separate subclasses.

class HouseRental(Rental, House):
	def prompt_init():
		init = House.prompt_init()
		init.update(Rental.prompt_init())
		return init
	prompt_init = staticmethod(prompt_init)

# OK

>>> init = HouseRental.prompt_init()
Enter the square feet: 1
Enter number of bedrooms: 2
Enter number of baths: 3
Is the yard fenced? (yes, no) no
Is there a garage? (attached, detached, none) none
How many stories? 4
What is the monthly rent? 5
What are the estimated utilities? 6
Is the property furnished? (yes, no) no
>>> house = HouseRental(**init)
>>> house.display()

PROPERTY DETAILS
================
square footage: 1
bedrooms: 2
bathrooms: 3
HOUSE DETAILS
# of stories: 4
garage: none
fenced yard: no
RENTAL DETAILS
rent: 5
estimated utilities: 6
furnished: no

# The order of the inherited classes in the preceding example is important.

class ApartmentRental(Rental, Apartment):
	def prompt_init():
		init = Apartment.prompt_init()
		init.update(Rental.prompt_init())
		return init
	prompt_init = staticmethod(prompt_init)

class ApartmentPurchase(Purchase, Apartment):
	def prompt_init():
		init = Apartment.prompt_init()
		init.update(Purchase.prompt_init())
		return init
	prompt_init = staticmethod(prompt_init)

class HousePurchase(Purchase, House):
	def prompt_init():
		init = House.prompt_init()
		init.update(Purchase.prompt_init())
		return init
	prompt_init = staticmethod(prompt_init)

# Create the Agent, which is responsible for creating new listings and displaying existing ones.

class Agent:
	def __init__(self):
		self.property_list = []
	def display_properties(self):
		for property in self.property_list:
			property.display()

# OK

type_map = {
	("house", "rental"): HouseRental,
	("house", "purchase"): HousePurchase,
	("apartment", "rental"): ApartmentRental,
	("apartment", "purchase"): ApartmentPurchase
}

# OK

def add_property(self):
	property_type = get_valid_input(
			"What type of property? ",
			("house", "apartment")).lower()
	payment_type = get_valid_input(
			"What payment type? ",
			("purchase", "rental")).lower()
	PropertyClass = self.type_map[
		(property_type, payment_type)]
	init_args = PropertyClass.prompt_init()
	self.property_list.append(PropertyClass(**init_args))

# OK

>>> agent = Agent()
>>> agent.add_property()
What type of property? (house, apartment) house
What payment type? (purchase, rental) rental
Enter the square feet: 900
Enter number of bedrooms: 2
Enter number of baths: one and a half
Is the yard fenced? (yes, no) yes
Is there a garage? (attached, detached, none) detached
How many stories? 1
What is the monthly rent? 1200
What are the estimated utilities? included
Is the property furnished? (yes, no) no
>>> agent.add_property()
What type of property? (house, apartment) apartment
What payment type? (purchase, rental) purchase
Enter the square feet: 800
Enter number of bedrooms: 3
Enter number of baths: 2
What laundry facilities does the property have? (coin, ensuite,
one) ensuite
Does the property have a balcony? (yes, no, solarium) yes
What is the selling price? $200,000
What are the estimated taxes? 1500
>>> agent.display_properties()
PROPERTY DETAILS
================
square footage: 900
bedrooms: 2
bathrooms: one and a half
HOUSE DETAILS
# Of stories: 1
garage: detached
fenced yard: yes
RENTAL DETAILS
rent: 1200
estimated utilities: included
furnished: no
PROPERTY DETAILS
================
square footage: 800
bedrooms: 3
bathrooms: 2
APARTMENT DETAILS
laundry: ensuite
has balcony: yes
PURCHASE DETAILS
selling price: $200,000
estimated taxes: 1500
>>> 

# Exercises

# Hilarious I thought the entire point of all of this classification tasks, clustering analysis, machine learning, yadda was that these words and structures actually do map on to something real. And so there are in fact underlying real inheritance hierarchies. I dunno non obvious inheritance relationships.

# Summary

# We've gone from simple inheritance, one of the most useful tools in the object-oriented programmer's toolbox, all the way through to multiple inheritance, one of the most complicated. We learned how to:

# Add functionality to existing classes and built-ins using inheritance
# Share similar code between classes by abstracting it into a parent class
# Combine multiple threads of functionality using multiple inheritance Call parent methods using super
# Format argument lists in multiple inheritance so super doesn't choke
# In the next chapter, we'll cover the subtle art of handling exceptional circumstances.

# Expecting The Unexpected

# Exceptions

# How to cause an exception to occur
# How to recover when an exception has occurred
# How to handle different exceptions with different code
# Cleaning up when an exception has occurred
# Creating new exceptions
# Using the exception syntax for flow control

# Raising Exceptions

# How do we cause an exception to occur? The easiest way is to do something stupid! Chances are you've done this already and seen the exception output.

>>> print "hello world"
 File "<stdin>", line 1
 print "hello world"
 ^
SyntaxError: invalid syntax

# SyntaxError exception yeah yeah yeah.

>>> x = 5 / 0
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
ZeroDivisionError: int division or modulo by zero
>>> lst = [1,2,3]
>>> print(lst[3])
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
IndexError: list index out of range
>>> lst + 2
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
 TypeError: can only concatenate list (not "int") to list
>>> lst.add
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
AttributeError: 'list' object has no attribute 'add'
>>> d = {'a': 'hello'}
>>> d['b']
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
KeyError: 'b'
>>> print(this_is_not_a_var)
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
NameError: name 'this_is_not_a_var' is not defined
>>> 

# Raising An Exception

class EvenOnly(list):
	def append(self, integer):
		if not isinstance(integer, int):
			raise TypeError("Only integers can be added")
		if integer % 2:
			raise ValueError("Only even numbers can be added")
		super().append(integer)

# Extends the list built in.

>>> e = EvenOnly()
>>> e.append("a string")
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
 File "even_integers.py", line 7, in add
 raise TypeError("Only integers can be added")
TypeError: Only integers can be added
>>> e.append(3)
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
 File "even_integers.py", line 9, in add
 raise ValueError("Only even numbers can be added")
ValueError: Only even numbers can be added
>>> e.append(2)

# What Happens When An Exception Occurs?

def no_return():
	print("I am about to raise an exception")
	raise Exception("This is always raised")
	print("This line will never execute")
	return "I won't be returned"

# OK

>>> no_return()
I am about to raise an exception
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
 File "exception_quits.py", line 3, in no_return
 raise Exception("This is always raised")
Exception: This is always raised

# OK

def call_exceptor():
	print("call_exceptor starts here...")
	no_return()
	print("an exception was raised...")
	print("...so these lines don't run")

# OK

>>> call_exceptor()
call_exceptor starts here...
I am about to raise an exception
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
 File "method_calls_excepting.py", line 9, in call_exceptor
 no_return()
 File "method_calls_excepting.py", line 3, in no_return
 raise Exception("This is always raised")
Exception: This is always raised

# Handling Exceptions

try:
	no_return()
except:
	print("I caught an exception")
print("executed after the exception")

# OK

I am about to raise an exception
I caught an exception
executed after the exception

# OK

def funny_division(anumber):
	try:
		return 100 / anumber
	except ZeroDivisionError:
		return "Silly wabbit, you can't divide by zero!"
print(funny_division(0))
print(funny_division(50.0))
print(funny_division("hello"))

# The function is tested with print statements that show it behaving as expected:

Silly wabbit, you can't divide by zero!
2.0
Traceback (most recent call last):
 File "catch_specific_exception.py", line 9, in <module>
 print(funny_division("hello"))
 File "catch_specific_exception.py", line 3, in funny_division
 return 100 / anumber
TypeError: unsupported operand type(s) for /: 'int' and 'str'

# OK

def funny_division2(anumber):
	try:
		if anumber == 13:
			raise ValueError("13 is an unlucky number")
		return 100 / anumber
	except (ZeroDivisionError, TypeError):
		return "Enter a number other than zero"
for val in (0, "hello", 50.0, 13):
	print("Testing {}:".format(val), end=" ")
	print(funny_division2(val))

# OK

Testing 0: Enter a number other than zero
Testing hello: Enter a number other than zero
Testing 50.0: 2.0
Testing 13: Traceback (most recent call last):
 File "catch_multiple_exceptions.py", line 11, in <module>
 print(funny_division2(val))
 File "catch_multiple_exceptions.py", line 4, in funny_division2
 raise ValueError("13 is an unlucky number")
ValueError: 13 is an unlucky number

# OK

def funny_division3(anumber):
	try:
		if anumber == 13:
			raise ValueError("13 is an unlucky number")
		return 100 / anumber
	except ZeroDivisionError:
		return "Enter a number other than zero"
	except TypeError:
		return "Enter a numerical value"
	except ValueError:
		print("No, No, not 13!")
		raise raise # reise reise gang

# OK

try:
 raise ValueError("This is an argument")
except ValueError as e:
 print("The exception arguments were", e.args)

# OK

import random
some_exceptions = [ValueError, TypeError, IndexError, None]
try:
	choice = random.choice(some_exceptions)
	print("raising {}".format(choice))
	if choice:
		raise choice("An error")
except ValueError:
	print("Caught a ValueError")
except TypeError:
	print("Caught a TypeError")
except Exception as e:
	print("Caught some other error: %s" %
		( e.__class__.__name__))
else:
	print("This code called if there is no exception")
finally:
	print("This cleanup code is always called")

# OK

$ python finally_and_else.py
raising None
This code called if there is no exception
This cleanup code is always called

$ python finally_and_else.py
raising <class 'TypeError'>
Caught a TypeError
This cleanup code is always called

$ python finally_and_else.py
raising <class 'IndexError'>
Caught some other error: IndexError
This cleanup code is always called

$ python finally_and_else.py
raising <class 'ValueError'>
Caught a ValueError
This cleanup code is always called

# Exception Hierarchy

# OK we crack a lack on this tomorrow solid day here working hard learning the Truly useful Good stuff.

# Defining Our Own Exceptions

class InvalidWithdrawal(Exception):
	pass
raise InvalidWithdrawal("You don't have $50 in your account")

# OK

class InvalidWithdrawal(Exception):
	def __init__(self, balance, amount):
		super().__init__("account doesn't have ${}".format(
			amount))
		self.amount = amount
		self.balance = balance
	def overage(self):
		return self.amount - self.balance
raise InvalidWithdrawal(25, 50)

# OK

try:
	raise InvalidWithdrawal(25, 50)
except InvalidWithdrawal as e:
	print("I'm sorry, but your withdrawal is "
		"more than your balance by "
		"${}".format(e.overage()))

# Exceptions Are Not Exceptional

def divide_with_exception(number, divisor):
	try:
		print("{} / {} = {}".format(
			number, divisor, number / divisor * 1.0))
	except ZeroDivisionError:
		print("You can't divide by zero")
def divide_with_if(number, divisor):
	if divisor == 0:
		print("You can't divide by zero")
	else:
		print("{} / {} = {}".format(
			number, divisor, number / divisor * 1.0))

# ZeroDivisionError OK IndexError

class Inventory:
	def lock(self, item_type):
		'''Select the type of item that is going to
		be manipulated. This method will lock the
		item so nobody else can manipulate the
		inventory until it's returned. This prevents
		selling the same item to two different
		customers.'''
		pass
	def unlock(self, item_type):
		'''Release the given type so that other
		customers can access it.'''
		pass
	def purchase(self, item_type):
		'''If the item is not locked, raise an
		exception. If the itemtype does not exist,
		raise an exception. If the item is currently
		out of stock, raise an exception. If the item
		is available, subtract one item and return
		the number of items left.'''
		pass
	
# OK

item_type = 'widget'
inv = Inventory()
inv.lock(item_type)
try:
	num_left = inv.purchase(item_type)
except InvalidItemType:
	print("Sorry, we don't sell {}".format(item_type))
except OutOfStock:
	print("Sorry, that item is out of stock.")
else:
	print("Purchase complete. There are "
			"{} {}s left".format(num_left, item_type))
finally:
	inv.unlock()

# OK

# Case Study

# Use and handling of exceptions at a fairly low level of detail: syntax and definitions.

# Authorization.

import hashlib
class User:
	def __init__(self, username, password):
		'''Create a new user object. The password
		will be encrypted before storing.'''
		self.username = username
		self.password = self._encrypt_pw(password)
		self.is_logged_in = False
	def _encrypt_pw(self, password):
		'''Encrypt the password with the username and return
		the sha digest.'''
		hash_string = (self.username + password)
		hash_string = hash_string.encode("utf8")
		return hashlib.sha256(hash_string).hexdigest()
	def check_password(self, password):
		'''Return True if the password is valid for this
		user, false otherwise.'''
		encrypted = self._encrypt_pw(password)
		return encrypted == self.password

# OK

class AuthException(Exception):
	def __init__(self, username, user=None):
		super().__init__(username, user)
		self.username = username
		self.user = user

class UsernameAlreadyExists(AuthException):
	pass

class PasswordTooShort(AuthException):
	pass

# OK

class Authenticator:
	def __init__(self):
		'''Construct an authenticator to manage
		users logging in and out.'''
		self.users = {}
	def add_user(self, username, password):
		if username in self.users:
			raise UsernameAlreadyExists(username)
		if len(password) < 6:
			raise PasswordTooShort(username)
		self.users[username] = User(username, password)

# Prepare the login method.

class InvalidUsername(AuthException):
	pass
class InvalidPassword(AuthException):
	pass

# Simple login method to our Authenticator class.

def login(self, username, password):
	try:
		user = self.users[username]
	except KeyError:
		raise InvalidUsername(username)
	if not user.check_password(password):
		raise InvalidPassword(username, user)
	user.is_logged_in = True
	return True

# OK

def is_logged_in(self, username):
	if username in self.users:
		return self.users[username].is_logged_in
	return False

# OK default authenticator instance to our module.

authenticator = Authenticator()

# OK

class Authorizor:
	def __init__(self, authenticator):
		self.authenticator = authenticator
		self.permissions = {}

# OK

# New methods to add new permissions and set up which users are associated with each permission.

def add_permission(self, perm_name):
	'''Create a new permission that users
	can be added to'''
	try:
		perm_set = self.permissions[perm_name]
	except KeyError:
		self.permissions[perm_name] = set()
	else:
		raise PermissionError("Permission Exists")

def permit_user(self, perm_name, username):
	'''Grant the given permission to the user'''
	try:
		perm_set = self.permissions[perm_name]
	except KeyError:
		raise PermissionError("Permission does not exist")
	else:
		if username not in self.authenticator.users:
			raise InvalidUsername(username)
		perm_set.add(username)

# OK

class PermissionError(Exception):
	pass

# OK

def check_permission(self, perm_name, username):
	if not self.authenticator.is_logged_in(username):
		raise NotLoggedInError(username)
	try:
		perm_set = self.permissions[perm_name]
	except KeyError:
		raise PermissionError("Permission does not exist")
	else:
		if username not in perm_set:
			raise NotPermittedError(username)
		else:
			return True

# OK 2 new exceptions in here, they both take usernames, so we will define them as subclasses of AuthException:

class NotLoggedInError(AuthException):
	pass
class NotPermittedError(AuthException):
	pass

# Add a "default" authorizor to go with our default authenticator:

authorizor = Authorizor(authenticator)

>>> import auth
>>> auth.authenticator.add_user("joe", "joepassword")
>>> auth.authorizor.add_permission("paint")
>>> auth.authorizor.check_permission("paint", "joe")
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
 File "auth.py", line 109, in check_permission
 raise NotLoggedInError(username)
auth.NotLoggedInError: joe
>>> auth.authenticator.is_logged_in("joe")
False
>>> auth.authenticator.login("joe", "joepassword")
True
>>> auth.authorizor.check_permission("paint", "joe")
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
 File "auth.py", line 116, in check_permission
 raise NotPermittedError(username)
auth.NotPermittedError: joe
>>> auth.authorizor.check_permission("mix", "joe")
Traceback (most recent call last):
 File "auth.py", line 111, in check_permission
 perm_set = self.permissions[perm_name]
KeyError: 'mix'
During handling of the above exception, another exception occurred:
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
 File "auth.py", line 113, in check_permission
 raise PermissionError("Permission does not exist")
auth.PermissionError: Permission does not exist
>>> auth.authorizor.permit_user("mix", "joe")
Traceback (most recent call last):
 File "auth.py", line 99, in permit_user
 perm_set = self.permissions[perm_name]
KeyError: 'mix'
During handling of the above exception, another exception occurred:
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
 File "auth.py", line 101, in permit_user
 raise PermissionError("Permission does not exist")
auth.PermissionError: Permission does not exist
>>> auth.authorizor.permit_user("paint", "joe")
>>> auth.authorizor.check_permission("paint", "joe")
True

# OK

import auth

# Set up a test user and permission.
auth.authenticator.add_user("joe", "joepassword")
auth.authorizor.add_permission("test program")
auth.authorizor.add_permission("change program")
auth.authorizor.permit_user("test program", "joe")

class Editor:
	def __init__(self):
		self.username = None
		self.menu_map = {
			"login": self.login,
			"test": self.test,
			"change": self.change,
			"quit": self.quit
		}

	def login(self):
		logged_in = False
		while not logged_in:
			username = input("username: ")
			password = input("password: ")
			try:
				logged_in = auth.authenticator.login(
						username, password)
			except auth.InvalidUsername:
				print("Sorry, that username does not exist")
			except auth.InvalidPassword:
				print("Sorry, incorrect password")
			else:
				self.username = username
	
	def is_permitted(self, permission):
		try:
			auth.authorizor.check_permission(
				permission, self.username)
		except auth.NotLoggedInError as e:
			print("{} is not logged in".format(e.username))
			return False
		except auth.NotPermittedError as e:
			print("{} cannot {}".format(
				e.username, permission))
			return False
		else:
			return True

	def test(self):
		if self.is_permitted("test program"):
			print("Testing program now...")

	def change(self):
		if self.is_permitted("change program"):
			print("Changing program now...")

	def quit(self):
		raise SystemExit()

	def menu(self):
		try:
			answer = ""
			while True:
				print("""
Please enter a command:
\tlogin\tLogin
\ttest\tTest the program
\tchange\tChange the program
\tquit\tQuit
""")
				answer = input("enter a command: ").lower()
				try:
					func = self.menu_map[answer]
				except KeyError:
					print("{} is not a valid option".format(
						answer))
				else:
					func()
		finally:
			print("Thank you for testing the auth module")

Editor().menu()

# OK

# Exercises

# OKOKOK there are a number of good interesting use cases for handling exceptions.

# Summary

# In this chapter, we went into the gritty details of raising, handling, defining, and manipulating exceptions. Exceptions are a powerful way to communicate unusual circumstances or error conditions without requiring a calling function to explicitly check return values. Specifically, we covered:

# Built-In Exceptions And Raising Exceptions
# Several Ways To Handle Specific Exceptions
# Defining New Exceptions
# Using Exceptions For Unexceptional Circumstances

# In the next chapter, everything we've studied so far will come together as we discuss how object-oriented programming principles and structures should best be applied in Python applications.

# When To Use Object Oriented Programming

# In the previous chapters, we've covered many of the defining features of Object-Oriented Programming. We now know the principles and paradigms of Object-Oriented Design, and we've covered the syntax of Object-Oriented Programming In Python. Yet, things are still hazy when it comes to knowing how and when to apply these principles and syntax. Here, we'll discuss some of the more useful applications of the knowledge we've gained, while in Chapter 7, we'll cover something just as important: when not to use them! In this chapter we'll cover:

# How To Recognise Objects
# Data And Behaviours, Once Again
# Wrapping Data In Behaviour Using Properties
# Restricting Data Using Behaviour
# The Don't Repeat Yourself principle
# Recognising Code That Is The Same

# Treat Objects As Objects

# OK

square = [(1,1), (1,2), (2,2), (2,1)]

# OK

import math

def distance(p1, p2):
	return math.sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)

def perimeter(polygon):
	perimeter = 0
	points = polygon + [polygon[0]]
	for i in range(len(polygon)):
		perimeter += distance(points[i], points[i+1])
	return perimeter

# OK

# This is funny to me in the context of some Discord chats with the old Good friend and pal Presley Graham about R2 and general geometry algorithms which are always a fascinating topic. As well as just some other general musings of mine in that area trying to crack like some open tasks which came my way via Jeff Erickson. As well as of course my own experiences with competitive programming and viewing like massive amounts of the Codeforces and AtCoder arhives as is Truly represented in Library.txt so there you have it some C++ codes as well on the topic of these sorts of things what Point class is used etc.

# Apparently we can now write the object-oriented version in record time:

import math

class Point:
	def __init__(self, x, y):
		self.x = x
		self.y = y
	def distance(self, p2):
		return math.sqrt((self.x-p2.x)**2 + (self.y-p2.y)**2)

class Polygon:
	def __init__(self):
		self.vertices = []
	def add_point(self, point):
		self.vertices.append((point))
	def perimeter(self):
		perimeter = 0
		points = self.vertices + [self.vertices[0]]
		for i in range(len(self.vertices)):
			perimeter += points[i].distance(points[i+1])
		return perimeter

# OKOKOK

>>> square = Polygon()
>>> square.add_point(Point(1,1))
>>> square.add_point(Point(1,2))
>>> square.add_point(Point(2,2))
>>> square.add_point(Point(2,1))
>>> square.perimeter()
4.0

# Fairly succinct and easy to read, you might think, but let's compare it to the function-based code:

>>> square = [(1,1), (1,2), (2,2), (2,1)]
>>> perimeter(square)
4.0

# OK

def __init__(self, points = []):
	self.vertices = []
	for point in points:
		if isinstance(point, tuple):
			point = Point(*point)
		self.vertices.append(point)

# OK encapsulate more data about a polygon in to a class.

# Using Properties To Add Behaviour To Class Data

class Color:
	def __init__(self, rgb_value, name):
		self._rgb_value = rgb_value
		self._name = name
	def set_name(self, name):
		self._name = name

	def get_name(self):
		return self._name

# OK

>>> c = Color("#ff0000", "bright red")
>>> c.get_name()
'bright red'
>>> c.set_name("red")
>>> c.get_name()
'red'

# OK

class Color:
	def __init__(self, rgb_value, name):
		self.rgb_value = rgb_value
		self.name = name
c = Color("#ff0000", "bright red")
print(c.name)
c.name = "red"

# OK

def set_name(self, name):
	if not name:
		raise Exception("Invalid Name")
	self._name = name

# OK

class Color:
	def __init__(self, rgb_value, name):
		self.rgb_value = rgb_value
		self._name = name
	def _set_name(self, name):
		if not name:
			raise Exception("Invalid Name")
		self._name = name
	def _get_name(self):
		return self._name

name = property(_get_name, _set_name)

# OK

>>> c = Color("#0000ff", "bright red")
>>> print(c.name)
bright red
>>> c.name = "red"
>>> print(c.name)
red
>>> c.name = ""
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
 File "setting_name_property.py", line 8, in _set_name
 raise Exception("Invalid Name")
Exception: Invalid Name

# How It Works

class Silly:
	def _get_silly(self):
		print("You are getting silly")
		return self._silly
	def _set_silly(self, value):
		print("You are making silly {}".format(value))
		self._silly = value
	def _del_silly(self):
		print("Whoah, you killed silly!")
		del self._silly
	
	silly = property(_get_silly, _set_silly,
			_del_silly, "This is a silly property")

# OK

>>> s = Silly()
>>> s.silly = "funny"
You are making silly funny
>>> s.silly
You are getting silly
'funny'
>>> del s.silly
Whoah, you killed silly!

# OK

Help on class Silly in module __main__:
class Silly(builtins.object)
 | Data descriptors defined here:
 |
 | __dict__
 | dictionary for instance variables (if defined)
 |
 | __weakref__
 | list of weak references to the object (if defined)
 |
 | silly
 | This is a silly property

# Decorators: Another Way To Create Properties

class Foo:
	@property
	def foo(self):
		return "bar"

# OK

class Foo:
	@property
	def foo(self):
		return self._foo

	@foo.setter
	def foo(self, value):
		self._foo = value

# OK

# Then we decorate a new method with exactly the same name with the setter attribute of the original decorated with exactly the same name with the setter attribute of the original decorated foo method!

class Silly:
	@property
	def silly(self):
		"This is a silly property"
		print("You are getting silly")
		return self._silly
	
	@silly.setter
	def silly(self, value):
		print("You are making silly {}".format(value))
		self._silly = value

	@silly.deleter
	def silly(self):
		print("Whoah, you killed silly!")
		del self._silly

# When Should We Use Properties?

# With the property keyword smearing the division between behaviour and data, it can be confusing to know which one to choose.

from urllib.request import urlopen

class WebPage:
	def __init__(self, url):
		self.url = url
		self._content = None

	@property
	def content(self):
		if not self._content:
			print("Retrieving New Page...")
			self._content = urlopen(self.url).read()
		return self._content

# OK

>>> import time
>>> webpage = WebPage("http://ccphillips.net/")
>>> now = time.time()
>>> content1 = webpage.content
Retrieving New Page...
>>> time.time() - now
22.43316888809204
>>> now = time.time()
>>> content2 = webpage.content
>>> time.time() - now
1.9266459941864014
>>> content2 == content1
True

# OK

class AverageList(list):
	@property
	def average(self):
		return sum(self) / len(self)

# OK

>>> a = AverageList([1,2,3,4])
>>> a.average
2.5

# Managing Objects

# As an example, we'll write a program that does a find and replace action for text files stored in a compressed ZIP file. We'll need objects to represent the ZIP file and each individual text file (luckily, we don't have to write these classes, they're available in the Python Standard Library). The manager object will be responsible for ensuring three steps occur in order:

# 1. Unzipping the compressed file.
# 2. Performing the find and replace action.
# 3. Zipping up the new files.

import sys
import os
import shutil
import zipfile
class ZipReplace:
	def __init__(self, filename, search_string,
			replace_string):
		self.filename = filename
		self.search_string = search_string
		self.replace_string = replace_string
		self.temp_directory = "unzipped-{}".format(
			filename)

	def _full_filename(self, filename):
		return os.path.join(self.temp_directory, filename)

# OK

# Readability: The code for each step is in a self-contained unit that is easy to read and understand. The method names describe what the method does, and no additional documentation is required to understand what is going on.
# Extensibility: If a subclass wanted to use compressed TAR files instead of ZIP files, it could override the zip and unzip methods without having to duplicate the find_replace method.
# Partitioning: An external class could create an instance of this class and call the find and replace method directly on some folder without having to zip the content.

# OK

	def zip_find_replace(self):
		self.unzip_files()
		self.find_replace()
		self.zip_files()

	def unzip_files(self):
		os.mkdir(self.temp_directory)
		zip = zipfile.ZipFile(self.filename)
		try:
			zip.extractall(self.temp_directory)
		finally:
			zip.close()

	def find_replace(self):
		for filename in os.listdir(self.temp_directory):
			with open(self._full_filename(filename)) as file:
				contents = file.read()
			contents = contents.replace(
					self.search_string, self.replace_string)
			with open(
				self._full_filename(filename), "w") as file:
				file.write(contents)

	def zip_files(self):
		file = zipfile.ZipFile(self.filename, 'w')
		for filename in os.listdir(self.temp_directory):
			file.write(
				self._full_filename(filename), filename)
		shutil.rmtree(self.temp_directory)

if __name__ == "__main__":
	ZipReplace(*sys.argv[1:4]).zip_find_replace()

# OK

# OK

python zipsearch.py hello.zip hello hi

# Removing Duplicate Code

# In Practice

import os
import shutil
import zipfile

class ZipProcessor:
	def __init__(self, zipname):
		self.zipname = zipname
		self.temp_directory = "unzipped-{}".format(
			zipname[:-4])

	def _full_filename(self, filename):
		return os.path.join(self.temp_directory, filename)

	def process_zip(self):
		self.unzip_files()
		self.process_files()
		self.zip_files()

	def unzip_files(self):
		os.mkdir(self.temp_directory)
		zip = zipfile.ZipFile(self.zipname)
		try:
			zip.extractall(self.temp_directory)
		finally:
			zip.close()

	def zip_files(self):
		file = zipfile.ZipFile(self.zipname, 'w')
		for filename in os.listdir(self.temp_directory):
			file.write(self._full_filename(
				filename), filename)
		shutil.rmtree(self.temp_directory)

# Let us fix up our original zipsearch to make use of this parent class:

from zip_processor import ZipProcessor
import sys
import os

class ZipReplace(ZipProcessor):
	def __init__(self, filename, search_string,
			replace_string):
		super().__init__(filename)
		self.search_string = search_string
		self.replace_string = replace_string

	def process_files(self):
		'''perform a search and replace on all files
		in the temporary directory'''
		for filename in os.listdir(self.temp_directory):
			with open(self._full_filename(filename)) as file:
				contents = file.read()
			contents = contents.replace(
					self.search_string, self.replace_string)
			with open(
				self._full_filename(filename), "w") as file:
				file.write(contents)

if __name__ == "__main__":
	ZipReplace(*sys.argv[1:4]).process_zip()

# OK

from zip_processor import ZipProcessor
import os
import sys
from pygame import image
from pygame.transform import scale

class ScaleZip(ZipProcessor):
	def process_files(self):
		'''Scale each image in the directory to 640x480'''
		for filename in os.listdir(self.temp_directory):
			im = image.load(self._full_filename(filename))
			scaled = scale(im, (640,480))
			image.save(scaled, self._full_filename(filename))

if __name__ == "__main__":
	ScaleZip(*sys.argv[1:4]).process_zip()

# Or We Can Use Composition

import os
import shutil
import zipfile

class ZipProcessor:
	def __init__(self, zipname, processor):
		self.zipname = zipname
		self.temp_directory = "unzipped-{}".format(
			zipname[:-4])
		self.processor = processor

	def _full_filename(self, filename):
		return os.path.join(self.temp_directory, filename)

	def process_zip(self):
		self.unzip_files()
		self.processor.process(self)
		self.zip_files()

	def unzip_files(self):
		os.mkdir(self.temp_directory)
		zip = zipfile.ZipFile(self.zipname)
		try:
			zip.extractall(self.temp_directory)
		finally:
			zip.close()

	def zip_files(self):
		file = zipfile.ZipFile(self.zipname, 'w')
		for filename in os.listdir(self.temp_directory):
			file.write(self._full_filename(filename), filename)
		shutil.rmtree(self.temp_directory)

# OK

from zip_processor import ZipProcessor
import sys
import os

class ZipReplace:
	def __init__(self, search_string,
			replace_string):
		self.search_string = search_string
		self.replace_string = replace_string

	def process(self, zipprocessor):
		'''perform a search and replace on all files in the
		temporary directory'''
		for filename in os.listdir(
				zipprocessor.temp_directory):
			with open(
				zipprocessor._full_filename(filename)) as file:
				contents = file.read()
			contents = contents.replace(
				self.search_string, self.replace_string)
			with open(zipprocessor._full_filename(
					filename), "w") as file:
				file.write(contents)

if __name__ == "__main__":
	zipreplace = ZipReplace(*sys.argv[2:4])
	ZipProcessor(sys.argv[1], zipreplace).process_zip()

# OK

# Case Study

class Document:
	def __init__(self):
		self.characters = []
		self.cursor = 0
		self.filename = ''

	def insert(self, character):
		self.characters.insert(self.cursor, character)
		self.cursor += 1

	def delete(self):
		del self.characters[self.cursor]

	def save(self):
		f = open(self.filename, 'w')
		f.write(''.join(self.characters))
		f.close()

	def forward(self):
		self.cursor += 1

	def back(self):
		self.cursor -= 1

# OK

>>> doc = Document()
>>> doc.filename = "test_document"
>>> doc.insert('h')
>>> doc.insert('e')
>>> doc.insert('l')
>>> doc.insert('l')
>>> doc.insert('o')
>>> "".join(doc.characters)
'hello'
>>> doc.back()
>>> doc.delete()
>>> doc.insert('p')
>>> "".join(doc.characters)
'hellp'

# OK

class Cursor:
	def __init__(self, document):
		self.document = document
		self.position = 0

	def forward(self):
		self.position += 1

	def back(self):
		self.position -= 1

	def home(self):
		while self.document.characters[
				self.position-1] != '\n':
			self.position -= 1
			if self.position == 0:
				# Got to beginning of file before newline.
				break

	def end(self):
		while self.position < len(self.document.characters
				) and self.document.characters[
					self.position] != '\n':
			self.position += 1
	
	# OK

class Document:
	def __init__(self):
		self.characters = []
		self.cursor = Cursor(self)
		self.filename = ''

	def insert(self, character):
		self.characters.insert(self.cursor.position,
				character)
		self.cursor.forward()

	def delete(self):
		del self.characters[self.cursor.position]

	def save(self):
		f = open(self.filename, 'w')
		f.write(''.join(self.characters))
		f.close()

 # OK

>>> d = Document()
>>> d.insert('h')
>>> d.insert('e')
>>> d.insert('l')
>>> d.insert('l')
>>> d.insert('o')
>>> d.insert('\n')
>>> d.insert('w')
>>> d.insert('o')
>>> d.insert('r')
>>> d.insert('l')
>>> d.insert('d')
>>> d.cursor.home()
>>> d.insert("*")
>>> print("".join(d.characters))
hello
*world

# OK we can add a property to the Document class to give us the complete string:

@property
def string(self):
	return "".join(self.characters)

# OK

>>> print(d.string)
hello
world

# OK

class Character:
	def __init__(self, character,
			bold=False, italic=False, underline=False):
		assert len(character) == 1
		self.character = character
		self.bold = bold
		self.italic = italic
		self.underline = underline

	def __str__(self):
		bold = "*" if self.bold else ''
		italic = "/" if self.italic else ''
		underline = "_" if self.underline else ''
		return bold + italic + underline + self.character

# OK

def insert(self, character):
	if not hasattr(character, 'character'):
		character = Character(character)

# OK

@property
def string(self):
	return "".join((str(c) for c in self.characters))

# OK

def home(self):
	while self.document.characters[
			self.position-1].character != '\n':
		self.position -= 1
		if self.position == 0:
			# Got to beginning of file before newline.
			break

def end(self):
	while self.position < len(
			self.document.characters) and \
			self.document.characters[
					self.position
					].character != '\n':
		self.position += 1

# OK

>>> d = Document()
>>> d.insert('h')
>>> d.insert('e')
>>> d.insert(Character('l', bold=True))
>>> d.insert(Character('l', bold=True))
>>> d.insert('o')
>>> d.insert('\n')
>>> d.insert(Character('w', italic=True))
>>> d.insert(Character('o', italic=True))
>>> d.insert(Character('r', underline=True))
>>> d.insert('l')
>>> d.insert('d')
>>> print(d.string)
he*l*lo
/w/o_rld
>>> d.cursor.home()
>>> d.delete()
>>> d.insert('W')
>>> print(d.string)
he*l*lo
W/o_rld
>>> d.characters[0].underline = True
>>> print(d.string)
_he*l*lo
W/o_rld
>>>

# Exercises

# Well we will see maybe soon I cook up a little something of my own here rather shortly maybe I do not. OK duplicate code is bad. I do copy and paste code a lot but got in to re vectorising stuff where possible like on this one Trading Software Engineer coding round I did a really Good job.

# Summary

# In this chapter, we focused on identifying objects, especially objects that are not immediately apparent; objects that manage and control. In particular, we covered:

# Why objects should have both data and behaviour.
# How properties blur the distinction between data and behaviour.
# The Don't Repeat Yourself principle and the follies of duplicate code.
# Inheritance and composition for reducing code duplication.

# In the next chapter we'll cover several of the built-in Python data structures and objects, focusing on their object-oriented properties and how they can be extended or adapted.

# Python Data Structures

# In our examples so far, we've already seen many of the built-in Python data structures in action. You've probably covered many of them in introductory books or tutorials. In this chapter, we'll be discussing the object-oriented features of these data structures, when they should be used instead of a regular class, and when they should not be used. In particular we'll be covering:

# Tuples
# Dictionaries
# Lists And Sets
# How And Why To Extend Built-In Objects

# Empty Objects

>>> o = object()
>>> o.x = 5
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
AttributeError: 'object' object has no attribute 'x'

# OK

class MyObject:
	pass

# It is possible to set attributes on such classes:

>>> m = MyObject()
>>> m.x = "hello"
>>> m.x
'hello'

# Tuples And Named Tuples

# Immutable yeah yeah maybe this comes up on like a Triplebyte round I aced or something. OK can use them as keys in dictionaries makes sense so like maybe we were say counting like frequency counts then we could use a tuple here rather than a vector in the underlying hash map.

>>> stock = "GOOG", 613.30, 625.86, 610.50
>>> stock2 = ("GOOG", 613.30, 625.86, 610.50)

# OK

import datetime
def middle(stock, date):
	symbol, current, high, low = stock
	return (((high + low) /2), date)

mid_value, date = middle(("GOOG", 613.30, 625.86, 610.50),
		datetime.date(2010, 1, 6))

# Illustrates tuple unpacking.

>>> stock = "GOOG", 613.30, 625.86, 610.50
>>> high = stock[2]
>>> high
625.86

# OK

>>> stock[1:3]
(613.3, 625.86)

# Named Tuples

from collections import namedtuple
Stock = namedtuple("Stock", "symbol current high low")
stock = Stock("GOOG", 613.30, high=625.86, low=610.50)

# OK

>>> stock.high
625.86
>>> symbol, current, high, low = stock
>>> current
613.3

# OK

>>> stock.current = 609.27
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
AttributeError: can't set attribute

# Dictionaries

stocks = {"GOOG": (613.30, 625.86, 610.50),
			"MSFT": (30.25, 30.70, 30.19)}

# OK

>>> stocks["GOOG"]
(613.3, 625.86, 610.5)
>>> stocks["RIM"]
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
KeyError: 'RIM'

# OK

>>> print(stocks.get("RIM"))
None
>>> stocks.get("RIM", "NOT FOUND")
'NOT FOUND'

# OK

>>> stocks.setdefault("GOOG", "INVALID")
(613.3, 625.86, 610.5)
>>> stocks.setdefault("RIM", (67.38, 68.48, 67.28))
(67.38, 68.48, 67.28)
>>> stocks["RIM"]
(67.38, 68.48, 67.28)

# OK

>>> for stock, values in stocks.items():
... print("{} last value is {}".format(stock, values[0]))
...
GOOG last value is 613.3
RIM last value is 67.38
MSFT last value is 30.25

# OK

>>> stocks["GOOG"] = (597.63, 610.00, 596.28)
>>> stocks['GOOG']
(597.63, 610.0, 596.28)

# OK

random_keys = {}
random_keys["astring"] = "somestring"
random_keys[5] = "aninteger"
random_keys[25.2] = "floats work too"
random_keys[("abc", 123)] = "so do tuples"
class AnObject:
	def __init__(self, avalue):
		self.avalue = avalue
my_object = AnObject(14)
random_keys[my_object] = "We can even store objects"
my_object.avalue = 12
try:
	random_keys[[1,2,3]] = "we can't store lists though"
except:
	print("unable to store list\n")
for key, value in random_keys.items():
	print("{} has value {}".format(key, value))

# When Should We Use Dictionaries?

# Dictionaries are extremely versatile and have numerous uses. No poo Sherlock.

# Using defaultdict

def letter_frequency(sentence):
	frequencies = {}
	for letter in sentence:
		frequency = frequencies.setdefault(letter, 0)
		frequencies[letter] = frequency + 1
	return frequencies

# OK

from collections import defaultdict
def letter_frequency(sentence):
	frequencies = defaultdict(int)
	for letter in sentence:
		frequencies[letter] += 1
	return frequencies

# OK

from collections import defaultdict
num_items = 0
def tuple_counter():
	global num_items
	num_items += 1
	return (num_items, [])

d = defaultdict(tuple_counter)

# OK

>>> d = defaultdict(tuple_counter)
>>> d['a'][1].append("hello")
>>> d['b'][1].append('world')
>>> d
defaultdict(<function tuple_counter at 0x82f2c6c>,
{'a': (1, ['hello']), 'b': (2, ['world'])})

# Lists

import string
CHARACTERS = list(string.ascii_letters) + [" "]

def letter_frequency(sentence):
	frequencies = [(c, 0) for c in CHARACTERS]
	for letter in sentence:
		index = CHARACTERS.index(letter)
		frequencies[index] = (letter,frequencies[index][1]+1)
	return frequencies

# OK

>>> letter_frequency("the quick brown fox jumps over the lazy dog")
[('a', 1), ('b', 1), ('c', 1), ('d', 1), ('e', 3), ('f', 1), ('g', 1),
('h', 2), ('i', 1), ('j', 1), ('k', 1), ('l', 1), ('m', 1), ('n', 1),
('o', 4), ('p', 1), ('q', 1), ('r', 2), ('s', 1), ('t', 2), ('u', 2),
('v', 1), ('w', 1), ('x', 1), ('y', 1), ('z', 1), ('A', 0), ('B', 0),
('C', 0), ('D', 0), ('E', 0), ('F', 0), ('G', 0), ('H', 0), ('I', 0),
('J', 0), ('K', 0), ('L', 0), ('M', 0), ('N', 0), ('O', 0), ('P', 0),
('Q', 0), ('R', 0), ('S', 0), ('T', 0), ('U', 0), ('V', 0), ('W', 0),
('X', 0), ('Y', 0), ('Z', 0), (' ', 8)]

# Sorting Lists

class WeirdSortee:
	def __init__(self, string, number, sort_num):
		self.string = string
		self.number = number
		self.sort_num = sort_num

def __lt__(self, object):
	if self.sort_num:
		return self.number < object.number
	return self.string < object.string

def __repr__(self):
	return"{}:{}".format(self.string, self.number)

# OK

>>> a = WeirdSortee('a', 4, True)
>>> b = WeirdSortee('b', 3, True)
>>> c = WeirdSortee('c', 2, True)
>>> d = WeirdSortee('d', 1, True)
>>> l = [a,b,c,d]
>>> l
[a:4, b:3, c:2, d:1]
>>> l.sort()
>>> l
[d:1, c:2, b:3, a:4]
>>> for i in l:
... i.sort_num = False
...
>>> l.sort()
>>> l
[a:4, b:3, c:2, d:1]

# OK

>>> x = [(1,'c'), (2,'a'), (3, 'b')]
>>> x.sort()
>>> x
[(1, 'c'), (2, 'a'), (3, 'b')]
>>> x.sort(key=lambda i: i[1])
>>> x
[(2, 'a'), (3, 'b'), (1, 'c')]

# OK

>>> l = ["hello", "HELP", "Helo"]
>>> l.sort()
>>> l
['HELP', 'Helo', 'hello']
>>> l.sort(key=str.lower)
>>> l
['hello', 'Helo', 'HELP']

# Sets

song_library = [("Phantom Of The Opera", "Sarah Brightman"),
	("Knocking On Heaven's Door", "Guns N' Roses"),
	("Captain Nemo", "Sarah Brightman"),
	("Patterns In The Ivy", "Opeth"),
	("November Rain", "Guns N' Roses"),
	("Beautiful", "Sarah Brightman"),
	("Mal's Song", "Vixy and Tony")]

artists = set()
for song, artist in song_library:
	artists.add(artist)

print(artists)

# OK

{'Sarah Brightman', "Guns N' Roses", 'Vixy and Tony', 'Opeth'}

# OK

>>> "Opeth" in artists
True
>>> for artist in artists:
... print("{} plays good music".format(artist))
...
Sarah Brightman plays good music
Guns N' Roses plays good music
Vixy and Tony play good music
Opeth plays good music
>>> alphabetical = list(artists)
>>> alphabetical.sort()
>>> alphabetical
["Guns N' Roses", 'Opeth', 'Sarah Brightman', 'Vixy and Tony']

# OK

# union method, intersection method, symmetric_difference methods

# For the usual sets operations.

my_artists = {"Sarah Brightman", "Guns N' Roses",
		"Opeth", "Vixy and Tony"}
auburns_artists = {"Nickelback", "Guns N' Roses",
		"Savage Garden"}
print("All: {}".format(my_artists.union(auburns_artists)))
print("Both: {}".format(auburns_artists.intersection(my_artists)))
print("Either but not both: {}".format(
	my_artists.symmetric_difference(auburns_artists)))

# OK

All: {'Sarah Brightman', "Guns N' Roses", 'Vixy and Tony',
'Savage Garden', 'Opeth', 'Nickelback'}
Both: {"Guns N' Roses"}
Either but not both: {'Savage Garden', 'Opeth', 'Nickelback',
'Sarah Brightman', 'Vixy and Tony'}

# issubset issuperset

my_artists = {"Sarah Brightman", "Guns N' Roses",
		"Opeth", "Vixy and Tony"}

bands = {"Guns N' Roses", "Opeth"}

print("my_artists is to bands:")
print("issuperset: {}".format(my_artists.issuperset(bands)))
print("issubset: {}".format(my_artists.issubset(bands)))
print("difference: {}".format(my_artists.difference(bands)))
print("*"*20)
print("bands is to my_artists:")
print("issuperset: {}".format(bands.issuperset(my_artists)))
print("issubset: {}".format(bands.issubset(my_artists)))
print("difference: {}".format(bands.difference(my_artists)))

# OK

my_artists is to bands:
issuperset: True
issubset: False
difference: {'Sarah Brightman', 'Vixy and Tony'}
********************
bands is to my_artists:
issuperset: False
issubset: True
difference: set()

# Extending Built-Ins

c = a + b
c = a.add(b)

l[0] = 5
l.setitem(0, 5)

d[key] = value
d.setitem(key, value)

for x in alist:
	# Do something with x
it = alist.iterator()
while it.has_next():
	x = it.next()
	# Do something with x

# OK

class SillyInt(int):
	def __add__(self, num):
		return 0

# OK

>>> a = SillyInt(1)
>>> b = SillyInt(2)
>>> a + b
0

# OK

>>> dir(list)
['__add__', '__class__', '__contains__', '__delattr__','__delitem__', '__
doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__getitem_
_', '__gt__', '__hash__', '__iadd__', '__imul__', '__init__', '__iter__',
'__le__', '__len__', '__lt__', '__mul__', '__ne__', '__new__', '__reduce_
_', '__reduce_ex__', '__repr__', '__reversed__', '__rmul__', '__setattr__
', '__setitem__', '__sizeof__', '__str__', '__subclasshook__', 'append',
'count', 'extend', 'index', 'insert', 'pop', 'remove', 'reverse', 'sort']

# Want additional information on how any of these methods works, we can use the help function:

>>> help(list.__add__)
Help on wrapper_descriptor:

__add__(...)
	x.__add__(y) <==> x+y

# OK

from collections import KeysView, ItemsView, ValuesView
class DictSorted(dict):
	def __new__(*args, **kwargs):
		new_dict = dict.__new__(*args, **kwargs)
		new_dict.ordered_keys = []
		return new_dict

	def __setitem__(self, key, value):
		'''self[key] = value syntax'''
		if key not in self.ordered_keys:
			self.ordered_keys.append(key)
		super().__setitem__(key, value)

	def setdefault(self, key, value):
		if key not in self.ordered_keys:
			self.ordered_keys.append(key)
		return super().setdefault(key, value)

	def keys(self):
		return KeysView(self)

	def values(self):
		return ValuesView(self)

	def items(self):
		return ItemsView(self)

	def __iter__(self):
		'''for x in self syntax'''
		return self.ordered_keys.__iter__()

# OK

>>> ds = DictSorted()
>>> d = {}
>>> ds['a'] = 1
>>> ds['b'] = 2
>>> ds.setdefault('c', 3)
3
>>> d['a'] = 1
>>> d['b'] = 2
>>> d.setdefault('c', 3)
3
>>> for k,v in ds.items():
... print(k,v)
...
a 1
b 2
c 3
>>> for k,v in d.items():
... print(k,v)
...
a 1
c 3
b 2

# OK

# Case Study

# To tie everything together, we will write a very useful simple link ollector which will visit a website and collect every link on every page it finds in that site.

<html>
	<body>
		<a href="contact.html">Contact us</a>
		<a href="blog.html">Blog</a>
		<a href="esme.html">My Dog</a>
		<a href="/hobbies.html">Some hobbies</a>
		<a href="/contact.html">Contact AGAIN</a>
		<a href="http://www.archlinux.org/">Favorite OS</a>
	</body>
</html>

# OK

python3 -m http.server

# OK

from urllib.request import urlopen
from urllib.parse import urlparse
import re
import sys
LINK_REGEX = re.compile(
		"<a [^>]*href=['\"]([^'\"]+)['\"][^>]*>")

class LinkCollector:
	def __init__(self, url):
		self.url = "http://" + urlparse(url).netloc

	def collect_links(self, path="/"):
		full_url = self.url + path
		page = str(urlopen(full_url).read())
		links = LINK_REGEX.findall(page)
		print(links)

if __name__ == "__main__":
	LinkCollector(sys.argv[1]).collect_links()

# OK

['contact.html', 'blog.html', 'esme.html', '/hobbies.html',
'/contact.html', 'http://www.archlinux.org/']

# OK

def normalize_url(self, path, link):
	if link.startswith("http://"):
		return link
	elif link.startswith("/"):
		return self.url + link
	else:
		return self.url + path.rpartition('/'
			)[0] + '/' + link

# OK

class LinkCollector:
	def __init__(self, url):
		self.url = "http://+" + urlparse(url).netloc
		self.collected_links = set()
		self.visited_links = set()

	def collect_links(self, path="/"):
		full_url = self.url + path
		self.visited_links.add(full_url)
		page = str(urlopen(full_url).read())
		links = LINK_REGEX.findall(page)
		links = {self.normalize_url(path, link
			) for link in links}
		self.collected_links = links.union(
			self.collected_links)
		unvisited_links = links.difference(
			self.visited_links)
		print(links, self.visited_links,
			self.collected_links, unvisited_links)
	
# OK

for link in unvisited_links:
	if link.startswith(self.url):
		self.collect_links(urlparse(link).path)

# OK

if __name__ == "__main__":
	collector = LinkCollector(sys.argv[1])
	collector.collect_links()
	for link in collector.collected_links:
		print(link)

# OK

$ python3 link_collector.py http://localhost:8000
http://localhost:8000/
http://en.wikipedia.org/wiki/Cavalier_King_Charles_Spaniel
http://masterhelenwu.com
http://archlinux.me/dusty/
http://localhost:8000/blog.html
http://ccphillips.net/
http://localhost:8000/contact.html
http://localhost:8000/taichi.html
http://www.archlinux.org/
http://localhost:8000/esme.html
http://localhost:8000/hobbies.html

# OK so this very coolio doolio useful for sure uh scraping websites and stuff man wonders about these little Twitter user scrapers tools I never did actually choose to be curious and examine the source code on those projects maybe would be cool and useful right now to go explore that territory of machine land and see how those engineers engineer those precise sorts of things.

from urllib.request import urlopen
from urllib.parse import urlparse
import re
import sys
LINK_REGEX = re.compile(
		"<a [^>]*href=['\"]([^'\"]+)['\"][^>]*>")

class LinkCollector:
	def __init__(self, url):
		self.url = "http://%s" % urlparse(url).netloc
		self.collected_links = {}
		self.visited_links = set()

	def collect_links(self, path="/"):
		full_url = self.url + path
		self.visited_links.add(full_url)
		page = str(urlopen(full_url).read())
		links = LINK_REGEX.findall(page)
		links = {self.normalize_url(path, link
			) for link in links}
		self.collected_links[full_url] = links
		for link in links:
			self.collected_links.setdefault(link, set())
		unvisited_links = links.difference(
				self.visited_links)
		for link in unvisited_links:
			if link.startswith(self.url):
				self.collect_links(urlparse(link).path)

	def normalize_url(self, path, link):
		if link.startswith("http://"):
			return link
		elif link.startswith("/"):
			return self.url + link
		else:
			return self.url + path.rpartition('/'
				)[0] + '/' + link

if __name__ == "__main__":
	collector = LinkCollector(sys.argv[1])
	collector.collect_links()
	for link, item in collector.collected_links.items():
		print("{}: {}".format(link, item))

# Exercises

# OK I am pretty good with data structures of course.

# Summary

# We've covered several built-in data structures and attempted to understand how to choose one for specific applications. Sometimes the best thing we can do is create a new class of objects, but often, one of the built-ins provides exactly what we need. When it doesn't, we can always use inheritance or composition to adapt them to our needs. In particular, we covered:

# Tuples And Named Tuples
# Dictionaries And Default Dictionaries
# Lists And Sets
# Overriding Special Variables On Built-Ins

# In the next chapter we'll discuss how to integrate the object-oriented and not-soobject-oriented aspects of Python. Along the way, we'll discover that it's more object-oriented than it looks at first sight!

# Python Object Oriented Shortcuts

# Now let's look at some aspects of Python that appear more reminiscent of structural or functional programming than object-oriented programming. Although object-oriented programming is the most popular kid on the block these days, the old paradigms still offer useful tools. Most of these tools are really syntactic sugar over an underlying object-oriented implementation; we can think of them as a further abstraction layer built on top of the (already abstracted) object-oriented paradigm. In this chapter we'll be covering:

# Built-In Functions That Take Care Of Common Tasks In One Call
# List, Set, And Dictionary Comprehensions
# Generators
# An Alternative To Method Overloading
# Functions As Objects

# Python Built-In Functions

# There are numerous functions in Python that perform a task or calculate a result on certain objects without being methods on the class. Their purpose is to abstract common calculations that apply to many types of classes. This is applied duck typing; these functions accept objects with certain attributes or methods that satisfy a given interface, and are able to perform generic tasks on the object.

# Len

>>> len([1,2,3,4])
4

# Reversed

normal_list=[1,2,3,4,5]

class CustomSequence():
	def __len__(self):
		return 5

	def __getitem__(self, index):
		return "x{0}".format(index)

class FunkyBackwards(CustomSequence):
	def __reversed__(self):
		return "BACKWARDS!"

for seq in normal_list, CustomSequence(), FunkyBackwards():
	print("\n{}: ".format(seq.__class__.__name__), end="")
	for item in reversed(seq):
		print(item, end=", ")

# OK

list: 5, 4, 3, 2, 1,
CustomSequence: x4, x3, x2, x1, x0,
FunkyBackwards: B, A, C, K, W, A, R, D, S, !,

# Enumerate

import sys
filename = sys.argv[1]

with open(filename) as file:
	for index, line in enumerate(file):
		print("{0}: {1}".format(index+1, line), end='')

# OK

1: import sys
2: filename = sys.argv[1]
3:
4: with open(filename) as file:
5: for index, line in enumerate(file):
6: print("{0}: {1}".format(index+1, line), end='')

# Zip Function

first last email
john smith jsmith@example.com
jane doan janed@example.com
david neilson dn@example.com

# OK

import sys
filename = sys.argv[1]
contacts = []
with open(filename) as file:
	header = file.readline().strip().split('\t')
	for line in file:
		line = line.strip().split('\t')
		contact_map = zip(header, line)
		contacts.append(dict(contact_map))
for contact in contacts:
	print("email: {email} -- {last}, {first}".format(
		**contact))

# OK

email: jsmith@example.com -- smith, john
email: janed@example.com -- doan, jane
email: dn@example.com -- neilson, david

# OK

>>> list_one = ['a', 'b', 'c']
>>> list_two = [1, 2, 3]
>>> zipped = zip(list_one, list_two)
>>> zipped = list(zipped)
>>> zipped
[('a', 1), ('b', 2), ('c', 3)]
>>> unzipped = zip(*zipped)
>>> list(unzipped)
[('a', 'b', 'c'), (1, 2, 3)]

# Other Functions

def min_max_indexes(seq):
	minimum = min(enumerate(seq), key=lambda s: s[1])
	maximum = max(enumerate(seq), key=lambda s: s[1])
	return minimum[0], maximum[0]

# OK

>>> alist = [5,0,1,4,6,3]
>>> min_max_indexes(alist)
(1, 4)
>>> alist[1], alist[4]
(0, 6)

# Comprehension

# List Comprehensions

input_strings = ['1', '5', '28', '131', '3']
output_integers = []
for num in input_strings:
	output_integers.append(int(num))

# OK

input_strings = ['1', '5', '28', '131', '3']
output_integers = [int(num) for num in input_strings]

# OK

output_ints = [int(n) for n in input_strings if len(n) < 3]

# OK

import sys
filename = sys.argv[1]

with open(filename) as file:
	header = file.readline().strip().split('\t')
	contacts = [
			dict(
				zip(header, line.strip().split('\t'))
				) for line in file
			]

# Set And Dictionary Comprehensions

from collections import namedtuple
Book = namedtuple("Book", "author title genre")
books = [
	Book("Pratchett", "Nightwatch", "fantasy"),
	Book("Pratchett", "Thief Of Time", "fantasy"),
	Book("Le Guin", "The Dispossessed", "scifi"),
	Book("Le Guin", "A Wizard Of Earthsea", "fantasy"),
	Book("Turner", "The Thief", "fantasy"),
	Book("Phillips", "Preston Diamond", "western"),
	Book("Phillips", "Twice Upon A Time", "scifi"),
]
fantasy_authors = {
	b.author for b in books if b.genre == 'fantasy'}

# OK

>>> fantasy_authors
{'Turner', 'Pratchett', 'Le Guin'}

# OK

fantasy_titles = {
	b.title: b for b in books if b.genre == 'fantasy'}

# Generator Expressions

Jan 26, 2010 11:25:25 DEBUG This is a debugging message.
Jan 26, 2010 11:25:36 INFO This is an information method.
Jan 26, 2010 11:25:46 WARNING This is a warning. It could be
serious.
Jan 26, 2010 11:25:52 WARNING Another warning sent.
Jan 26, 2010 11:25:59 INFO Here's some information.
Jan 26, 2010 11:26:13 DEBUG Debug messages are only useful if
you want to figure something out.
Jan 26, 2010 11:26:32 INFO Information is usually harmless,
but helpful.
Jan 26, 2010 11:26:40 WARNING Warnings should be heeded.
Jan 26, 2010 11:26:54 WARNING Watch for warnings.

# OK

import sys

inname = sys.argv[1]
outname = sys.argv[2]

with open(inname) as infile:
	with open(outname, "w") as outfile:
		warnings = (l for l in infile if 'WARNING' in l)
		for l in warnings:
			outfile.write(l)

# OK

Jan 26, 2010 11:25:46 WARNING This is a warning. It could be
serious.
Jan 26, 2010 11:25:52 WARNING Another warning sent.
Jan 26, 2010 11:26:40 WARNING Warnings should be heeded.
Jan 26, 2010 11:26:54 WARNING Watch for warnings.

# Generators

import sys
inname, outname = sys.argv[1:3]

with open(inname) as infile:
	with open(outname, "w") as outfile:
		warnings = (l.replace('\tWARNING', '')
				for l in infile if 'WARNING' in l)
		for l in warnings:
			outfile.write(l)

# OK

import sys
inname, outname = sys.argv[1:3]

with open(inname) as infile:
	with open(outname, "w") as outfile:
		for l in infile:
			if 'WARNING' in l:
				outfile.write(l.replace('\tWARNING', ''))

# OK

import sys
inname, outname = sys.argv[1:3]

class WarningFilter:
	def __init__(self, insequence):
		self.insequence = insequence

	def __iter__(self):
		return self

	def __next__(self):
		l = self.insequence.readline()
		while l and 'WARNING' not in l:
			l = self.insequence.readline()
		if not l:
			raise StopIteration
		return l.replace('\tWARNING', '')

with open(inname) as infile:
	with open(outname, "w") as outfile:
		filter = WarningFilter(infile)
		for l in filter:
			outfile.write(l)

# OK

import sys
inname, outname = sys.argv[1:3]

def warnings_filter(insequence):
	for l in insequence:
		if 'WARNING' in l:
			yield l.replace('\tWARNING', '')

with open(inname) as infile:
	with open(outname, "w") as outfile:
		filter = warnings_filter(infile)
		for l in filter:
			outfile.write(l)

# OK

>>> print(warnings_filter([]))
<generator object warnings_filter at 0xb728c6bc>

# An Alternative To Method Overloading

def no_args():
	pass

# And here is how it is called:

no_args()

# OK

def mandatory_args(x, y, z):
	pass

# And to call it:

mandatory_args("a string", a_variable, 5)

# Default Arguments

def default_arguments(x, y, z, a="Some String", b=False):
	pass

# OK

kwargs("a string", variable, 8, "", True)

# OK

kwargs("a longer string", some_variable, 14)

# OK

kwargs("a string", variable, 14, b=True)

# OK

>>> kwargs(y=1,z=2,x=3,a="hi")
3 1 2 hi False

# OK

number = 5
def funky_function(number=number):
	print(number)
number=6
funky_function(8)
funky_function()
print(number)

# OK

>>> def hello(b=[]):
... b.append('a')
... print(b)
...
>>> hello()
['a']
>>> hello()
['a', 'a']

# OK

# Variable Argument Lists

def get_pages(*links):
	for link in links:
		# Download the link with urllib.
		print(link)

# OK

get_pages()
get_pages('http://www.archlinux.org')
get_pages('http://www.archlinux.org',
		'http://ccphillips.net/')

# OK

class Options:
	default_options = {
			'port': 21,
			'host': 'localhost',
			'username': None,
			'password': None,
			'debug': False,
			}

	def __init__(self, **kwargs):
		self.options = dict(Options.default_options)
		self.options.update(kwargs)

	def __getitem__(self, key):
		return self.options[key]

# OK

>>> options = Options(username="dusty", password="drowssap",
 debug=True)
>>> options['debug']
True
>>> options['port']
21
>>> options['username']
'dusty'

# OK

import shutil
import os.path

def augmented_move(target_folder, *filenames,
		verbose=False, **specific):
	'''Move all filenames into the target_folder, allowing
	specific treatment of certain files.'''

	def print_verbose(message, filename):
		'''print the message only if verbose is enabled'''
		if verbose:
			print(message.format(filename))

	for filename in filenames:
		target_path = os.path.join(target_folder, filename)
		if filename in specific:
			if specific[filename] == 'ignore':
				print_verbose("Ignoring {0}", filename)
			elif specific[filename] == 'copy':
				print_verbose("Copying {0}", filename)
				shutil.copyfile(filename, target_path)
		else:
			print_verbose("Moving {0}", filename)
			shutil.move(filename, target_path)

# OK

>>> augmented_move("move_here", "one", "two")

# OK

>>> augmented_move("move_here", "three", verbose=True)
Moving three

# OK

>>> augmented_move("move_here", "four", "five", "six",
 four="copy", five="ignore")

# OK

>>> augmented_move("move_here", "seven", "eight", "nine",
 seven="copy", verbose=True, eight="ignore")
Copying seven
Ignoring eight
Moving nine

# Unpacking Arguments

def show_args(arg1, arg2, arg3="THREE"):
	print(arg1, arg2, arg3)
some_args = range(3)
more_args = {
		"arg1": "ONE",
		"arg2": "TWO"}
print("Unpacking a sequence:", end=" ")
show_args(*some_args)
print("Unpacking a dict:", end=" ")
show_args(**more_args)

# OK

Unpacking a sequence: 0 1 2
Unpacking a dict: ONE TWO THREE

# Functions Are Objects Too

def my_function():
	print("The Function Was Called")
my_function.description = "A silly function"

def second_function():
	print("The second was called")
second_function.description = "A sillier function."

def another_function(function):
	print("The description:", end=" ")
	print(function.description)
	print("The name:", end=" ")
	print(function.__name__)
	print("The class:", end=" ")
	print(function.__class__)
	print("Now I'll call the function passed in")
	function()

another_function(my_function)
another_function(second_function)

# OK

The description: A silly function
The name: my_function
The class: <class 'function'>
Now I'll call the function passed in
The Function Was Called
The description: A sillier function.
The name: second_function
The class: <class 'function'>
Now I'll call the function passed in
The second was called

# OK

import datetime
import time

class TimedEvent:
	def __init__(self, endtime, callback):
		self.endtime = endtime
		self.callback = callback

	def ready(self):
		return self.endtime <= datetime.datetime.now()

class Timer:
	def __init__(self):
		self.events = []

	def call_after(self, delay, callback):
		end_time = datetime.datetime.now() + \
				datetime.timedelta(seconds=delay)

		self.events.append(TimedEvent(end_time, callback))

	def run(self):
		while True:
			ready_events = (e for e in self.events if e.ready())
			for event in ready_events:
				event.callback(self)
				self.events.remove(event)
			time.sleep(0.5)

# OK

from timer import Timer
import datetime

def format_time(message, *args):
	now = datetime.datetime.now().strftime("%I:%M:%S")
	print(message.format(*args, now=now))

def one(timer):
	format_time("{now}: Called One")

def two(timer):
	format_time("{now}: Called Two")

def three(timer):
	format_time("{now}: Called Three")

class Repeater:
	def __init__(self):
		self.count = 0

	def repeater(self, timer):
		format_time("{now}: repeat {0}", self.count)
		timer.call_after(5, self.repeater)

timer = Timer()
timer.call_after(1, one)
timer.call_after(2, one)
timer.call_after(2, two)
timer.call_after(4, two)
timer.call_after(3, three)
timer.call_after(6, three)
repeater = Repeater()
timer.call_after(5, repeater.repeater)
format_time("{now}: Starting")
timer.run()

# OK

02:53:35: Starting
02:53:36: Called One
02:53:37: Called One
02:53:37: Called Two
02:53:38: Called Three
02:53:39: Called Two
02:53:40: repeat 0
02:53:41: Called Three
02:53:45: repeat 1
02:53:50: repeat 2
02:53:55: repeat 3
02:54:00: repeat 4

# OK

# Using Functions As Attributes

class A:
	def print(self):
		print("my class is A")

	def fake_print():
		print("my class is not A")
a = A()
a.print()
a.print = fake_print
a.print()

# OK

my class is A
my class is not A

# Callable Objects

class Repeater:
	def __init__(self):
		self.count = 0

	def __call__(self, timer):
		format_time("{now}: repeat {0}", self.count)
		self.count += 1
		timer.call_after(5, self)

timer = Timer()
timer.call_after(5, Repeater())
format_time("{now}: Starting")
timer.run()

# Case Study

python -m smtpd -n -c DebuggingServer localhost:1025

# OK

import smtplib
from email.mime.text import MIMEText

def send_email(subject, message, from_addr, *to_addrs,
		host="localhost", port=1025, **headers):

	email = MIMEText(message)
	email['Subject'] = subject
	email['From'] = from_addr
	for header, value in headers.items():
		email[header] = value

	sender = smtplib.SMTP(host, port)
	for addr in to_addrs:
		del email['To']
		email['To'] = addr
		sender.sendmail(from_addr, addr, email.as_string())
	sender.quit()

 # OK

 def send_email(subject, message, from_addr, *to_addrs,
 		host="localhost", port=1025, headers=None):
 
 	headers = {} if headers is None else headers

 # OK

 >>> send_email("A model subject", "The message contents",
 "from@example.com", "to1@example.com", "to2@example.com")

 # OK

 ---------- MESSAGE FOLLOWS ----------
Content-Type: text/plain; charset="us-ascii"
MIME-Version: 1.0
Content-Transfer-Encoding: 7bit
Subject: A model subject
From: from@example.com
To: to1@example.com
X-Peer: 127.0.0.1
The message contents
------------ END MESSAGE ------------
---------- MESSAGE FOLLOWS ----------
Content-Type: text/plain; charset="us-ascii"
MIME-Version: 1.0
Content-Transfer-Encoding: 7bit
Subject: A model subject
From: from@example.com
To: to2@example.com
X-Peer: 127.0.0.1
The message contents
------------ END MESSAGE ------------

# OK

from collections import defaultdict
class MailingList:
	'''Manage groups of e-mail addresses for sending e-mails.'''
	def __init__(self):
		self.email_map = defaultdict(set)

	def add_to_group(self, email, group):
		self.email_map[email].add(group)

 # OK

def emails_in_groups(self, *groups):
	groups = set(groups)
	return {e for (e, g) in self.email_map.items()
			if g & groups}

 # OK

def send_mailing(self, subject, message, from_addr,
		*groups, **kwargs):
	emails = self.emails_in_groups(*groups)
	send_email(subject, message, from_addr,
			*emails, **kwargs)

 # OK

 >>> python -i mailing_list.py

 # OK

 >>> m = MailingList()

 # OK

>>> m.add_to_group("friend1@example.com", "friends")
>>> m.add_to_group("friend2@example.com", "friends")
>>> m.add_to_group("family1@example.com", "family")
>>> m.add_to_group("pro1@example.com", "professional")

# OK

>>> m.send_mailing("A Party",
"Friends and family only: a party", "me@example.com", "friends",
"family", headers={"Reply-To": "me2@example.com"})

# Exercises

# OKOKOK good solid day of Good solid hard work this all seems very very very mission critical and important so we keep up the Good work and grind the grind or whatever I mean get high repeatedly and choose to expose ourselves to the Right stuff which leads to the Right target goal outcomes and boom we are booming.

# Summary

# We covered several very different topics in this chapter. Each represented an important non Object-Oriented feature that is popular in Python. Just because we can use Object-Oriented principles does not always mean we should! However, we also saw that "the Python way" often just provides a shortcut to traditional Object-Oriented syntax. Knowing the Object-Oriented principles underlying these tools allows us to use them effectively in our own classes.

# We covered:

# Built-In Functions
# Comprehensions And Generators
# Function Arguments, Variable Arguments, And Keyword Arguments
# Callback Functions And Callable Objects

# In the next chapter, we're going to study design patterns; building blocks that object-oriented programmers use to create maintainable applications. In many cases, we'll see that, as in this chapter, Python provides syntax for popular design patterns that we can use instead.

# Python Design Patterns I

# We've covered the basic building blocks of object-oriented programming. Now, we'll look at secondary structures that can be built from those blocks. These higher-level structures, called design patterns, can help organise complex systems. In the next two chapters, we'll be covering:

# What Design Patterns Are
# Numerous Specific Patterns
# A Canonical Implementation Of Each Pattern In Python
# Python Syntax To Replace Certain Patterns

# Design Patterns

# Ensure structural integrity. OK various possible designs. Righto in terms of Object Oriented Design. We already have plenty of experience with the most common design patterns. Right the iterator pattern is meant to provide a common interface for looping over the items in a sequence. For example, 2 iterators may loop over the items in different directions, or in a sorted order. Right.

while not iterator.done():
	item = iterator.next()
	# do something with the item

# Of course in Python the much more readable, and writeable:

for item in iterator

# Syntax to actually access the items.

# Decorator Pattern

# There are two primary uses of the decorator pattern:

# Enhancing the response of a component that is sending data to a second component.

# Supporting multiple optional behaviours.

# Core, all the decorators implement a specific Interface. The decorators maintain a reference to another instance of that Interface, via composition.

# Decorator Example

import socket

def respond(client):
	response = input("Enter a value: ")
	client.send(bytes(response, 'utf8'))
	client.close()

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('localhost',2401))
server.listen(1)
try:
	while True:
		client, addr = server.accept()
		respond(client)
finally:
	server.close()

# respond function accepts a socket parameter and prompts for data to be sent as a reply, then sends it.

import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('localhost', 2401))
print("Received: {0}".format(client.recv(1024)))
client.close()

# OK

class LogSocket:
	def __init__(self, socket):
		self.socket = socket

def send(self, data):
	print("Sending {0} to {1}".format(
		data, self.socket.getpeername()[0]))
	self.socket.send(data)

def close(self):
	self.socket.close()

# OK send and close interface to client sockets. This seems really important. A better decorator would also implement [and possibly customise] all of the socket methods.

respond(LogSocket(client))

# OK

import gzip
from io import BytesIO

class GzipSocket:
	def __init__(self, socket):
		self.socket = socket

	def send(self, data):
		buf = BytesIO()
		zipfile = gzip.GzipFile(fileobj=buf, mode="w")
		zipfile.write(data)
		zipfile.close()
		self.socket.send(buf.getvalue())

	def close(self):
		self.socket.close()

# OK

client, addr = server.accept()
if log_send:
	client = LoggingSocket(client)
if client.getpeername()[0] in compress_hosts:
	client = GzipSocket(client)
respond(client)

# OK send method.

client, addr = server.accept()
if log_send:
	client = LoggingSocket(client)
if client.getpeername()[0] in compress_hosts:
	client = GzipSocket(client)
respond(client)

# Decorators In Python

# The decorator pattern is useful in Python.

import time

def log_calls(func):
	def wrapper(*args, **kwargs):
		now = time.time()
		print("Calling {0} with {1} and {2}".format(
			func.__name__, args, kwargs))
		return_value = func(*args, **kwargs)
		print("Executed {0} in {1}ms".format(
			func.__name__, time.time() - now))
		return return_value
	return wrapper

def test1(a,b,c):
	print("\ttest1 called")

def test2(a,b):
	print("\ttest2 called")

def test3(a,b):
	print("\ttest3 called")
	time.sleep(1)

test1 = log_calls(test1)
test2 = log_calls(test2)
test3 = log_calls(test3)

test1(1,2,3)
test2(4,b=5)
test3(6,7)

# This decorator function is very similar to the example we explored earlier; in those cases, the decorator took a socket-like object and created a socket-like object. This time, our decorator takes a function object and returns a new function object. This code is comprised of three separate tasks: 

# A function, log_calls accepts a function.
# The function defines (internally) a new function, named wrapper, that does some extra calculations before calling the original function.
# This new function is returned, to replace the original function.

@log_calls
def test1(a,b,c):
	print("\ttest1 called")

# Observer Pattern

# Useful for state monitouring and event handling situations.

# Observer Example

class Inventory:
	def __init__(self):
		self.observers = []
		self._product = None
		self._quantity = 0

	def attach(self, observer):
		self.observers.append(observer)

	@property
	def product(self):
		return self._product
	@product.setter

	def product(self, value):
		self._product = value
		self._update_observers()

	@property
	def quantity(self):
		return self._quantity
	@quantity.setter

	def quantity(self, value):
		self._quantity = value
		self._update_observers()

	def _update_observers(self):
		for observer in self.observers:
			observer()

# OK

class ConsoleObserver:
	def __init__(self, inventory):
		self.inventory = inventory

	def __call__(self):
		print(self.inventory.product)
		print(self.inventory.quantity)

# OK

>>> i = Inventory()
>>> c = ConsoleObserver(i)
>>> i.attach(c)
>>> i.product = "Widget"
Widget
0
>>> i.quantity = 5
Widget
5

# OK after attaching the observer to the inventory object, whenever we change one of the two observed properties, the observer is called and its action is invoked.

>>> i = Inventory()
>>> c1 = ConsoleObserver(i)
>>> c2 = ConsoleObserver(i)
>>> i.attach(c1)
>>> i.attach(c2)
>>> i.product = "Gadget"
Gadget
0
Gadget
0

# OK we can easily add totally different types of observers that back up the data in a file, database, or internet application at the same time.

# Strategy Pattern

# Typically, different algorithms have different trade-offs; one might be faster than another, but uses a lot more memory, while a third algorithm may be most suitable when multiple CPUs are present or a distributed system is provided. Here is the strategy pattern in UML:

# Strategy Example

# OK canonical example of the strategy pattern is sort routines; over the years, numerous algorithms have been invented for sorting a collection of objects; quick sort, merge sort, and heap sort all fast sort algorithms with different features, each useful in its own right, depending on the size and type of inputs, how out of order they are, and the requirements of the system.

from pygame import image
from pygame.transform import scale
from pygame import Surface

class TiledStrategy:
	def make_background(self, img_file, desktop_size):
		in_img = image.load(img_file)
		out_img = Surface(desktop_size)
		for x in range((out_img.get_width(
			) // in_img.get_width()) + 1):
			for y in range((out_img.get_height(
				) // in_img.get_height()) + 1):
				out_img.blit(in_img, (in_img.get_width() * x,
					in_img.get_height() * y))
		return out_img

class CenteredStrategy:
	def make_background(self, img_file, desktop_size):
		in_img = image.load(img_file)
		out_img = Surface(desktop_size)
		out_img.fill((0,0,0))
		left = (out_img.get_width() - in_img.get_width()) / 2
		top = (out_img.get_height() - in_img.get_height()) / 2
		out_img.blit(in_img, (left, top))
		return out_img

class ScaledStrategy:
	def make_background(self, img_file, desktop_size):
		in_img = image.load(img_file)
		return scale(in_img, desktop_size)

# OK

# Strategy In Python

# OK

# State Pattern

# OK

# State Example

<book>
	<author>Dusty Phillips</author>
	<publisher>Packt Publishing</publisher>
	<title>Python 3 Object Oriented Programming</title>
	<content>
		<chapter>
			<number>1</number>
			<title>Object Oriented Design</title>
		</chapter>
		<chapter>
			<number>2</number>
			<title>Objects In Python</title>
		</chapter>
	</content>
</book>

# OK

class Node:
	def __init__(self, tag_name, parent=None):
		self.parent = parent
		self.tag_name = tag_name
		self.children = []
		self.text=""

	def __str__(self):
		if self.text:
			return self.tag_name + ": " + self.text
		else:
			return self.tag_name

# Switching states can be tricky; how do we know if the next node is an opening tag, a closing tag, or a text node? We could put a little logique in each state to work that out, but it actually makes more sense to create a new state we'll be switching to next.

class Parser:
	def __init__(self, parse_string):
		self.parse_string = parse_string
		self.root = None
		self.current_node = None
		self.state = FirstTag()

	def process(self, remaining_string):
		remaining = self.state.process(remaining_string, self)
		if remaining:
			self.process(remaining)

	def start(self):
		self.process(self.parse_string)

# OK

class FirstTag:
	def process(self, remaining_string, parser):
		i_start_tag = remaining_string.find('<')
		i_end_tag = remaining_string.find('>')
		tag_name = remaining_string[i_start_tag+1:i_end_tag]
		root = Node(tag_name)
		parser.root = parser.current_node = root
		parser.state = ChildNode()
		return remaining_string[i_end_tag+1:]

# OK

class ChildNode:
	def process(self, remaining_string, parser):
		stripped = remaining_string.strip()
		if stripped.startswith("</"):
			parser.state = CloseTag()
		elif stripped.startswith("<"):
			parser.state = OpenTag()
		else:
			parser.state = TextNode()
	return stripped

# OK

class OpenTag:
	def process(self, remaining_string, parser):
		i_start_tag = remaining_string.find('<')
		i_end_tag = remaining_string.find('>')
		tag_name = remaining_string[i_start_tag+1:i_end_tag]
		node = Node(tag_name, parser.current_node)
		parser.current_node.children.append(node)
		parser.current_node = node
		parser.state = ChildNode()
		return remaining_string[i_end_tag+1:]

# OK

class CloseTag:
	def process(self, remaining_string, parser):
		i_start_tag = remaining_string.find('<')
		i_end_tag = remaining_string.find('>')
		assert remaining_string[i_start_tag+1] == "/"
		tag_name = remaining_string[i_start_tag+2:i_end_tag]
		assert tag_name == parser.current_node.tag_name
		parser.current_node = parser.current_node.parent
		parser.state = ChildNode()
		return remaining_string[i_end_tag+1:].strip()

# OK

class TextNode:
	def process(self, remaining_string, parser):
		i_start_tag = remaining_string.find('<')
		text = remaining_string[:i_start_tag]
		parser.current_node.text = text
		parser.state = ChildNode()
		return remaining_string[i_start_tag:]

# Set up the initial state on the parser object we created.

self.state = FirstTag()

# OK test the class.

if __name__ == "__main__":
	import sys
	with open(sys.argv[1]) as file:
		contents = file.read()
		p = Parser(contents)
		p.start()

		nodes = [p.root]
		while nodes:
			node = nodes.pop(0)
			print(node)
			nodes = node.children + nodes

# OK

book
author: Dusty Phillips
publisher: Packt Publishing
title: Python 3 Object Oriented Programming
content
chapter
number: 1
title: Object Oriented Design
chapter
number: 2
title: Objects In Python

# OK

# State Versus Strategy

# State pattern looks very similar to strategy pattern, indeed the UML diagrams for the two are identical.

# Singleton Pattern

# One of the most controversial patterns apparently many have accused it of being an anti-pattern; a pattern that should be avoided, not promoted.

# Singleton Implementation

class OneOnly:
	_singleton = None
	def __new__(cls, *args, **kwargs):
		if not cls._singleton:
			cls._singleton = super(OneOnly, cls
				).__new__(cls, *args, **kwargs)
		return cls._singleton

# OK

>>> o1 = OneOnly()
>>> o2 = OneOnly()
>>> o1 == o2
True
>>> o1
<__main__.OneOnly object at 0xb71c008c>
>>> o2
<__main__.OneOnly object at 0xb71c008c>

# OK

# Module Variables Can Mimic Singletons

class FirstTag:
	def process(self, remaining_string, parser):
		i_start_tag = remaining_string.find('<')
		i_end_tag = remaining_string.find('>')
		tag_name = remaining_string[i_start_tag+1:i_end_tag]
		root = Node(tag_name)
		parser.root = parser.current_node = root
		parser.state = child_node
		return remaining_string[i_end_tag+1:]

class ChildNode:
	def process(self, remaining_string, parser):
		stripped = remaining_string.strip()
		if stripped.startswith("</"):
			parser.state = close_tag
		elif stripped.startswith("<"):
			parser.state = open_tag
		else:
			parser.state = text_node
		return stripped

class OpenTag:
	def process(self, remaining_string, parser):
		i_start_tag = remaining_string.find('<')
		i_end_tag = remaining_string.find('>')
		tag_name = remaining_string[i_start_tag+1:i_end_tag]
		node = Node(tag_name, parser.current_node)
		parser.current_node.children.append(node)
		parser.current_node = node
		parser.state = child_node
		return remaining_string[i_end_tag+1:]

class TextNode:
	def process(self, remaining_string, parser):
		i_start_tag = remaining_string.find('<')
		text = remaining_string[:i_start_tag]
		parser.current_node.text = text
		parser.state = child_node
		return remaining_string[i_start_tag:]

class CloseTag:
	def process(self, remaining_string, parser):
		i_start_tag = remaining_string.find('<')
		i_end_tag = remaining_string.find('>')
		assert remaining_string[i_start_tag+1] == "/"
		tag_name = remaining_string[i_start_tag+2:i_end_tag]
		assert tag_name == parser.current_node.tag_name
		parser.current_node = parser.current_node.parent
		parser.state = child_node
		return remaining_string[i_end_tag+1:].strip()

first_tag = FirstTag()
child_node = ChildNode()
text_node = TextNode()
open_tag = OpenTag()
close_tag = CloseTag()

# Template Pattern

# Template Example

# OK create a car sales reporter as an example. We can store records of sales in an SQLite database table.

# We have two common tasks we need to perform:

# Select all sales of new vehicles and output them to the screen in a commadelimited format

# Output a comma-delimited list of all salespeople with their gross sales and save it to a file that can be imported to a spreadsheet

# These seem like quite different tasks, but they have some common features. In both cases, we need to perform the following steps:

# 1. Connect to the database.
# 2. Construct a query for new vehicles or gross sales.
# 3. Issue the query.
# 4. Format the results into a comma-delimited string.
# 5. Output the data to a file or e-mail

import sqlite3
conn = sqlite3.connect("sales.db")
conn.execute("CREATE TABLE Sales (salesperson text, "
	"amt currency, year integer, model text, new boolean)")
conn.execute("INSERT INTO Sales values"
	" ('Tim', 16000, 2010, 'Honda Fit', 'true')")
conn.execute("INSERT INTO Sales values"
	" ('Tim', 9000, 2006, 'Ford Focus', 'false')")
conn.execute("INSERT INTO Sales values"
	" ('Gayle', 8000, 2004, 'Dodge Neon', 'false')")
conn.execute("INSERT INTO Sales values"
	" ('Gayle', 28000, 2009, 'Ford Mustang', 'true')")
conn.execute("INSERT INTO Sales values"
	" ('Gayle', 50000, 2010, 'Lincoln Navigator', 'true')")
conn.execute("INSERT INTO Sales values"
	" ('Don', 20000, 2008, 'Toyota Prius', 'false')")
conn.commit()
conn.close()

# OK

class QueryTemplate:
	def connect(self):
		pass

	def construct_query(self):
		pass

	def do_query(self):
		pass

	def format_results(self):
		pass

	def output_results(self):
		pass

	def process_format(self):
		self.connect()
		self.construct_query()
		self.do_query()
		self.format_results()
		self.output_results()

# OK

import sqlite3

class QueryTemplate:
	def connect(self):
		self.conn = sqlite3.connect("sales.db")

	def construct_query(self):
		raise NotImplementedError()

	def do_query(self):
		results = self.conn.execute(self.query)
		self.results = results.fetchall()

	def format_results(self):
		output = []
		for row in self.results:
			row =[str(i) for i in row]
			output.append(", ".join(row))
		self.formatted_results = "\n".join(output)

	def output_results(self):
		raise NotImplementedError()

# OK OK NotImplementedError

import datetime

class NewVehiclesQuery(QueryTemplate):
	def construct_query(self):
		self.query = "select * from Sales where new='true'"

	def output_results(self):
		print(self.formatted_results)

class UserGrossQuery(QueryTemplate):
	def construct_query(self):
		self.query = ("select salesperson, sum(amt) " +
		" from Sales group by salesperson")

	def output_results(self):
		filename = "gross_sales_{0}".format(
				datetime.date.today().strftime("%Y%m%d")
				)
		with open(filename, 'w') as outfile:
			outfile.write(self.formatted_results)

# Exercises

# OK

# Summary

# In this chapter, we learned that design patterns are useful abstractions that provide "best practice" solutions for common programming problems. We understood that design patterns in Python, due to its dynamic nature and built-in syntax, can look very different from their usual renditions in other languages. We discussed several patterns in detail, with examples, UML diagrams and a discussion of the differences between Python and statically typed object-oriented languages. We covered:

# What Design Patterns Are
# The Iterator Pattern
# The Decorator Pattern
# The Observer Pattern
# The Strategy And State Patterns
# The Template Pattern

# In the next chapter, we'll discuss several more useful design patterns and their application in Python.

# Python Design Patterns II

# This chapter carries on from the previous chapter by introducing several more design patterns. Once again, we'll cover the canonical examples as well as any common alternative implementations in Python. We'll be discussing:

# The Adapter Pattern
# The Facade Pattern
# Lazy Initialisation And The Flyweight Pattern
# The Command Pattern
# The Abstract Factory Pattern
# The Composition Pattern

# Adapter Pattern

# OK

class AgeCalculator:
	def __init__(self, birthday):
		self.year, self.month, self.day = (
		int(x) for x in birthday.split('-'))

	def calculate_age(self, date):
		year, month, day = (
				int(x) for x in date.split('-'))
		age = year - self.year
		if (month,day) < (self.month,self.day):
			age -= 1
		return age

# OK

# Can write an adapter that allows a normal date to be plugged into a normal AgeCalculator:

import datetime
class DateAgeAdapter:
	def _str_date(self, date):
		return date.strftime("%Y-%m-%d")

	def __init__(self, birthday):
		birthday = self._str_date(birthday)
		self.calculator = AgeCalculator(birthday)

	def get_age(self, date):
		date = self._str_date(date)
		return self.calculator.calculate_age(date)

# OK

import datetime
class AgeableDate(datetime.date):
	def split(self, char):
		return self.year, self.month, self.d

# OK

>>> bd = AgeableDate(1975, 6, 14)
>>> today = AgeableDate.today()
>>> today
AgeableDate(2010, 2, 23)
>>> a = AgeCalculator(bd)
>>> a.calculate_age(today)
34

# OK OK OK instead of inheritance, the so called monkey patching.

# Facade Pattern

import smtplib
import imaplib
class EmailFacade:
	def __init__(self, host, username, password):
		self.host = host
		self.username = username
		self.password = password

# OK

def send_email(self, to_email, subject, message):
	if not "@" in username:
		from_email = "{0}@{1}".format(
				self.username, self.host)
	else:
		from_email = self.username
	message = ("From: {0}\r\n"
			"To: {1}\r\n"
			"Subject: {2}\r\n\r\n{3}").format(
				from_email,
				to_email,
				subject,
				message)

smtp = smtplib.SMTP(self.host)
smtp.login(self.username, self.password)
smtp.sendmail(from_email, [to_email], message)

# OK

def get_inbox(self):
	mailbox = imaplib.IMAP4(self.host)
	mailbox.login(bytes(self.username, 'utf8'),
		bytes(self.password, 'utf8'))
	mailbox.select()
	x, data = mailbox.search(None, 'ALL')
	messages = []
	for num in data[0].split():
		x, message = mailbox.fetch(num, '(RFC822)')
		messages.append(message[0][1])
	return messages

# OK

# Flyweight Pattern

import weakref

class CarModel:
	_models = weakref.WeakValueDictionary()

	def __new__(cls, model_name, *args, **kwargs):
		model = cls._models.get(model_name)
		if not model:
			model = super().__new__(cls)
			cls._models[model_name] = model
		return model

# OK

def __init__(self, model_name, air=False, tilt=False,
		cruise_control=False, power_locks=False,
		alloy_wheels=False, usb_charger=False):
	if not hasattr(self, "initted"):
		self.model_name = model_name
		self.air = air
		self.tilt = tilt
		self.cruise_control = cruise_control
		self.power_locks = power_locks
		self.alloy_wheels = alloy_wheels
		self.usb_charger = usb_charger
		self.initted=True

# OK

def check_serial(self, serial_number):
	print("Sorry, we are unable to check "
			"the serial number {0} on the {1} "
			"at this time".format(
				serial_number, self.model_name))

# OK

class Car:
	def __init__(self, model, color, serial):
		self.model = model
		self.color = color
		self.serial = serial

	def check_serial(self):
		return self.model.check_serial(self.serial)

# OK

>>> dx = CarModel("FIT DX")
>>> lx = CarModel("FIT LX", air=True, cruise_control=True,
... power_locks=True, tilt=True)
>>> car1 = Car(dx, "blue", "12345")
>>> car2 = Car(dx, "black", "12346")
>>> car3 = Car(lx, "red", "12347")

# OK

>>> id(lx)
3071620300
>>> del lx
>>> del car3
>>> import gc
>>> gc.collect()
0
>>> lx = CarModel("FIT LX", air=True, cruise_control=True,
... power_locks=True, tilt=True)
>>> id(lx)
3071576140
>>> lx = CarModel("FIT LX")
>>> id(lx)
3071576140
>>> lx.air
True

# OK

# Command Pattern

import sys

class Window:
	def exit(self):
		sys.exit(0)

class Document:
	def __init__(self, filename):
		self.filename = filename
		self.contents = "This file cannot be modified"
	def save(self):
		with open(self.filename, 'w') as file:
			file.write(self.contents)

# OK

class ToolbarButton:
	def __init__(self, name, iconname):
		self.name = name
		self.iconname = iconname

	def click(self):
		self.command.execute()

class MenuItem:
	def __init__(self, menu_name, menuitem_name):
		self.menu = menu_name
		self.item = menuitem_name

	def click(self):
		self.command.execute()

class KeyboardShortcut:
	def __init__(self, key, modifier):
		self.key = key
		self.modifier = modifier

	def keypress(self):
		self.command.execute()

# OK

class SaveCommand:
	def __init__(self, document):
		self.document = document

	def execute(self):
		self.document.save()

class ExitCommand:
	def __init__(self, window):
		self.window = window

	def execute(self):
		self.window.exit()

# OK

window = Window()
document = Document("a_document.txt")
save = SaveCommand(document)
exit = ExitCommand(window)

save_button = ToolbarButton('save', 'save.png')
save_button.command = save
save_keystroke = KeyboardShortcut("s", "ctrl")
save_keystroke.command = save
exit_menu = MenuItem("File", "Exit")
exit_menu.command = exit

# OK

import sys

class Window:
	def exit(self):
		sys.exit(0)

class MenuItem:
	def click(self):
		self.command()

window = Window()
menu_item = MenuItem()
menu_item.command = window.exit

# OK

class Document:
	def __init__(self, filename):
		self.filename = filename
		self.contents = "This file cannot be modified"

	def save(self):
		with open(self.filename, 'w') as file:
			file.write(self.contents)

	class KeyboardShortcut:
		def keypress(self):
			self.command()

	class SaveCommand:
		def __init__(self, document):
			self.document = document

		def __call__(self):
			self.document.save()

document = Document("a_file.txt")
shortcut = KeyboardShortcut()
save_command = SaveCommand(document)
shortcut.command = save_command

# Abstract Factory Pattern

class FranceDateFormatter:
	def format_date(self, y, m, d):
		y, m, d = (str(x) for x in (y,m,d))
		y = '20' + y if len(y) == 2 else y
		m = '0' + m if len(m) == 1 else m
		d = '0' + d if len(d) == 1 else d
		return("{0}/{1}/{2}".format(d,m,y))

class USADateFormatter:
	def format_date(self, y, m, d):
		y, m, d = (str(x) for x in (y,m,d))
		y = '20' + y if len(y) == 2 else y
		m = '0' + m if len(m) == 1 else m
		d = '0' + d if len(d) == 1 else d
		return("{0}-{1}-{2}".format(m,d,y))

class FranceCurrencyFormatter:
	def format_currency(self, base, cents):
		base, cents = (str(x) for x in (base, cents))
		if len(cents) == 0:
			cents = '00'
		elif len(cents) == 1:
			cents = '0' + cents

		digits = []
		for i,c in enumerate(reversed(base)):
			if i and not i % 3:
				digits.append(' ')
			digits.append(c)
		base = ''.join(reversed(digits))
		return "{0}€{1}".format(base, cents)

class USACurrencyFormatter:
	def format_currency(self, base, cents):
		base, cents = (str(x) for x in (base, cents))
		if len(cents) == 0:
			cents = '00'
		elif len(cents) == 1:
			cents = '0' + cents
		digits = []
		for i,c in enumerate(reversed(base)):
			if i and not i % 3:
				digits.append(',')
			digits.append(c)
		base = ''.join(reversed(digits))
		return "${0}.{1}".format(base, cents)

# OK

class USAFormatterFactory:
	def create_date_formatter(self):
		return USADateFormatter()

	def create_currency_formatter(self):
		return USACurrencyFormatter()

class FranceFormatterFactory:
	def create_date_formatter(self):
		return FranceDateFormatter()

	def create_currency_formatter(self):
		return FranceCurrencyFormatter()

# OK

country_code = "US"
factory_map = {
		"US": USAFormatterFactory,
		"FR": FranceFormatterFactory}
formatter_factory = factory_map.get(country_code)()

# OK

localize/
	__init__.py
	backends/
			__init__.py
			USA.py
			France.py
			...

# OK

from .backends import USA, France

if country_code == "US":
	current_backend = USA

# OK

# Composite Pattern

class Folder:
	def __init__(self, name):
		self.name = name
		self.children = {}

	def add_child(self, child):
		pass

	def move(self, new_path):
		pass

	def copy(self, new_path):
		pass

	def delete(self):
		pass

class File:
	def __init__(self, name, contents):
		self.name = name
		self.contents = contents

	def move(self, new_path):
		pass

	def copy(self, new_path):
		pass

	def delete(self):
		pass

# OK

class Component:
	def __init__(self, name):
		self.name = name

	def move(self, new_path):
		new_folder =get_path(new_path)
		del self.parent.children[self.name]
		new_folder.children[self.name] = self
		self.parent = new_folder

	def delete(self):
		del self.parent.children[self.name]

class Folder(Component):
	def __init__(self, name):
		super().__init__(name)
		self.children = {}

	def add_child(self, child):
		pass

	def copy(self, new_path):
		pass

class File(Component):
	def __init__(self, name, contents):
		super().__init__(name)
		self.contents = contents

	def copy(self, new_path):
		pass

root = Folder('')

def get_path(path):
	names = path.split('/')[1:]
	node = root
	for name in names:
		node = node.children[name]
	return node

# OK

def add_child(self, child):
	child.parent = self
	self.children[child.name] = child

# OK

$ python3 -i 1261_09_18_add_child.py

>>> folder1 = Folder('folder1')
>>> folder2 = Folder('folder2')
>>> root.add_child(folder1)
>>> root.add_child(folder2)
>>> folder11 = Folder('folder11')
>>> folder1.add_child(folder11)
>>> file111 = File('file111', 'contents')
>>> folder11.add_child(file111)
>>> file21 = File('file21', 'other contents')
>>> folder2.add_child(file21)
>>> folder2.children
{'file21': <__main__.File object at 0xb7220a4c>}
>>> folder2.move('/folder1/folder11')
>>> folder11.children
{'folder2': <__main__.Folder object at 0xb722080c>, 'file111': <__main__
.File object at 0xb72209ec>}
>>> file21.move('/folder1')
>>> folder1.children
{'file21': <__main__.File object at 0xb7220a4c>, 'folder11': <__main__
.Folder object at 0xb722084c>}
>>> 

# OK

# Exercises

# OK

# OK implement the copy method for the File and Folder objects in the previous section. The File method should be quite trivial. Righto.

# Whatever bro.

# Summary

# In this chapter, we went into detail on several more design patterns, covering their canonical descriptions as well as alternatives for implementing them in Python, which is often more flexible and versatile than traditional object-oriented languages. In particular, we covered:

# The adapter pattern for matching interfaces.
# The facade pattern for simplifying complex systems.
# The flyweight pattern for reducing memory consumption.
# The command pattern for isolating invokers.
# The abstract factory pattern for separating implementation.
# The composition pattern for tree-like structures.

# In the next chapter, we'll cover some of the common tools for manipulating files, configuration, and processes.

# Files And Strings

# Ah this is terribly important let us get it. ESSKEETIT. I love me some files and some strings. Especially strings in English those are my favourite strings. Might need to post up a massive Mandarin English dictionary here in .txt soon so that everyone knows I can mem it.

# Let's take a step back from the higher-level patterns now, and cover several Python constructs we've used in all our examples, but without any details. We'll be looking at files, Input Output, and serializing and loading data. Along the way, we'll find out how complicated Python's excessively simple strings really are. In particular, we'll see:

# The complexities of strings, bytes, and byte array.
# The ins and outs of string formatting.
# How to open files.
# Context managers.
# A few ways to serialise data.

# Strings

# OK Unicode yeah yeah yeah. Immutable.

# String Manipulation

# I will remember it... Zarathustra lmao of course we remember the things we see sometimes.

# OK a variety of ways to do strings.

a = "hello"
b = 'world'
c = '''a multiple
line string'''
d = """More
multiple"""
e = ("Three " "Strings "
	"Together")

# OK

# OK some like builtin Boolean methods which maybe have good solid performant underlying implementations one assumes, hopes, supposes.

>>> s = "hello world"
>>> s.startswith('hi')
False
>>> s.endswith('ld')
True
>>> s.find('l')
2
>>> s.index('m')
Traceback (most recent call last):
	File "<stdin>", line 1, in <module>
ValueError: substring not found
>>>

# OK

>>> s = "hello world, how are you"
>>> s2 = s.split(' ')
>>> s2
['hello', 'world,', 'how', 'are', 'you']
>>> '#'.join(s2)
'hello#world,#how#are#you'
>>> s.replace(' ', '**')
'hello**world,**how**are**you'
>>> s.partition(' ')
('hello', ' ', 'world, how are you')

# OK

# String Formatting

template = "Hello {}, you are currently {}."
print(template.format('Dusty', 'writing'))

# OK

Hello Dusty, you are currently writing.

# OK

template = "Hello {0}, you are {1}. Your name is {0}."
print(template.format('Dusty', 'writing'))

# OK

template = "Hello {}, you are {}. Your name is {0}."
print(template.format('Dusty', 'writing'))

# OK

Traceback (most recent call last):
	File "1261_10_04_format_some_positions_broken.py", line 2, in
<module>
	print(template.format('Dusty', 'writing'))
ValueError: cannot switch from automatic field numbering to manual
field specification

# Escaping Braces

template = """
public class {0} {{
	public static void main(String[] args) {{
		System.out.println({1});
	}}
}}"""

print(template.format("MyClass", "print('hello world')"));

# OK

public class MyClass {
	public static void main(String[] args) {
		System.out.println("print('hello world')");
	}
}

# Keyword Arguments

template = """
From: <{from_email}>
To: <{to_email}>
Subject: {subject}
{message}"""
print(template.format(
	from_email = "a@example.com",
	to_email = "b@example.com",
	message = "Here's some mail for you. "
	" Hope you enjoy the message!",
	subject = "You have mail!"
	))

# OK

print("{} {label} {}".format("x", "y", label="z"))

# OK

x z y

# OK

# Container Lookups

emails = ("a@example.com", "b@example.com")
message = {
	'subject': "You Have Mail!",
	'message': "Here's some mail for you!"
	}
template = """
From: <{0[0]}>
To: <{0[1]}>
Subject: {message[subject]}
{message[message]}"""
print(template.format(emails, message=message))

# OK

# OK

emails = ("a@example.com", "b@example.com")
message = {
	'emails': emails,
	'subject': "You Have Mail!",
	'message': "Here's some mail for you!"
	}
template = """
From: <{0[emails][0]}>
To: <{0[emails][1]}>
Subject: {0[subject]}
{0[message]}"""
print(template.format(message))

# Object Lookups

class EMail:
	def __init__(self, from_addr, to_addr, subject, message):
		self.from_addr = from_addr
		self.to_addr = to_addr
		self.subject = subject
		self.message = message
email = EMail("a@example.com", "b@example.com",
		"You Have Mail!",
		"Here's some mail for you!")
template = """
From: <{0.from_addr}>
To: <{0.to_addr}>
Subject: {0.subject}
{0.message}"""
print(template.format(email))

# Making It Look Right

subtotal = 12.32
tax = subtotal * 0.07
total = subtotal + tax

print("Sub: ${0} Tax: ${1} Total: ${total}".format(
	subtotal, tax, total=total))

# OK

Sub: $12.32 Tax: $0.8624 Total: $13.1824

# OK

subtotal = 12.32
tax = subtotal * 0.07
total = subtotal + tax

print("Sub: ${0:0.2f} Tax: ${1:0.2f} "
	"Total: ${total:0.2f}".format(
	subtotal, tax, total=total))

# OK

orders = [('burger', 2, 5),
	('fries', 3.5, 1),
	('cola', 1.75, 3)]
print("PRODUCT QUANTITY PRICE SUBTOTAL")
for product, price, quantity in orders:
	subtotal = price * quantity
	print("{0:10s}{1: ^9d} ${2: <8.2f}${3: >7.2f}".format(
		product, quantity, price, subtotal))

# OK

PRODUCT QUANTITY PRICE SUBTOTAL
burger 5 $2.00 $ 10.00
fries 1 $3.50 $ 3.50
cola 3 $1.75 $ 5.25

# OK

# After this maybe hop back in to the mix with that large Github Python Machine Learning Trading repository was an OK solid review of observations to be made. And then on to the C++ parallel work.

import datetime
print("{0:%Y-%m-%d %I:%M%p }".format(
	datetime.datetime.now()))

# OK

# Strings Are Unicode

# OK yeah yeah yeah.

# Converting Bytes To Text

characters = b'\x63\x6c\x69\x63\x68\xe9'
print(characters)
print(characters.decode("latin-1"))

# OK

b'clich\xe9'
cliché

# Converting Text To Bytes

characters = "cliché"
print(characters.encode("UTF-8"))
print(characters.encode("latin-1"))
print(characters.encode("CP437"))
print(characters.encode("ascii"))

# OK

b'clich\xc3\xa9'
b'clich\xe9'
b'clich\x82'
Traceback (most recent call last):
	File "1261_10_16_decode_unicode.py", line 5, in <module>
		print(characters.encode("ascii"))
UnicodeEncodeError: 'ascii' codec can't encode character '\xe9' in
position 5: ordinal not in range(128)

# OK

# strict
# replace
# ignore
# xmlcharrefreplace

# OK

# Strategy "cliché".encode("ascii", strategy)
# replace b'clich?'
# ignore b'clich'
# xmlcharrefreplace b'clich&#233

# Mutable Byte Strings

b = bytearray(b"abcdefgh")
b[4:6] = b"\x15\xa3"
print(b)

# OK

b = bytearray(b'abcdef')
b[3] = ord(b'g')
b[4] = 68
print(b)

# File Input Output

file = open('filename', encoding='ascii', errors='replace')
print(file.read())
file.close()

# OK

contents = "an oft-repeated cliché"
file = open("filename", "w", encoding="ascii", errors="replace")
file.write(contents)
file.close()

# OK

# Placing It In Context

with open('filename') as file:
	for line in file:
		print(line, end='')

# OK

class StringJoiner(list):
	def __enter__(self):
		return self

	def __exit__(self, type, value, tb):
		self.result = "".join(self)

# OK

import random, string
with StringJoiner() as joiner:
	for i in range(15):
		joiner.append(random.choice(string.ascii_letters))
print(joiner.result)

# OK

# Faking Files

# OKOKOK

# coding=utf-8
from io import StringIO, BytesIO
source_file = StringIO("an oft-repeated cliché")
dest_file = BytesIO()

char = source_file.read(1)
while char:
	dest_file.write(char.encode("ascii", "replace"))
	char = source_file.read(1)
print(dest_file.getvalue())

# OK

# Storing Objects

import pickle

some_data = ["a list", "containing", 5,
		"values including another list",
		["inner", "list"]]

with open("pickled_list", 'wb') as file:
	pickle.dump(some_data, file)

with open("pickled_list", 'rb') as file:
	loaded_data = pickle.load(file)

print(loaded_data)
assert loaded_data == some_data

# OK

# Customizing Pickles

from threading import Timer
import datetime
from urllib.request import urlopen

class UpdatedURL:
	def __init__(self, url):
		self.url = url
		self.contents = ''
		self.last_updated = None
		self.update()

	def update(self):
		self.contents = urlopen(self.url).read()
		self.last_updated = datetime.datetime.now()
		self.schedule()

	def schedule(self):
		self.timer = Timer(3600, self.update)
		self.timer.setDaemon(True)
		self.timer.start()

# OK

>>> u = UpdatedURL("http://news.yahoo.com/")
>>> import pickle
>>> serialized = pickle.dumps(u)
Traceback (most recent call last):
	File "<stdin>", line 1, in <module>
	File "/usr/lib/python3.1/pickle.py", line 1358, in dumps
		Pickler(f, protocol, fix_imports=fix_imports).dump(obj)
_pickle.PicklingError: Can't pickle <class 'method'>:
attribute lookup builtins.method failed

# OK

def __getstate__(self):
	new_state = self.__dict__.copy()
	if 'timer' in new_state:
		del new_state['timer']
	return new_state

# OK

def __setstate__(self, data):
	self.__dict__ = data
	self.schedule()

# OK

# Serialising Web Objects

# JavaScript Object Notation [JSON]

class Contact:
	def __init__(self, first, last):
		self.first = first
		self.last = last

	@property
	def full_name(self):
		return("{} {}".format(self.first, self.last))

# OK

>>> c = Contact("John", "Smith")
>>> json.dumps(c.__dict__)
'{"last": "Smith", "first": "John"}'

# OK

import json
class ContactEncoder(json.JSONEncoder):
	def default(self, obj):
		if isinstance(obj, Contact):
			return {'is_contact': True,
				'first': obj.first,
				'last': obj.last,
				'full': obj.full_name}
		return super().default(obj)

# OK

>>> c = Contact("John", "Smith")
>>> json.dumps(c, cls=ContactEncoder)
'{"is_contact": true, "last": "Smith", "full": "John Smith",
"first": "John"}'

# OK

def decode_contact(dic):
		if dic.get('is_contact'):
			return Contact(dic['first'], dic['last'])
		else:
			return dic

# OK

>>> data = '{"is_contact": true, "last": "smith",
		"full": "john smith", "first": "john"}'
>>> c = json.loads(data, object_hook=decode_contact)
>>> c
<__main__.Contact object at 0xa02918c>
>>> c.full_name
'john smith'

# Exercises

# Summary

# We've covered string manipulation, file IO, and object serialization. We discussed how to combine hard-coded strings and program variables into outputtable strings using the powerful string formatting system, and learned the difference between binary and textual data. All told, we've seen:

# How to use the various str methods
# String formatting
# bytes versus str
# Mutable bytearrays
# Files in binary and textual formatters
# Context managers and the with statement
# Serializing data with pickle and json

# In the next chapter, we'll cover one of the most important topics in Python programming: how to test our code to ensure it's doing what we think it is doing.

# Testing Object-oriented Programs

# Most skilled Python programmers agree that testing is one of the most important aspects of software development in Python. Even though this chapter is placed near the end of the book, it is not an afterthought; everything we have studied so far will help us when writing tests. We'll be studying:

# The importance of unit testing and test-driven development.
# The standard unittest module.
# The py.test automated testing suite.
# Code coverage.

# Why test?

# OK duh need to test or do actual hard core verification.

# We write automated tests.

# There are 4 main reasons to write tests:

# To ensure that code is working the way the developer thinks it should.
# To ensure that code continues working when we make changes.
# To ensure the developer understood the requirements.
# To ensure that the code we are writing has a maintainable interface.

# OK

# Test-Driven Development

# OKOKOK testing makes software better no poo.

# Unit Testing

import unittest

class CheckNumbers(unittest.TestCase):
	def test_int_float(self):
		self.assertEquals(1, 1.0)

if __name__ == "__main__":
	unittest.main()

# OK


--------------------------------------------------------------
Ran 1 test in 0.000s
OK

# OK

def test_str_float(self):
	self.assertEquals(1, "1")

# OK

.F
============================================================
FAIL: test_str_float (__main__.CheckNumbers)
--------------------------------------------------------------
Traceback (most recent call last):
 File "simplest_unittest.py", line 8, in test_str_float
 self.assertEquals(1, "1")
AssertionError: 1 != '1'
--------------------------------------------------------------
Ran 2 tests in 0.001s
FAILED (failures=1)

# OK

# Assertion Methods

# Additional Assertion Methods In Python 3.1

import unittest

def average(seq):
	return sum(seq) / len(seq)

class TestAverage(unittest.TestCase):
	def test_python30_zero(self):
		self.assertRaises(ZeroDivisionError,
				average,
				[])

	def test_python31_zero(self):
		with self.assertRaises(ZeroDivisionError):
			average([])

if __name__ == "__main__":
	unittest.main()

# OKOKOK

# Reducing Boilerplate And Cleaning Up

from collections import defaultdict

class StatsList(list):
	def mean(self):
		return sum(self) / len(self)

	def median(self):
		if len(self) % 2:
			return self[int(len(self) / 2)]
		else:
			idx = int(len(self) / 2)
			return (self[idx] + self[idx-1]) / 2

	def mode(self):
		freqs = defaultdict(int)
		for item in self:
			freqs[item] += 1
		mode_freq = max(freqs.values())
		modes = []
		for item, value in freqs.items():
			if value == mode_freq:
				modes.append(item)
		return modes

# OK

from stats import StatsList
import unittest

class TestValidInputs(unittest.TestCase):
	def setUp(self):
		self.stats = StatsList([1,2,2,3,3,4])

	def test_mean(self):
		self.assertEqual(self.stats.mean(), 2.5)

	def test_median(self):
		self.assertEqual(self.stats.median(), 2.5)
		self.stats.append(4)
		self.assertEqual(self.stats.median(), 3)

	def test_mode(self):
		self.assertEqual(self.stats.mode(), [2,3])
		self.stats.remove(2)
		self.assertEqual(self.stats.mode(), [3])

if __name__ == "__main__":
	unittest.main()

# OK

# Organising And Running Tests

# Python 3.1 or earlier: python3 -m discover.
# Python 3.2 or later: python3 -m unittest discover.

# Ignoring Broken Tests

# These decorators are:

# expectedFailure()
# skip(reason)
# skipIf(condition, reason)
# skipUnless(condition, reason)

# OK

import unittest
import sys

class SkipTests(unittest.TestCase):
	@unittest.expectedFailure
	def test_fails(self):
		self.assertEqual(False, True)

	@unittest.skip("Test is useless")
	def test_skip(self):
		self.assertEqual(False, True)

	@unittest.skipIf(sys.version_info.minor == 1,
			"broken on 3.1")
	def test_skipif(self):
		self.assertEqual(False, True)

	@unittest.skipUnless(sys.platform.startswith('linux'),
			"broken on linux")
	def test_skipunless(self):
		self.assertEqual(False, True)

if __name__ == "__main__":
	unittest.main()

# OK

xssF
=============================================================
FAIL: test_skipunless (__main__.SkipTests)
--------------------------------------------------------------
Traceback (most recent call last):
 File "skipping_tests.py", line 21, in test_skipunless
 self.assertEqual(False, True)
AssertionError: False != True
--------------------------------------------------------------
Ran 4 tests in 0.001s
FAILED (failures=1, skipped=2, expected failures=1)

# Testing With py.test

# So let's take the simplest possible unittest example we wrote earlier and port it to py.test:

def test_int_float():
	assert 1 == 1.0

# OK

class TestNumbers:
	def test_int_float(self):
		assert 1 == 1.0

	def test_int_str(self):
		assert 1 == "1"

# OK

============== test session starts ==============
python: platform linux2 -- Python 3.1.2 -- pytest-1.2.1
test object 1: class_pytest.py
class_pytest.py .F
=================== FAILURES====================
___________ TestNumbers.test_int_str ____________
self = <class_pytest.TestNumbers object at 0x85b4fac>
 def test_int_str(self):
> assert 1 == "1"
E assert 1 == '1'
class_pytest.py:7: AssertionError
====== 1 failed, 1 passed in 0.10 seconds =======

# OK

# One Way To Do Setup And Cleanup

def setup_module(module):
	print("setting up MODULE {0}".format(
		module.__name__))

def teardown_module(module):
	print("tearing down MODULE {0}".format(
		module.__name__))

def test_a_function():
	print("RUNNING TEST FUNCTION")

class BaseTest:
	def setup_class(cls):
		print("setting up CLASS {0}".format(
			cls.__name__))

	def teardown_class(cls):
		print("tearing down CLASS {0}\n".format(
			cls.__name__))

	def setup_method(self, method
		print("setting up METHOD {0}".format(
			method.__name__))

	def teardown_method(self, method):
		print("tearing down METHOD {0}".format(
			method.__name__))

class TestClass1(BaseTest):
	def test_method_1(self):
		print("RUNNING METHOD 1-1")

	def test_method_2(self):
		print("RUNNING METHOD 1-2")

class TestClass2(BaseTest):
	def test_method_1(self):
		print("RUNNING METHOD 2-1")

	def test_method_2(self):
		print("RUNNING METHOD 2-2")

# OK

py.test setup_teardown.py -s
	setup_teardown.py
	setting up MODULE setup_teardown
	RUNNING TEST FUNCTION
	.setting up CLASS TestClass1
	setting up METHOD test_method_1
	RUNNING METHOD 1-1
	.tearing down METHOD test_method_1
	setting up METHOD test_method_2
	RUNNING METHOD 1-2
	.tearing down METHOD test_method_2
	tearing down CLASS TestClass1
	setting up CLASS TestClass2
	setting up METHOD test_method_1
	RUNNING METHOD 2-1
	.tearing down METHOD test_method_1
	setting up METHOD test_method_2
	RUNNING METHOD 2-2
	.tearing down METHOD test_method_2
	tearing down CLASS TestClass2
	
	tearing down MODULE setup_teardown

# OK

# A Completely Different Way To Set Up Variables

# funcargs

from stats import StatsList

def pytest_funcarg__valid_stats(request):
	return StatsList([1,2,2,3,3,4])

def test_mean(valid_stats):
	assert valid_stats.mean() == 2.5

def test_median(valid_stats):
	assert valid_stats.median() == 2.5
	valid_stats.append(4)
	assert valid_stats.median() == 3

def test_mode(valid_stats):
	assert valid_stats.mode() == [2,3]
	valid_stats.remove(2)
	assert valid_stats.mode() == [3]

# OK

import tempfile
import shutil
import os.path

def pytest_funcarg__temp_dir(request):
	dir = tempfile.mkdtemp()
	print(dir)

	def cleanup():
		shutil.rmtree(dir)
	request.addfinalizer(cleanup)
	return dir

def test_osfiles(temp_dir):
	os.mkdir(os.path.join(temp_dir, 'a'))
	os.mkdir(os.path.join(temp_dir, 'b'))
	dir_contents = os.listdir(temp_dir)
	assert len(dir_contents) == 2
	assert 'a' in dir_contents
	assert 'b' in dir_contents

# OK

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind(('localhost',1028))
s.listen(1)

	while True:
		client, address = s.accept()
		data = client.recv(1024)
		client.send(data)
		client.close()

# OK

import subprocess
import socket
import time

def pytest_funcarg__echoserver(request):
	def setup():
		p = subprocess.Popen(
				['python3', 'echo_server.py'])
		time.sleep(1)
		return p

	def cleanup(p):
		p.terminate()

	return request.cached_setup(
			setup=setup,
			teardown=cleanup,
			scope="session")

def pytest_funcarg__clientsocket(request):
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect(('localhost', 1028))
	request.addfinalizer(lambda: s.close())
	return s

def test_echo(echoserver, clientsocket):
	clientsocket.send(b"abc")
	assert clientsocket.recv(3) == b'abc'

def test_echo2(echoserver, clientsocket):
	clientsocket.send(b"def")
	assert clientsocket.recv(3) == b'def'

# OKOKOK

# Test Skipping With py.test

import sys
import py.test

def test_simple_skip():
	if sys.platform != "fakeos":
			py.test.skip("Test works only on fakeOS")

	fakeos.do_something_fake()
	assert fakeos.did_not_happen

# OK

import py.test

@py.test.mark.skipif("sys.version_info <= (3,0)")

def test_python3():
	assert b"hello".decode() == "hello"

# OK

# py.test Extras

package: something/
	module: test_something.py
		class: TestSomething
			method: test_first
			method: test_second

# How Much Testing Is Enough?

>>> coverage run coverage_unittest.py

# OK

>>> coverage report

# OK

Name Stmts Exec Cover
--------------------------------------------------
coverage_unittest 7 7 100%
stats 19 6 31%
--------------------------------------------------
TOTAL 26 13 50%

# OK

Missing
-----------
8-12, 15-23

# OK

from stats import StatsList
import unittest

class TestMean(unittest.TestCase):
	def test_mean(self):
		self.assertEqual(StatsList([1,2,2,3,3,4]).mean(), 2.5)

if __name__ == "__main__":
	unittest.main()

# OK

# Case Study

# LOL LMAO

# Recall what Threefish and RSA are... instead we shall be implementing a 16th Century algorithm known as the Vigenere Cipher.

# Given a keyword TRAIN, we encode the message ENCODED IN PYTHON as follows:

# 1. Repeat the keyword and message together such that it is easy to map letters from one to the other:
# E N C O D E D I N P Y T H O N
# T R A I N T R A I N T R A I N
# 2. For each letter in the plaintext, find the row that begins with that letter in the table.
# 3. Find the column with the letter associated with the keyword letter for the chosen plaintext letter.
# 4. The encoded character is at the intersection of this row and column.

# Implementing It

def test_encode():
	cipher = VigenereCipher("TRAIN")
	encoded = cipher.encode("ENCODEDINPYTHON")
	assert encoded == "XECWQXUIVCRKHWA"

# OK

class VigenereCipher:
	def __init__(self, keyword):
		self.keyword = keyword

	def encode(self, plaintext):
		return "XECWQXUIVCRKHWA"

# OK

def test_encode_character():
	cipher = VigenereCipher("TRAIN")
	encoded = cipher.encode("E")
	assert encoded == "X"

# OK

def test_encode_spaces():
	cipher = VigenereCipher("TRAIN")
	encoded = cipher.encoded("ENCODED IN PYTHON")
	assert encoded == "XECWQXUIVCRKHWA"

def test_encode_lowercase():
	cipher = VigenereCipher("TRain")
	encoded = cipher.encoded("encoded in Python")
	assert encoded == "XECWQXUIVCRKHWA"

# OK

from vigenere_cipher import combine_character
def test_combine_character():
	assert combine_character("E", "T") == "X"
	assert combine_character("N", "R") == "E"

# OK

def combine_character(plain, keyword):
	plain = plain.upper()
	keyword = keyword.upper()
	plain_num = ord(plain) - ord('A')
	keyword_num = ord(keyword) - ord('A')
	return chr(ord('A') + (plain_num + keyword_num) % 26)

# OK

def test_extend_keyword():
	cipher = VigenereCipher("TRAIN")
	extended = cipher.extend_keyword(16)
	assert extended == "TRAINTRAINTRAINT"

# OK

def extend_keyword(self, number):
	repeats = number // len(self.keyword) + 1
	return (self.keyword * repeats)[:number]

# OK

def encode(self, plaintext):
	cipher = []
	keyword = self.extend_keyword(len(plaintext))
	for p,k in zip(plaintext, keyword):
		cipher.append(combine_character(p,k))
	return "".join(cipher)

# OK

plaintext = plaintext.replace(" ", "").upper()

# OK

def test_separate_character():
	assert separate_character("X", "T") == "E"
	assert separate_character("E", "R") == "N"

def test_decode():
	cipher = VigenereCipher("TRAIN")
	decoded = cipher.decode("XECWQXUIVCRKHWA")
	assert decoded == "ENCODEDINPYTHON"

# OK

def separate_character(cypher, keyword):
	cypher = cypher.upper()
	keyword = keyword.upper()
	cypher_num = ord(cypher) - ord('A')
	keyword_num = ord(keyword) - ord('A')
	return chr(ord('A') + (cypher_num - keyword_num) % 26)

 # OK

def decode(self, ciphertext):
	plain = []
	keyword = self.extend_keyword(len(ciphertext))
	for p,k in zip(ciphertext, keyword):
		plain.append(separate_character(p,k))
	return "".join(plain)

# OK

def _code(self, text, combine_func):
	text = text.replace(" ", "").upper()
	combined = []
	keyword = self.extend_keyword(len(text))
	for p,k in zip(text, keyword):
		combined.append(combine_func(p,k))
	return "".join(combined)

def encode(self, plaintext):
	return self._code(plaintext, combine_character)

def decode(self, ciphertext):
	return self._code(ciphertext, separate_character)

# OK

# Exercises

# Summary

# We have finally covered the most important topic in Python programming: automated testing. After proving its importance and considering best design principles, we discussed the basic API for two popular Python 3 test frameworks. In particular we covered:

# Unit Testing.
# Test-Driven Development.
# The Unittest Module.
# Assertion Methods And Code Setup/Cleanup.
# The py.test Framework.
# Code Coverage.

# In the next chapter, we'll wrap up our learning with a compendium of object-oriented frameworks and libraries that work in Python 3.

# Common Python 3 Libraries

# In this chapter we'll be covering:

# Database Libraries And Object-Relational Managers
# Point-And-Click Graphical Applications
# CherryPy For Web Applications
# Working With XML

# Database Access

import sqlite3
connection = sqlite3.connect("mydb.db")
connection.execute(
		"CREATE TABLE IF NOT EXISTS "
		"pet (type, breed, gender, name)")
connection.execute("INSERT INTO pet VALUES("
		"'dog', 'spaniel', 'female', 'Esme')")
connection.execute("INSERT INTO pet VALUES("
		"'cat', 'persian', 'male', 'Oscar')")
results = connection.execute("SELECT breed, name"
		" from pet where type='dog'")
for result in results:
	print(result[1])
connection.close()

# OK

# Introducing SQLAlchemy

import sqlalchemy as sqa
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()

class Pet(Base):
	__tablename__ = "pet"
	id = sqa.Column(sqa.Integer, primary_key=True)
	type = sqa.Column(sqa.String(16))
	breed = sqa.Column(sqa.String(32))
	gender = sqa.Column(sqa.Enum("male", "female"))
	name = sqa.Column(sqa.String(64))

engine = sqa.create_engine('sqlite:///mydata.db')
Base.metadata.create_all(engine)

# Adding And Querying Objects

pet = Pet()
pet.id = 1
pet.type = "dog"
pet.breed = "spaniel"
pet.gender = "female"
pet.name = "Esme"

# OK

Session = sqa.orm.sessionmaker(bind=engine)
session = Session()

session.add(pet)
session.commit()

# OK

# all(), which returns all items in the table.
# first(), which returns the first item.
# one(), which returns the only item. If no items or multiple items are found, it raises an exception.
# get(primary_key), which accepts a primary key value and returns the object matching that key.
# group_by(), order_by(), and having(), which add the related SQL clauses to the query.
# filter_by(), which uses keyword arguments to query the session.
# filter(), which uses more advanced SQL expressions (which we will discuss shortly) to query.

# OK

session.query(Pet).filter_by(name="Esme").one()

# OK

# SQL Expression Language

# != to specify inequality
# < for less than comparisons
# > for greater than comparisons
# <= for less than or equal
# >= for greater than or equal
# & to combine clauses using an AND query
# | to combine clauses using an OR query
# ~ to negate a query using NOT

# Pretty User Interfaces

# OK

# TkInter

import tkinter

class EmptyFrame(tkinter.Frame):
	pass

root = tkinter.Tk()
EmptyFrame(master=root).mainloop()

# OK

import tkinter
import random

class DiceFrame(tkinter.Frame):
	def __init__(self, master):
		super().__init__(master)
		
		die = tkinter.Button(self,
				text = "Roll!",
				command=self.roll)
		die.pack()
		self.roll_result = tkinter.StringVar()
		label = tkinter.Label(self,
				textvariable=self.roll_result)
		label.pack()
		self.pack()

	def roll(self):
		self.roll_result.set(random.randint(1, 6))

root = tkinter.Tk()
DiceFrame(master=root).mainloop()

# OK

# expand: A boolean value to say whether or not to grow the widget beyond its expected size if the parent window is resized larger. If multiple widgets have expand set, the extra space is divided between them.

# fill: Set to a string value of none, x, y, or both to instruct the widget to fill all available space assigned to it in the specified direction.

# anchor: If the widget is not set to fill its space, it can be positioned within that space. The default, center, will ensure equal spacing on all sides. Other values can be compass directions such as n, e, s, w, to position the item at the top, right, bottom, or left of available space, and the values ne, se, sw, and nw can be used to position it in one of the four corners.

# ipadx and ipady: These integer values provide padding inside the widget on either the left and right or top and bottom edges. It has the effect of increasing the size of the widget.

# padx and pady: These integer values provide padding between the widget and the edge of its available space. It has the effect of placing space between the widget and its neighbors.

# side: Use one of left, right, top, or bottom to pack the widgets along a specific side. Normally, all widgets in a container frame are packed to the same side; mixing them can have unanticipated effects. If you need more than a single row or column, you can pack frames inside of other frames.

# OK

import tkinter

class PackFrame(tkinter.Frame):
	def __init__(self, master):
		super().__init__(master)

		button1 = tkinter.Button(self,
				text = "expand fill")
		button1.pack(expand=True, fill="both", side="left")
		button2 = tkinter.Button(self,
				text = "anchor ne pady")
		button2.pack(anchor="ne", pady=5, side="left")
		button3 = tkinter.Button(self,
				text = "anchor se padx")
		button3.pack(anchor="se", padx=5, side="left")

class TwoPackFrames(tkinter.Frame):
	def __init__(self, master):
		super().__init__(master)
		button1 = tkinter.Button(self,
				text="ipadx")
		button1.pack(ipadx=215)
		packFrame1 = PackFrame(self)
		packFrame1.pack(side="bottom", anchor="e")
		packFrame2 = PackFrame(self)
		packFrame2.pack(side="bottom", anchor="w")
		self.pack()

root = tkinter.Tk()
TwoPackFrames(master=root).mainloop()

# OK

# PyQt

from PyQt4 import QtGui

app = QtGui.QApplication([])

class EmptyWidget(QtGui.QWidget):
	pass

window = EmptyWidget()
window.show()
app.exec_()

# OK

from PyQt4 import QtGui
import random

app = QtGui.QApplication([])

choices = ["Rock", "Paper", "Scissors"]

class RockPaperScissorsWidget(QtGui.QWidget):
	def __init__(self):
		super().__init__()
		rock = RPSButton("Rock", self)
		paper = RPSButton("Paper", self)
		scissors = RPSButton("Scissors", self)
		for button in (rock, paper, scissors):
			button.resize(100, 100)
		rock.move(0,0)
		paper.move(0,100)
		scissors.move(0,200)
		self.response = QtGui.QLabel("", self)
		self.response.setGeometry(110, 0, 200, 300)

class RPSButton(QtGui.QPushButton):
	def mousePressEvent(self, event):
		computer_choice = random.choice(choices)
		user_choice = self.text()

		comp_idx = choices.index(computer_choice)
		user_idx = choices.index(user_choice)

		message = {
				0: 'Tied',
				1: 'Computer Wins',
				2: 'You Win'}[(comp_idx - user_idx + 3) % 3]

		self.parent().response.setText("You chose {0}<br />"
				"Computer chose {1}<br />"
				"{2}".format(user_choice, computer_choice, message))

window = RockPaperScissorsWidget()
window.show()
app.exec_()

# OK

# Choosing A GUI Toolkit

# XML

# ElementTree

<!DOCTYPE html>
<html>
	<head>
		<title>This is a web page</title>
		<link rel="stylesheet" href="styles.css" />
	</head>
	<body>
		<h1>Welcome To My Site</h1>
		<article class="simple">
			This is <em>my</em> site. It is rather lame.
			But it's still <strong>mine</strong>. Mine,
			I say.
		</article>
	</body>
</html>

# OK

from xml.etree.ElementTree import fromstring

with open("html_document.html") as file:
	root = fromstring(file.read())

print("ROOT NODE")
print("\ttag:", root.tag)
print("\tnumber of children:", len(root))
print("\tchildren:", [c.tag for c in root.getchildren()])
head = root[0]
print("HEAD NODE")
print("\tfirst child:", head[0].tag)
print("\tsecond_child:", head[1].tag)
print("\tlink attributes:", head[1].attrib)
article = root[1][1]
print("ARTICLE NODE")
print("\ttag:", article.tag)
print("\ttext:", article.text)
print("\tfirst child:", article[0].tag, article[0].text)
print("\t\tem's tail:", article[0].tail)
print("\tsecond child:", article[1].tag, article[1].text)
print("\tstrong's tail:", article[1].tail)

# OK

ROOT NODE
	tag: html
	number of children: 2
	children: ['head', 'body']
HEAD NODE
	first child: title
	second_child: link
	link attributes: {'href': 'styles.css', 'rel': 'stylesheet'}
ARTICLE NODE
	tag: article
	text:
			This is
	first child: em my
			em's tail: site. It is rather lame.
				But it's still
	second child: strong mine
	strong's tail: . Mine,
		I say.

# OK

# Parse it node by node and convert it to some other structure.
# Find specific elements or attributes and look up their value.

# OK

print('search for child tag:', root.find('head'))
print('search children recursively:', root.findall('.//em'))
print('build path:', root.findtext('./body/article/em'))

# OK

search for child tag: <Element head at 961f7ac>
search children recursively: [<Element em at 961fb2c>]
build path: my

# OK

# Constructing XML Extensible Markup Language Documents

from xml.etree.ElementTree import (Element, SubElement,
		tostring)

root = Element("html")
head = Element("head")
root.append(head)
title = SubElement(head, "title")
title.text = "my page"
link = SubElement(head, "link")
link.attrib['rel'] = "stylesheet"
link.attrib['href'] = "styles.css"
body = Element("body")
body.text = "This is my website."
root.append(body)
print(tostring(root))

# OK

<html><head><title>my page</title><link href="styles.css"
rel="stylesheet" /></head><body>This is my website.</body></html>

# Ixml

print('xpath attribute:', root.xpath('//link[@href]'))
print('xpath text filter:', root.xpath('//*[contains(em, "my")]'))
print('xpath first child:', root.xpath('/html/body/article/em[1]'))
from lxml.cssselect import CSSSelector
print('css class selector:', CSSSelector('.simple')(root))
print('css tag selector:', CSSSelector('em')(root))

# OK

# A parser for badly formed HTML.
# A unique library for treating elements like objects, so you can access sub-tags as if they were attributes on objects.
# A complete XML validation tool that can utilise DTDs, XMLSchema, and RELAX NG schemas.

# OK

# CherryPy

import cherrypy

class SimplePage:
	@cherrypy.expose
	def index(self):
		with open("html_document.html") as file:
			return file.read()

cherrypy.quickstart(SimplePage())

# OK

import cherrypy

template = """<!DOCTYPE html>
<html>
	<body>
		{message}
	</body>
</html>"""

class AboutPage:
	@cherrypy.expose
	def index(self):
		return template.format(message="""
		I'm not a very interesting person...""")

@cherrypy.expose
def contactPage(self):
	print(self)
	return template.format(
			message="I can't be contacted anywhere.")

class MainPage:
	about = AboutPage()
	contact = contactPage
	@cherrypy.expose
	def index(self):
		return template.format(message="""
		This is the main page.
		<a href="/about/">About Me</a>
		<a href="/contact/">Contact Me</a>
		<a href="/links/">Some Links</a>
		""")

	@cherrypy.expose
	def links(self):
		return template.format(
				message="No Links Yet")

cherrypy.quickstart(MainPage())

# OK

# By defining a separate function and including the attribute in the class definition as we did with contactPage.

# By defining a separate class and including an instance of it in the class definition, as we did with aboutPage.

# By adding the exposed method to the object after the class has been instantiated using code such as app.some_page = AnExposedClass()

# OK

import cherrypy

class ContactPage:
	@cherrypy.expose
	def index(self, message=None):
		if message:
			print("The user submitted:\n{0}".format(
				message))
		return "Thank you!"
	return """<form>
		<textarea name="message"></textarea>
		<input type="submit" />
		</form>"""

cherrypy.quickstart(ContactPage())

# OK

# A Full Web Stack?

import datetime
import sqlalchemy as sqa
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()

class Article(Base):
	__tablename__ = "article"
	rowid = sqa.Column(sqa.Integer, primary_key=True)
	title = sqa.Column(sqa.String)
	message = sqa.Column(sqa.String)
	pub_date = sqa.Column(sqa.DateTime)

	def __init__(self, title, message):
		self.title = title
		self.message = message
		self.pub_date=datetime.datetime.now()

class Comment(Base):
	__tablename__ = "comment"
	rowid = sqa.Column(sqa.Integer, primary_key=True)
	article_id = sqa.Column(sqa.Integer,
			sqa.ForeignKey('article.rowid'))
	article = sqa.orm.relationship(Article, backref="comments")
	name = sqa.Column(sqa.String)
	message = sqa.Column(sqa.String)

	def __init__(self, article_id, name, message):
		self.article_id = article_id
		self.name = name
		self.message = message

engine = sqa.create_engine('sqlite:///blog.db')
Base.metadata.create_all(engine)
Session = sqa.orm.sessionmaker(bind=engine)

# OK

# Jinja Templating

import jinja2

templates = jinja2.Environment(loader=jinja2.FileSystemLoader(
		'blog_templates'))

# OK

{% extends "base.html" %}

{% block title %}New Entry{% endblock %}
{% block content %}
<form method="POST" action="/process_add/">
	Title: <input name="title" type="text" size="40" /><br />
	<textarea name="message" rows="10" cols="40">
	</textarea><br />
	<input type="submit" value="Publish" />
</form>
{% endblock %}

# OK

<!DOCTYPE html>
<html>
	<head><title>{% block title %}{% endblock %}</title></head>
	<body>
		<h1>My Blog</h1>
		<ul>
			<li><a href="/">Main</a></li>
			<li><a href="/add/">Add Entry</a></li>
		</ul>
		<hr />
		{% block content %}
		{% endblock %}
	<body>
<html>

# OK

{% extends "base.html" %}

{% block title %}My Blog{% endblock %}
{% block content %}
	{% for article in articles %}
		<h2>{{article.title}}</h2>
		<em>{{article.pub_date.strftime('%b %d %Y')}}</em>
		<p>{{article.message}}</p>
		<div style="margin-left: 6em">
			<h3>Comments</h3>
			{% for comment in article.comments %}
				<em>{{comment.name}} wrote:</em>
				<p>
				{{comment.message}}
				</p>
			{% endfor %}
			{% include "comment_form.html" %}
		</div>
		<hr />
	{% endfor %}
{% endblock %}

# OK

<form method="POST"
		action="/process_comment/{{article.rowid}}/">
	Name: <input name="name" type="text" size="30" /><br />
	<textarea name="message" rows="5" cols="30">
	</textarea><br />
	<input type="submit" value="Comment" />
</form>

# The CherryPy Web Log Web Application

# Righto cheery cherry pie it is with the cherry on top in the cherry red chariot excess is just my character with the cherry wood fired cherry oven.

import cherrypy
class Blog:
	@cherrypy.expose
	def index(self):
		session = Session()
		articles = session.query(Article).all()
		template = templates.get_template("index.html")
		content = template.render(articles=articles)
		session.close()
		return content
cherrypy.quickstart(Blog())

# OK

@cherrypy.expose
def add(self):
	template = templates.get_template("add.html")
	return template.render()

# OK

@cherrypy.expose
def process_add(self, title=None, message=None):
	session = Session()
	article = Article(title, message)
	session.add(article)
	session.commit()
	session.close()
	raise cherrypy.HTTPRedirect("/")

# OK

@cherrypy.expose
def process_comment(self, article_id, name=None,
		message=None):
	session = Session()
	comment = Comment(article_id, name, message)
	session.add(comment)
	session.commit()
	session.close()
	raise cherrypy.HTTPRedirect("/")

# OK

# Exercises

# Terrific documentation on their websites, including tutorials, Application Program Interfaces references, and specific examples.

# OK

# Summary

# The variety of topics related in this chapter is quite staggering. We started with databases, graduated to Graphical User Interfaces, diverged into a discussion of XML, and ultimately built a small web application. The goal was to introduce popular, available libraries for major real-world tasks. The number of libraries available for Python 3 is steadily growing as more and more developers choose to support the cleaner syntax used in this version of the Python language. We have seen an overview of:

# SQLAlchemy For Databases
# TkInter For Graphical Interfaces
# PyQt For Different Graphical Interfaces
# ElementTree For XML Parsing
# lxml For Better XML Parsing
# CherryPy For Web Applications
# Jinja For String Templating In Web Applications

# Thus ends our tour through the world of Object-oriented Programming in Python. I sincerely hope you enjoyed the ride, and are excited to test your new skills on innovative new programming problems. Thanks for your attention, and please watch your step as you leave the vehicle.

# OK

Index
Symbols
 __call__ method 270
__getattribute__ method 192
__iter__ method 181
__new__ class method 248
__new__ method 181
__next__ method 197
__repr__ method 171
__str__ method 242
_update_observers method 236
A
absolute imports 46
abstract factory pattern
about 271
examples 272
implementing 273-275
UML class diagram 272
abstraction 16
access control 50, 51
adapter pattern
about 257, 259
benefits 258
structure 258
UML diagram 258
add_child method 279
add_point method 127
Agent class 90
aggregation 19
all() method 352
API SQLite 348
append() method 170
append method 98
arguments, for controlling widget
anchor 356
expand 356
fill 356
ipadx 356
ipady 356
padx 356
pady 356
side 357
assertDictEqual method 320
assertEqual method 318
assertFalse method 318
assert function 38
assertGreaterEqual method 319
assertGreater method 319
assertIn method 319
assertion methods, Python 3.1
about 319
assertDictEqual 320
assertGreater 319
assertGreaterEqual 319
assertIn 319
assertIsNone 319
assertIsNotNone 319
assertLess 319
assertLessEqual 319
assertListEqual 320
assertMultilineEqual 320
assertNotIn 319
assertRegexpMatches 320
assertSameElements 319
assertSequenceEqual 320
assertSetEqual 320
assertTupleEqual 320
assertion methods, unit testing
about 318
assertEqual 318
assertFalse 318
assertNotEqual 318
assertRaises 318
assertTrue 318
assertIsNone method 319
assertIsNotNone method 319
assertLessEqual method 319
assertLess method 319
assertListEqual method 320
assertMultilineEqual method 320
assertNotEqual method 318
assertNotIn method 319
assertRaises method 318
assertRegexpMatches method 320
assertSameElements method 319
assertSequenceEqual method 320
assertSetEqual method 320
assertTrue method 318
assertTupleEqual method 320
association 9
attributes 11, 12
AudioFile object 78
authentication 113
authentication and authorization system,
case study
about 112
designing 112-122
authorization 113
B
Base class 350
BaseException 95
basic inheritance
about 63
built-ins, extending 66
example 63-65
overriding 67, 68
super() 68
behaviors
about 7
adding to class data, properties used
129-131
boolean convenience methods
isalnum 284
isalpha 284
isdecimal 284
isdigit 284
isidentifier 285
islower 285
isnumeric 284
isprintable 285
isspace 285
istitle 285
isupper 285
bottom-up design 61
built-in functions, Python
about 191
all function 197
any function 197
compile function 197
delattr function 197
enumerate function 193
eval function 197
exec function 197
getattr function 197
hasattr function 197
len() function 192
reversed() function 192
setattr function 197
sorted() function 196
true function 197
zip function 194
bytearray type 298
BytesIO 302
bytes mode 300
C
calculate_distance method 38
call_after method 215
call_me method 73
callable attributes 218
callable objects 219
callback functions
about 213-217
canonical example, strategy pattern 238, 240
capitalize method 286
case study
authentication and authorization system
112
cryptography application, writing 339
Document class, modeling 147
mailing list manager 220
notebook application 53-61
simple link collector 182
simple real estate application 80
CHARACTERS list 170
CherryPy
about 368
example 368
features 368-371
CherryPy blog web application
about 375
designing 375-377
ChildNode state 244
cipher
working 339
class 9
class diagram
about 9
association 9
multiplicity 11
cleanup function 333
close method 300
code coverage 336
collect_links method 184
command-line arguments, py.test
--exitfirst argument 335
--looponfail argument 335
--pdb argument 335
-f argument 335
-k argument 336
py.test --help 335
py.test output 335
to py.test forces 335
command object 267
command pattern
about 267
example 267
implementing 268-271
UML diagram, 267
Component class 279
composite pattern
about 276
implementing 277-279
UML diagram 276
composition
about 17
example 17, 18
composition relationship 20
comprehensions
about 197
dictionary comprehensions 200, 201
generator expressions 201
list comprehensions 198
set comprehensions 200, 201
config attribute 330
connect function 349
connection object 349
constructor 39
Contact class 65
ContactList class 66
count() method 170
count method 285
coverage.py 336
coverage report command 337
coverage testing
about 336
coverage.py 336
figleaf 336
create_engine function 351
cryptography application, case study
cipher, working 339
implementing 340-344
writing 339, 340
CurrencyFormatter class 273
current_node 243
Cursor class 150
D
data 7
database access 348
database module 46
database object 47
DateFormatter class 273
datetime objects 258
DBAPI2 348
DebuggingServer class 220
declarative_base 350
decorator pattern
about 229
in Python 233, 234
in UML 229
network programming example 230-232
uses 229
decorator pattern, in Python
about 233
logging example 233, 234
decorators
about 134
applying 134
default arguments 207
defaultdict
using 166, 167
defaultdict constructor 167
default method 310
delay parameter 216
delegation method 139
design patterns
about 227, 228
abstract factory pattern 271
adapter pattern 257
command pattern 267
composite pattern 276
decorator pattern 229
facade pattern 260
flyweight pattern 263
observer pattern 235
singleton pattern 247
state pattern 240
strategy pattern 237
template pattern 251
diamond problem, multiple inheritance
about 71
example 71-75
dict() constructor 162
dict.update method 85
dict class 67
dictionaries
about 162
defaultdict, using 166, 167
stock application example 162-165
uses 166
dictionary comprehensions 200, 201
DictSorted object 181
difference method 176
discover module 322
distance method 126
docstrings 41
Document class, case study
modeling 147-154
DOM (Document Object Model) library 362
done() method 228
dot notation 35
duck typing 22
dumps function 304
E
Element object 363
ElementTree
about 362, 365
example 363, 364
XML documents, constructing 366
encapsulation 15
endswith method 285
enumerate function 193, 194
exceptional circumstances 109
exception hierarchy
about 106, 108
custom exceptions, defining 108
KeyboardInterrupt exception 107
SystemExit 107
exceptions
about 95
case study 112
handling 101-105
raising 95-100
using, for exceptional circumstances
109-[111
execute() method 270, 349
F
facade pattern
about 260, 262
structure 261
UML diagram 260, 261
figleaf 336
file IO
about 299, 300
files, faking 302, 303
placing, in context 301, 302
filename property 143
filter() method 352
filter_by method 352
find_replace method 138
findall method 367
find method 285, 365
findtext method 365
first() method 352
FirstTag state 245
Flyweight class 264
flyweight pattern
about 263
implementing 263-266
UML diagram 264
foo function 134
foo method 134
format() method 287
format_string function 50
format_time function 217
format method 217
FormatterFactory class 273
Friend class 71
fruit farming example 12
full_name property 309
funcargs 329
G
generator expressions 201, 202
generator syntax 203-205
get(primary_key) method 352
get_path function 279
get_valid_input method 91
get method 163
group_by() method 352
GUI toolkit
PyGTK 361
selecting 361
wxPython 361
H
hashable object 173
having() method 352
help function 179
House class 86
I
imaplib standard library 262
information hiding 15
inheritance
about 20
abstraction 22
basic inheritance 63
example 21, 22
multiple inheritance 23, 68
inheritance diagram 71
initialize_database function 48
insert() method 170
intersection method 175
Invoker objects 267
isalnum method 284
isalpha method 284
isdecimal method 284
isdigit method 284
isidentifier method 285
islower method 285
isnumeric method 284
isprintable method 285
isspace method 285
issubset method 176
issuperset method 176
istitle method 285
isupper method 285
iterative development model 8
iterator pattern 228
J
JavaScript Object Notation (JSON) 308
Jinja Templating 372-374
join function 151
JSONEncoder class 309
JSON serializer 308
K
KeyboardInterrupt exception 107
L
lambda function 197
len() function 192
links method 369
list.sort method 238
list comprehensions 198-200
lists
about 168-170
sorting 171, 172
loads function 304
lower method 286
lxm 366
lxml
features 366, 367
M
mailing list manager, case study
about 220
building 220-223
make_background method 240
menu_item class 270
message variable 370
method overloading 205
Method Resolution Order 72
methods 13
mixin 68
modules
about 43, 44
absolute imports 46
importing 45
organizing 45
relative imports 47-50
monkey-patch 69
mousePressEvent method 361
move method 279
multiple inheritance
about 23, 68
arguments lists, formatting 75, 77
diamond problem 71
example 70
mixin 68
options 69
working 70
multiplicity 11
mutable byte strings 297, 298
N
name attribute 131
namedtuple constructor 161
named tuples
about 161
creating 161
network programming example, decorator
pattern 230
new card catalog program, case study
about 24-30
UML diagram 26
UML sequence diagram 27
next() method 228
no_return function 100
Node objects 242
normalize_url method 184
notebook application, case study 53-61
NotImplementedError 254
O
object
about 7, 9
attributes 11, 12
behaviors 13
class diagram 9
classes relationship, describing 9
data 11
identifying 125-128
kinds 9
managing 137
storing 303
object-oriented 7
object-oriented Analysis (OOA) 8
object-oriented Design (OOD) 8
Object-Relational Managers(ORMs)
about 349
SQLAlchemy 349
object management
about 137
composition-based solution 145, 146
delegation method 139
duplicate code, removing 140, 141
example 138
existing code, reusing 142-144
extensibility 138
files, unzipping 139
files, zipping 139
partitioning 139
readability 138
object relations
association 9
composition 17
inheritance 20
objects, storing
about 303, 305
pickles, customizing 305, 307
web objects, serializing 308-310
observer pattern
about 235
example 235-237
in UML 235
one() method 352
open() function 299
OpenTag state 245
order_by() method 352
OrderedDict object 182
order method 65
P
p.reset() method 36
package 45
pack method 355
parameters 13
parent variable 279
Parser class 243
partition method 286
pattern parameter 365
paypal module 47
perimeter function 126
phone attribute 68
pickle module 303
plain_text attribute 51
play() method 78
Point class
creating 35
reset method 36
polymorphism
about 22, 78, 79
inheritance, using 78, 79
print method 218
process_comment method 376
process_files method 143
process_format method 254
process_zip function 146
process method 244
processor object 146
Product class 46
products module 46
prompt_init static method 85
properties
creating, decorators used 134, 135
using 135-137
property constructor 132
property keyword 131
property object
about 132
working 132, 133
public interface
creating 14-17
Purchase class 87
py.test
about 324
command-line arguments 335
running 325, 326
py.test.skip function 333
pygame library 144
PyGTK 361
PyQt
about 358
download link 358
features 359-361
Python
access control 50, 51
built-in data structures 157
built-in functions 191
case study 24
coverage testing 336
database access 348
default arguments 207
design patterns 227
docstrings 41
duck typing 22
objects, identifying 125
pickle module 303
strings 283
test, need for 313
test driven development 315
unit testing 316
unittest module 324
unpacking arguments 212, 213
variable argument lists 208-212
Python classes
attributes, adding 35
creating 33, 34
implementing 35-38
object, initializing 38-40
Python data structures
about 157
built-ins, extending 177-181
dictionaries 162
lists 168
named tuples 161
objects 157, 158
sets 173
tuples 159, 160
tuples, creating 159
PYTHONPATH 46
Q
Query object 352
quickstart function 368
R
readline method 300
read method 300
relative imports 47-50
Rental class 87
Repeater class 217
replace method 286
request.addfinalizer method 331
request.cached_setup method 331
request object 330
reset method 36
reverse() method 170
reversed() function 192, 193
root node 243
run method 216
S
SAX (Simple API for XML) library 362
self parameter 36
send_email method 262
send_mail function 47, 289
session.query() method 352
sessionmaker function 352
set() constructor 174
set() method 356
set_name() method 130
set comprehensions 200, 201
setdefault method 163
sets 173-176
setter attribute 134
setText method 361
setup function 333
setUp method 322
Silly class 135
simple link collector, case study
writing 182-188
simple real estate application, case study
about 80
designing 80-91
singleton pattern
about 247
implementing 248
mimicking, module variables used 249, 250
skip method 323
smtplib module 69
sort() method 170
sorted() function 196, 238
split method 260
SQLAlchemy
about 349
features 349, 350
objects, adding 351, 352
objects, querying 351, 352
SQL Expression Language 352
sqlalchemy.create_engine function 350
SQLAlchemy Expression Language 353
SQL Expression Language 352
SQLite 348
SQLite 3 348
startswith method 285
state pattern
about 240
differences, with strategy pattern 247
example 241-245
in UML 241
str() function 152
str.format method 287
str.lower function 172
strategy pattern
about 237
canonical example 238, 240
in Python 240
in UML 238
strategy pattern, in Python 240
str class 284
string.ascii_letters attribute 170
string formatting
about 287
brace characters, escaping 288
container lookups 289, 290
keyword arguments 288, 289
object lookups 291
variables, making look right 291-293
StringIO 302
string manipulation
about 284
examples 284
strings
about 283
mutable byte strings 297
string formatting 287
string manipulation 284
Unicode characters 294
StringVar object 356
strip() 245
subclass 64
Subclass object 73
SubElement function 366
super() 68
superclass 64
supplier class 65
symmetric_difference method 175
SyntaxError exception 96
sys.exit function 107
SystemExit exception 107
T
tearDown method 322
template pattern
about 251
example 252-255
in UML 251
test
need for 313, 314
TestCase 322
test driven development 315
testing, with py.test
about 324, 325
setup_class method 327
setup_method 327
setup_module method 327
teardown_class method 327
teardown_method 327
teardown_module method 327
test, skipping 333, 334
unittest example 325, 326
variables, setting up 329-333
TestSuites 322
TextNode state 245
TimedEvent class 215
Timer class 216
title method 286
Tk() object 355
TkInter
about 354
basic configuration 354
features 354-358
tkinter.Frame class 355
top-down design 61
translate method 286
tuples
about 159
creating 159
functions 159
unpacking 160
uses 160
TurboGears framework 371
U
undo method 271
Unicode
about 294
bytes, converting to text 295
text, converting to bytes 296, 297
Unified Modeling Language (UML) 9, 10
union method 175-177
unit testing
about 316, 317
assertion methods 318
broken tests, ignoring 323, 324
situations, testing 321, 322
tests, organizing 322
tests, running 322
unittest library 319
unittest module 324
unit tests 316
unpacking arguments 212, 213
unzip method 138
update() method 235
upper method 286
urlparse function 184
V
values 13
varargs 209
variable argument lists 208-212
W
weakref module 264
WeakValueDictionary object 264
web objects
serializing 308-310
WebPage class 137
Window.exit method 270
Window class 270
writelines method 300
write method 300
wxPython 361
X
XML 362
XML parsing techniques 362
Z
zipfile module 139
zip function 194, 195
zip method 138
zipprocessor object 146
ZipReplace class 142
import serial
import keyboard
import pyautogui

ser = serial.Serial("COM8",115200,timeout=1)


while (True):

	if ser.isOpen():

		input_data=ser.readline().strip().decode("utf-8")
		# print(type(input_data))
		my_list = input_data.split(",")
		# print(my_list)
		# print(my_list[0], my_list[1])
		# print("accX = ", my_list[0], " accY = ", my_list[1])
		# print(type(float(my_list[0])))

		X = float(my_list[0])
		Y = float(my_list[1])
		if(X > 4):
			print("LEFT")
			# keyboard.press_and_release('a')
			pyautogui.keyDown("a")

		elif(X < -4):
			print("RIGHT")
			keyboard.press_and_release('d')
		# else:
		# 	print("STOP")

		elif(Y > 4):
			print("BACK")
			keyboard.press_and_release("w","a")
		elif(Y < -4):
			print("FRONT")
			# keyboard.press_and_release('w')
			pyautogui.keyDown("w","a")
		else:
			print("STOP")  
			# keyboard.press_and_release('space')

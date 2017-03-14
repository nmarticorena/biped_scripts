#!/usr/bin/env python

#
# @file callback_ir.cpp
#
# Callback from simsensor to publish dummy messages as the encoder.
#
# @author <a href="mailto:knzo@live.cl">Kenzo</a>
# @created 2014-11-1
# @modified 2014-11-1
# @version 1.0
#

import rospy
from std_msgs.msg import String
from Tkinter import *
from c_msg.msg import ServoArray



def callback_left_hip(value):
	msg_servo_array.left_hip_angle = int(value)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Dummy: Left Hip: %d !",int(value))
	return

def callback_left_knee(value):
	msg_servo_array.left_knee_angle = int(value)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Dummy: Left Knee: %d !",int(value))
	return

def callback_left_ankle(value):
	msg_servo_array.left_ankle_angle = int(value)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Dummy: Left Ankle: %d !", int(value))
	return

def callback_right_hip(value):
	msg_servo_array.right_hip_angle = int(value)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Dummy: Right Hip: %d !", int(value))
	return

def callback_right_knee(value):
	msg_servo_array.right_knee_angle = int(value)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Dummy: Right Knee: %d !", int(value))
	return

def callback_right_ankle(value):
	msg_servo_array.right_ankle_angle = int(value)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Dummy: Right Ankle: %d !", int(value))
	return

def callback_enable(value):
	value = int(value)
	if value==1:
		value = True
	else:
		value = False
	msg_servo_array.enable = value
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Enable: " + str(value))
	return

def fase0(value=0):
	left_hip_bar.set(106)
	left_knee_bar.set(113)
	left_ankle_bar.set(93)
	right_hip_bar.set(97)
	right_knee_bar.set(87)
	right_ankle_bar.set(97)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))

def fase05(value=50):
	left_hip_bar.set(106)
	left_knee_bar.set(113)
	left_ankle_bar.set(78)
	right_hip_bar.set(97)
	right_knee_bar.set(87)
	right_ankle_bar.set(83)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))

def fase1(value=1):
	left_hip_bar.set(92)
	left_knee_bar.set(123)
	left_ankle_bar.set(78)
	right_hip_bar.set(74)
	right_knee_bar.set(102)
	right_ankle_bar.set(89)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))

def fase2(value=2):
	left_hip_bar.set(92)
	left_knee_bar.set(123)
	left_ankle_bar.set(98)
	right_hip_bar.set(69)
	right_knee_bar.set(114)
	right_ankle_bar.set(105)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))


def fase3(value=3):
	left_hip_bar.set(92)
	left_knee_bar.set(123)
	left_ankle_bar.set(110)
	right_hip_bar.set(93)
	right_knee_bar.set(91)
	right_ankle_bar.set(112)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))

def fase4(value=4):
	left_hip_bar.set(92)
	left_knee_bar.set(123)
	left_ankle_bar.set(102)
	right_hip_bar.set(93)
	right_knee_bar.set(91)
	right_ankle_bar.set(114)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))

def fase5(value=5):
	left_hip_bar.set(138)
	left_knee_bar.set(74)
	left_ankle_bar.set(111)
	right_hip_bar.set(104)
	right_knee_bar.set(91)
	right_ankle_bar.set(114)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))

def fase6(value=6):
	left_hip_bar.set(137)
	left_knee_bar.set(94)
	left_ankle_bar.set(93)
	right_hip_bar.set(103)
	right_knee_bar.set(69)
	right_ankle_bar.set(98)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))

def fase7(value=7):
	left_hip_bar.set(123)
	left_knee_bar.set(107)
	left_ankle_bar.set(81)
	right_hip_bar.set(103)
	right_knee_bar.set(69)
	right_ankle_bar.set(79)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))

def fase8(value=8):
	left_hip_bar.set(138)
	left_knee_bar.set(101)
	left_ankle_bar.set(70)
	right_hip_bar.set(103)
	right_knee_bar.set(69)
	right_ankle_bar.set(75)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))

#setpoint fases                 intento_1
#fase0 106,113,93 97,87,97
#fase1 88,113,78 74,116,93
#fase2 92,123,92 93,91,96
#fase3 92,123,110 93,91,112
#fase4 92,123,102 93,91,114
#fase5 138,74,111 104,91,114
#fase6 123,107,97 103,69,102
#fase7 123,107,81 103,69,79
#fase8 138,101,70 103,69,75

#setpoint fases                 intento_1
#fase0 106,113,93 97,87,97      esta bien
#fase0.5 106,113,78 97,87,83   
#fase1 92,123,78 74,102,89      mkIII
#fase2 92,123,98 69,114,105	mkII
#fase3 92,123,110 93,91,112
#fase4 92,123,102 93,91,114     NOT
#fase5 138,74,111 104,91,114    
#fase6 137,94,93 103,69,98	mkII

#fase7 123,107,81 103,69,79

#fase8 138,101,70 103,69,75     NOT



#=====GIRO======

def giro0(value=0):
	left_hip_bar.set(106)
	left_knee_bar.set(113)
	left_ankle_bar.set(93)
	right_hip_bar.set(97)
	right_knee_bar.set(87)
	right_ankle_bar.set(97)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("FaseGiro: %d !",int(value))

def Lfinegiro(value=1):
	left_hip_bar.set(92)
	left_knee_bar.set(123)
	left_ankle_bar.set(82)
	right_hip_bar.set(74)
	right_knee_bar.set(102)
	right_ankle_bar.set(97)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))

def Lcoargiro1(value=2):
	left_hip_bar.set(116)
	left_knee_bar.set(110)
	left_ankle_bar.set(78)
	right_hip_bar.set(64)
	right_knee_bar.set(98)
	right_ankle_bar.set(81)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))

def Lcoargiro2(value=3):
	left_hip_bar.set(116)
	left_knee_bar.set(116)
	left_ankle_bar.set(83)
	right_hip_bar.set(50)
	right_knee_bar.set(86)
	right_ankle_bar.set(95)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))

def Rfinegiro(value=1):
	left_hip_bar.set(131)
	left_knee_bar.set(93)
	left_ankle_bar.set(88)
	right_hip_bar.set(103)
	right_knee_bar.set(82)
	right_ankle_bar.set(104)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))
	
def Rcoargiro1(value=2):
	left_hip_bar.set(131)
	left_knee_bar.set(85)
	left_ankle_bar.set(100)
	right_hip_bar.set(103)
	right_knee_bar.set(87)
	right_ankle_bar.set(111)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))

def Rcoargiro2(value=3):
	left_hip_bar.set(139)
	left_knee_bar.set(113)
	left_ankle_bar.set(95)
	right_hip_bar.set(91)
	right_knee_bar.set(82)
	right_ankle_bar.set(106)
	pub_servo_array.publish(msg_servo_array)
	rospy.loginfo("Fase: %d !",int(value))





#Initialize as node
rospy.init_node('biped_dummy_plug_node', anonymous=True)

#Create dummy msg objects
msg_servo_array = ServoArray()
msg_servo_array.left_hip_angle    = 128
msg_servo_array.left_knee_angle   = 128
msg_servo_array.left_ankle_angle  = 128
msg_servo_array.right_hip_angle   = 128
msg_servo_array.right_knee_angle  = 128
msg_servo_array.right_ankle_angle = 128
msg_servo_array.enable = True

def quit(event):
    rospy.loginfo("Exit!")
    rospy.signal_shutdown("")
    root.quit()

#Create & Configure Publishers
pub_servo_array = rospy.Publisher('biped_dummy_plug_node/t_servo_array', ServoArray, queue_size=10)

#Create main window
root = Tk()
root.bind('<Control-c>', quit)
root.minsize() #width=500, height=500
root.wm_title("Biped - EVA-01 Dummy Plug")

#Create Main Frame Widget
win = Frame(root)
win.grid(sticky=N+S+E+W)

#Create Frames
frame_left =  LabelFrame(win, text='Left Foot', padx=5, pady=5)
frame_right = LabelFrame(win, text='Right Foot', padx=5, pady=5)

frame_left.pack(side=LEFT, expand=True, padx=10, pady=10, fill=BOTH)
frame_right.pack(side=LEFT, expand=True, padx=10, pady=10, fill=BOTH)


#Add Labels

#Left Foot Labels
Label(win, text='Hip:').grid(in_=frame_left,row=0,column=0, sticky=W)
Label(win, text='Knee:').grid(in_=frame_left,row=1,column=0, sticky=W)
Label(win, text='Ankle:').grid(in_=frame_left,row=2,column=0, sticky=W)

#Right Foot  Labels
Label(win, text='Hip:').grid(in_=frame_right,row=0,column=0, sticky=W)
Label(win, text='Knee:').grid(in_=frame_right,row=1,column=0, sticky=W)
Label(win, text='Ankle:').grid(in_=frame_right,row=2,column=0, sticky=W)
Label(win, text='Enable:').grid(in_=frame_right,row=3,column=0, sticky=W)






#Add Slide Bars

left_hip_bar = Scale(win, from_=10, to=170, orient=HORIZONTAL, command=callback_left_hip)
left_hip_bar.grid(in_=frame_left, row=0, column=100, sticky=E)
left_hip_bar.set(106)

left_knee_bar = Scale(win, from_=10, to=170, orient=HORIZONTAL, command=callback_left_knee)
left_knee_bar.grid(in_=frame_left, row=1, column=100, sticky=E)
left_knee_bar.set(112)

left_ankle_bar = Scale(win, from_=10, to=170, orient=HORIZONTAL, command=callback_left_ankle)
left_ankle_bar.grid(in_=frame_left, row=2, column=100, sticky=E)
left_ankle_bar.set(93)

right_hip_bar = Scale(win, from_=10, to=170, orient=HORIZONTAL, command=callback_right_hip)
right_hip_bar.grid(in_=frame_right, row=0, column=100, sticky=E)
right_hip_bar.set(97)

right_knee_bar = Scale(win, from_=10, to=170, orient=HORIZONTAL, command=callback_right_knee)
right_knee_bar.grid(in_=frame_right, row=1, column=100, sticky=E)
right_knee_bar.set(91)

right_ankle_bar = Scale(win, from_=10, to=170, orient=HORIZONTAL, command=callback_right_ankle)
right_ankle_bar.grid(in_=frame_right, row=2, column=100, sticky=E)
right_ankle_bar.set(97)

enable_bar = Scale(win, from_=0, to=1, orient=HORIZONTAL, command=callback_enable)
enable_bar.grid(in_=frame_right, row=3, column=100, sticky=E)
enable_bar.set(0)

#Botones
boton0 = Button(win, text='Fase 0',command = fase0)
boton0.grid(in_=frame_right,row=4,column=100)

boton05 = Button(win, text='Fase 05',command = fase05)
boton05.grid(in_=frame_right,row=13,column=100)

boton1 = Button(win, text='Fase 1',command = fase1)
boton1.grid(in_=frame_right,row=5,column=100)

boton2 = Button(win, text='Fase 2',command = fase2)
boton2.grid(in_=frame_right,row=6,column=100)

boton3 = Button(win, text='Fase 3',command = fase3)
boton3.grid(in_=frame_right,row=7,column=100)

boton4 = Button(win, text='Fase 4',command = fase4)
boton4.grid(in_=frame_right,row=8,column=100)

boton5 = Button(win, text='Fase 5',command = fase5)
boton5.grid(in_=frame_right,row=9,column=100)

boton6 = Button(win, text='Fase 6',command = fase6)
boton6.grid(in_=frame_right,row=10,column=100)

boton7 = Button(win, text='Fase 7',command = fase7)
boton7.grid(in_=frame_right,row=11,column=100)

boton8 = Button(win, text='Fase 8',command = fase8)
boton8.grid(in_=frame_right,row=12,column=100)

#GIRO

botong0 = Button(win, text='Giro 0',command = giro0)
botong0.grid(in_=frame_left,row=4,column=100)

botongL1 = Button(win, text='Lfine giro',command = Lfinegiro)
botongL1.grid(in_=frame_left,row=5,column=100)

botongL2 = Button(win, text='LGiro1',command = Lcoargiro1)
botongL2.grid(in_=frame_left,row=6,column=100)

botongL3 = Button(win, text='LGiro2',command = Lcoargiro2)
botongL3.grid(in_=frame_left,row=7,column=100)

botongR1 = Button(win, text='Rfinegiro',command = Rfinegiro)
botongR1.grid(in_=frame_left,row=8,column=100)

botongR2 = Button(win, text='RGiro 1',command = Rcoargiro1)
botongR2.grid(in_=frame_left,row=9,column=100)

botongR3 = Button(win, text='RGiro 2',command = Rcoargiro2)
botongR3.grid(in_=frame_left,row=10,column=100)

#COMENTARIO
#El giro hacia la izquierda lo hace pivoteandose en ambos pies planos en el suelo
#El giro hacia la derecha lo hace pivoteandose en un talon

#El giro con talon es el mas eficiente pero medio hueon
#el giro con los pies puede usarse como fine tune




#GIRO CORTO A LA IZQUIERDA EN SUP. RUGOSA (SUELO)
#	FASES: 		Fase 0, Lfinegiro, fase 0
#	dGRADO/dGIRO: 	90 grados en 7 giros, 12,8 grados por giro aprox.
#	DELTAX: 	En 7 giros se desplaza (14)i + (-0,5)j [cm]	

#GIRO LARGO A LA IZQUIERDA EN SUP. RUGOSA
#	FASES: 		Fase 0, Lcoargiro1, Lcoargiro2, fase 0
#	dGRADO/dGIRO: 	90 grados en 4 giros, 22,5 grados por giro aprox.
#	DELTAX: 	En 10 giros se desplaza (14)i + (-0,5)j [cm]	


#GIRO LARGO A LA DERECHA EN SUP. RUGOSA
#	FASES: 		Fase 0, Rcoargiro1, Rcoargiro2, fase 0
#	dGRADO/dGIRO: 	90 grados en 5 giros, 18 grados por giro aprox.
#	DELTAX: 	En 10 giros se desplaza (14)i + (-0,5)j [cm]	








win.mainloop()


CC = gcc
CFLAG = -W -Wall
TARGET = manager2019
OBJECTS = main.c menu.o user.o
DOBJECTS = main_d.o menu_d.o user_d.o

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAG) -o $@ $^

Debug : $(DOBJECTS)
	$(CC) $(CFLAG) -o $@ $^ 

menu_d.o : menu.c
	$(CC) $(CFLAG) -DDEBUG_MODE -c  -o $@ $^

main_d.o : main.c
	$(CC) $(CFLAG) -DDEBUG_MODE -c  -o $@ $^

user_d.o : user.c
	$(CC) $(CFLAG) -DDEBUG_MODE -c  -o $@ $^

clean :
	rm *.o $(TARGET) Debug

.POHNY : $(TARGET)

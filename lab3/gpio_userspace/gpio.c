#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>
#include <unistd.h>
#include <linux/gpio.h>
#include <stdlib.h>

int main(int argc, char *argv[ ])
{ 
	int fd0 = open("/dev/gpiochip0",O_RDWR); // open the file descriptor
	struct gpiochip_info cinfo;
	ioctl(fd0,GPIO_GET_CHIPINFO_IOCTL,&cinfo); // get the chip information
	fprintf(stdout, "GPIO chip 0: %s, \"%s\", %u lines\n", cinfo.name, cinfo.label, cinfo.lines);
	struct gpiohandle_request req_GYR; // Green and Yellow and Red
	struct gpiohandle_data data_GYR; // for data bit
	struct gpioevent_request req_pb; // for push button
	struct gpioevent_data event;
	req_GYR.lines = 3; // 3 pins in this handler
	req_GYR.lineoffsets[0] = 4; //pin 4 - Green LED
	req_GYR.lineoffsets[1] = 17; // pin 17 - Yellow LED
	req_GYR.lineoffsets[2] = 27; // pin 27 - Red LED
	req_GYR.flags = GPIOHANDLE_REQUEST_OUTPUT; // set them to be output
    req_pb.lineoffset = 11; //pin 11 push button
	req_pb.handleflags = GPIOHANDLE_REQUEST_INPUT; 
    req_pb.eventflags = GPIOEVENT_REQUEST_RISING_EDGE; // using Rising Edge to trigger event
    strcpy(req_pb.consumer_label, "Push Button Event");
	data_GYR.values[0] = 1; // set initial value of Green LED to High (ON)
	data_GYR.values[1] = 0; // set initial value of Yellow LED to Low (OFF)
	data_GYR.values[2] = 0; // set initial value of Red LED to Low (OFF)
	ioctl(fd0, GPIO_GET_LINEHANDLE_IOCTL, &req_GYR); // now get the line handler req_GYR
    ioctl(fd0, GPIO_GET_LINEEVENT_IOCTL, &req_pb); // execute ioctl() to get the event handler req_pb
	while (1) {
		ioctl(req_GYR.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data_GYR); // output data 
        read(req_pb.fd, &event, sizeof(event));
		usleep(1000000); //sleep for 1 second
		data_GYR.values[0] = !data_GYR.values[0]; // toggle
		data_GYR.values[1] = !data_GYR.values[1];
	} 

	close(req_GYR.fd); // release line
	close(req_pb.fd); // release line
	close(fd0); // close the file
	exit(EXIT_SUCCESS);
}//main

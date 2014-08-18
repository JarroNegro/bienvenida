#include <gtk/gtk.h>
#include <stdlib.h>
int inicio();

int main(int argc,char *argv[])
{
GtkWidget *ventana,*boton,*tabla,*logo,*label;

inicio();

gtk_init(&argc,&argv);

ventana= gtk_window_new (GTK_WINDOW_TOPLEVEL);
gtk_window_set_title (GTK_WINDOW (ventana), "Bienvenido a JarroNegro");
gtk_container_set_border_width(GTK_CONTAINER(ventana),10);
gtk_window_set_position(GTK_WINDOW(ventana), GTK_WIN_POS_CENTER);
gtk_window_set_default_size(GTK_WINDOW(ventana), 250, 180);

//tabla contenedora
  tabla = gtk_table_new(2,2, FALSE);
  gtk_container_add(GTK_CONTAINER(ventana), tabla);



//logo
logo = gtk_image_new_from_file("/usr/share/jn/logo.jpg");
gtk_table_attach_defaults(GTK_TABLE(tabla), logo, 0, 1, 0,1);

//label
 label = gtk_label_new("Bienvenido a JarroNegro!\n\
El equipo de desarrollo,\nte agradece por probar\n\
nuestro proyecto;\ny te invita a que colabores\n\
enviando dudas y sugerencias.\n\
 \n\nhttp://www.jarronegrolinux.com\n http://www.jarronegro.org \n http://www.jarronegro.com ");

gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
gtk_table_attach_defaults(GTK_TABLE(tabla), label, 1, 2, 0,1);

//botones
boton=gtk_button_new_with_label("Aceptar");
gtk_table_attach_defaults(GTK_TABLE(tabla), boton, 1, 2, 1,2);
g_signal_connect (G_OBJECT (boton), "clicked",G_CALLBACK (gtk_main_quit), G_OBJECT(ventana));


g_signal_connect_swapped(G_OBJECT(ventana), "destroy",G_CALLBACK(gtk_main_quit), G_OBJECT(ventana));
gtk_widget_show_all(ventana);
gtk_main();
return 0;
}

int inicio()
{
system("killall idesk");
system("idesk &");
system("amixer set PCM unmute");
system("amixer set Master unmute");
system("amixer set Master 100 &>/dev/null");
system("amixer set PCM 20 &>/dev/null");
system("xbindkeys &");

return 0;
}

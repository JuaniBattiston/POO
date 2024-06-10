Ejercicio A
^^^^^^^^^^^

- Definir una ventana vacía en la clase Principal, que herede de QWidget y diseñado con QtDesigner.
- Agregar a este proyecto la clase AdminDB para permitir el uso de una base de datos. 
- Instanciar un único objeto de AdminDB en la aplicación.
- Definir una clase Linea con las siguientes características:
	- En los archivos fuente linea.h y linea.cpp
	- Atributos privados: int x_inicial, y_inicial, x_final, y_final
	- Con sus getters y setters.
	- Utilizar en esta clase todos los const que son recomendables
- Definir una tabla "lineas" en la base de datos con los siguientes campos: id, x_inicial, y_inicial, x_final, y_final
- Cargar en la base de datos un único registro, es decir, los datos de una única línea.
- Desde la clase Principal se podrá leer este único registro y crear un objeto Linea con esos datos.
- Dibujar con paintEvent esta línea dentro de la ventana con las coordenadas leídas de la base.


Ejercicio B
^^^^^^^^^^^

- Definir un formulario en la clase Formulario usando QtDesigner. 
- En Formulario se darán de alta instrumentos en un negocio de instrumentos musicales.
- Los instrumentos que se pueden cargar serán: guitarras, vientos y teclados.
- Definir las clases Instrumento, Guitarra, Viento y Teclado.
- Cada clase en sus correspondientes archivos .h y .cpp
- Instrumento será una clase abstracta con la función virtual pura ``void afinar()``
- Que esa función virtual pura simplemente publique un texto por consola, por ejemplo "Afinando guitarra".
- El formulario tendrá un botón que agregará un instrumento nuevo a un ``QVector< Instrumento * >``
- El formulario tendrá un QComboBox en el cual tendrá el siguiente listado: Guitarra, Viento y Teclado.
- El formulario también tendrá un botón "Ver stock" que publicará por consola todos los instrumentos cargados.
- Los Instrumentos tendrán los siguientes atributos: marca, precio, cantidad_de_cuerdas, cantidad_de_teclas, metal_usado.
- Cuando en el QComboBox se seleccione Guitarra, se deberá permitir ingresar sólo la marca, el precio y la cantidad de cuerdas.

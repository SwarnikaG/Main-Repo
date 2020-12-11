Open your computer’s terminal. Change the current directory to the folder where you save your documents or projects. Enter the following commands to create a new project folder and initialize the project. <br>
>mkdir QOD <br>
>cd QOD <br>
>npm init <br>

Next, open the QOD folder in your favorite text editor. Create a folder named bin and add a new file to the bin folder named index.js. Open the index.js file in your text editor and take the code from above. <br>

Open the package.json file in the root of the project in your text editor. Change the main value to bin/index.js. <br>
Add a new key for bin with the following text.

>"bin": { <br>
>     "QOD": "./bin/index.js" <br>
>  }


However, the goal of writing a script like this is to be able to run it from anywhere. You can do that with the npm install command. <br>
>npm install -g .

### OUTPUT

![Alt text](img/QOD_output.png?raw=true "screenshot")

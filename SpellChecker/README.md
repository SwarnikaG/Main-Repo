### Setting up the Project Folder
Name it SpellChecker and make folders for storing js and css

### Steps to run the project (on localhost).
* Download the code or clone it using the link present in top right green button.
* open home.html file in any browser

### Steps to deploy the project (on Heroku).
* Have git installed.
* Sign up for a Heroku account.
* Download the Heroku CLI.
>Go into the root directory of your project.`$ cd projects/SpellChecker` <br>
>Rename index.html file to home.html. `mv index.html home.html` <br>
>Create a new file called index.php in the root directory, and write the following line `echo '<?php include_once("home.html"); ?>' > index.php` <br>
>Create a composer.json file in the root directory and write the following line in it `echo '{}' > composer.json` <br>
>Use git to initialize or create a version of the site `git init` <br>
>Add all the files to the git repository `git add .` <br>
>Commit or save all the changes for our site `git commit -m "deploying static--err, updating files"` <br>
>Login to Heroku on terminal `heroku login
Enter your Heroku credentials:
Email: <YOUR HEROKU EMAIL>
Password: <YOUR HEROKU PASSWORD>` <br>
>create site on Heroku `heroku apps:create WHATEVER_NAME` <br>
>Deploy to Heroku `git push heroku master` <br>
>Once we see remote: Verifying Deploy...done. , we can visit our site at the link shown.

### Description of what the project does
1. On upload of a file, read the file content and display it in the text area.
1. Process the text content and carry out a spell check for every word in the file content.
1. For every word where there's a typo, highlight (or underline in red) the word in red colour.
1. On right click of this highighted word, provide a custom menu which has suggestions in it. On
click of any suggestion, the faulty word should be replaced by a right one.
1. Host your project on Heroku : https://swarnika-spellchecker.herokuapp.com/

### Screenshots
>On right-click you can see suggestions to incorrect words <br>

![Alt text](SpellChecker/img/showing-suggestions.png?raw=true "Optional Title")

>If you select any word from the suggestions, it will be relaced with the incorrect word. <br>

![Alt text](SpellChecker/img/corrections.png?raw=true "Optional Title")


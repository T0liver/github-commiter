# GitHub Commiter
A code which can be run with cron job and commit to github every day.

I'm trying to write it in more and more languages so there will be not just the main branch and if so it will be not up-to-date as I don't want to mix the languages.

## Useage
1. Fork this repository.
2. Clone this to your local computer/laptop which you use daily.
3. Build the executable file from source or download the per-built one and place this into the root of the cloned repository folder.
4. Create a user.txt file and type the following there:
```
your GitHub username
your GitHub e-mail address
```
5. (optional) reset counter
6. (optional) Run it as test and check it if on GitHub the changes (incr. counter) made.
7. You're done with configuring the program! Now you have to set a cron job to make a daily activity on GitHub.

## Cron jobs
I'm making Windows and Linux steps as I'm using these two opreating system but whoever uses something else - make a PR with the tutorial, and I'll place it here!

### Windows
We will use task scheduler.
1. Open this *magical application* either by searching for this in the **Start menu** or by pressing *Win+R* and typing the following: `taskschd.msc`
2. Click on the library. At this point I made a new "User" folder here to organize the scripts and to make myself easier to find my own ones but as per you wish.
3. Now click on the *Create task* button in the right panel or by clicking the *Action* in the upper bar and then *Create Task...*.
4. Give it a name like *"Daily GitHub"* or somethig like that.
5. Click on the *Triggers* then create a new one and set when to start. I set mine to 4:20 AM but I'll explain it later.
6. Click on the *Actions* then create a new.
-
  - For the *Program/script* set: `C:\Windows\System32\cmd.exe `
  - *Add arguments*: `/K "C:\github-commiter\GitHubCommiter.exe"` (if you cloned this to the root of *C:* (don't) (this is just an example, the point is to start the program))
  - *Start in* (location) `C:\github-commiter` (again if you cloed this to the root of *C:* (don't). the point is to set the fodler of this program to run it properly)
7. Click on the *Conditions* the deselect the *only if the computer is connected to DC thing as I assume you use your laptop  not just when it's plugged in, and select the network option as for the GitHub push we need network connection.
8. Click on the Settings and select the *Run task as soon as possible after a scheduled start is missed*.
9. OK and save the action.

Now we set 4:20 AM to start every day because it's in the morining, I guess you don't use your PC this early but at the next time, you will power on you computer and log in, the script will run in a pop up shell and does it's job and only once a day as several times it's unnessesary as the little green dots only indicates the amount of collaborations in various repositories.

**You're done!**

### Linux
It's coming I just have to set it up myself and write a tutorial here...

[UNDER CONSTRUCTION]

## Implementations
Here is the list of the current implementations with links to the braches:

### C
- [version-in-c](https://github.com/T0liver/github-commiter/tree/version-in-c)

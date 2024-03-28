<!DOCTYPE html>
<html>
<head>
    <title>Create File</title>
    <script>
        function createFile() {
            var filePath = prompt("Create file (please enter the path to file):");
            
            if (filePath) {
                var fileExists = checkFileExists(filePath);
                
                if (fileExists) {
                    var useFile = confirm("File already exists! Do you want to use this file?");
                    
                    if (useFile) {
                        var file = openFile(filePath, "a");
                        var eraseContent = confirm("Do you want to erase all content?");
                        
                        if (eraseContent) {
                            console.log("Erasing...");
                            file.seek(0);
                            file.truncate();
                        }
                    } else {
                        return;
                    }
                } else {
                    console.log("Creating new file...");
                    var file = openFile(filePath, "a");
                    var run = true;
                    
                    while (run) {
                        var line = prompt();
                        file.write(line);
                        file.write('\n');
                        
                        if (keyboardInterrupt) {
                            break;
                        }
                    }
                }
                
                file.close();
            }
        }
        
        function checkFileExists(filePath) {
            // Check if file exists
            // Return true if file exists, false otherwise
        }
        
        function openFile(filePath, mode) {
            // Open file with specified mode
            // Return file object
        }
    </script>
</head>
<body>
    <button onclick="createFile()">Create File</button>
</body>
</html>

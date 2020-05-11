using System;
using System.IO;
using System.Collections.Generic;
using System.Runtime.InteropServices;

/// <summary>
/// Namespace <c>MiraLib</c> contains all the necessary classes and functions for managing consoles on the PC side for applications to use.
/// </summary>
namespace MiraLib
{
    /// <summary>
    /// Class <c>Manage</c> exposes functions for adding and selecting consoles from command line or embedded context.
    /// </summary>
    public static class Manage
    {
        /// <summary>
        /// private static Console <c>currentConsole</c> holds the currently active console. Set by <c>setCurrentConsole</c>.
        /// </summary>
        private static Console currentConsole = null;

        /// <summary>
        /// public static string <c>pathToConsoleListing</c> contains the path of the file containing the console listing.
        /// </summary>
        public static string pathToConsoleListing;

        /// <summary>
        /// static <c>Manage</c> is a static constructor which will initialize <c>pathToConsoleListing</c> based on the platform at runtime.
        /// </summary>
        static Manage()
        {
            // Check if the platform is windows to see if we can use appdata, or linux for using ~/
            if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
            {
                pathToConsoleListing = Path.Combine(Environment.GetEnvironmentVariable("LocalAppData"), "PS4Assistant", "consoles.list");
            }
            else
            {
                pathToConsoleListing = Path.Combine(Environment.GetEnvironmentVariable("HOME"), ".PS4Assistant", "consoles.list");
            }
        }

        /// <summary>
        /// public static List <c>GetListOfConsoles</c> gets the list of consoles that are tracked and returns them.
        /// </summary>
        /// <returns>List of Console objects.</returns>
        public static List<Console> GetListOfConsoles()
        {
            string line;
            List<Console> listOfConsoles = new List<Console>();

            // If a file doesn't exist for the console list, create one
            checkConsoleListFileExists();

            // Read the console file for new entries
            using (FileStream stream = new FileStream(pathToConsoleListing, FileMode.Open, FileAccess.Read, FileShare.Read, 4096, FileOptions.SequentialScan))
            {
                using (StreamReader file = new StreamReader(stream, false))
                {
                    while ((line = file.ReadLine()) != null)
                    {
                        // Parse the line, format is "name:ip"
                        string[] consoleInfo = line.Split(':');

                        Console console = new Console();
                        console.SetName(consoleInfo[0]);
                        console.SetIPAddress(consoleInfo[1]);

                        listOfConsoles.Add(console);
                    }
                }
            }

            return listOfConsoles;
        }

        /// <summary>
        /// public static bool <c>AddConsole</c> takes a given name and IP address, and attempts to add it to the list of consoles that are tracked. Returns true
        /// if the console was added, false otherwise (such as if the IP address is incorrect).
        /// </summary>
        /// <param name="name">Name of the console to add.</param>
        /// <param name="ip">IPv4 address of the console to add.</param>
        /// <returns>True if the console was added successfully, false otherwise.</returns>
        public static bool AddConsole(string name, string ip)
        {
            Console newConsole = new Console();
            newConsole.SetName(name);

            if (newConsole.SetIPAddress(ip))
            {
                // If a file doesn't exist for the console list, create one
                checkConsoleListFileExists();

                // Add the console to the file
                using (FileStream stream = new FileStream(pathToConsoleListing, FileMode.Append, FileAccess.Write, FileShare.Read, 4096, FileOptions.SequentialScan))
                {
                    using (StreamWriter file = new StreamWriter(stream, System.Text.Encoding.UTF8))
                    {
                        file.WriteLine(newConsole.GetName() + ":" + newConsole.GetIPAddress());
                    }
                }

                return true;
            }

            return false;
        }

        /// <summary>
        /// public static bool <c>RemoveConsole</c> takes a given name and attempts to remove it from the list of consoles that are tracked. Returns true
        /// if the console was removed, false otherwise (such as if the name isn't in the list).
        /// </summary>
        /// <param name="name">Name of the console to remove.</param>
        /// <returns>True if the console could be removed, false otherwise.</returns>
        public static bool RemoveConsole(string name)
        {
            bool foundAndRemoved = false;
            List<string> linesToWrite = new List<string>();

            // Remove it from the console list file
            using (FileStream stream = new FileStream(pathToConsoleListing, FileMode.Open, FileAccess.Read, FileShare.Read, 4096, FileOptions.SequentialScan))
            {
                using (StreamReader reader = new StreamReader(stream, true))
                {
                    string line;

                    while ((line = reader.ReadLine()) != null)
                    {
                        string consoleNameCandidate = line.Split(':')[0];

                        if (String.Compare(consoleNameCandidate, name) == 0)
                        {
                            foundAndRemoved = true;
                            continue;
                        }

                        linesToWrite.Add(line);
                    }
                }
            }

            // Rewrite the file
            using (FileStream stream = new FileStream(pathToConsoleListing, FileMode.Create, FileAccess.Write, FileShare.Read, 4096, FileOptions.SequentialScan))
            {
                using (StreamWriter writer = new StreamWriter(stream, System.Text.Encoding.UTF8))
                {
                    foreach (string line in linesToWrite)
                    {
                        writer.WriteLine(line);
                    }
                }
            }

            return foundAndRemoved;
        }

        /// <summary>
        /// public static method <c>SetCurrentConsole</c> sets the currently active console to the given <c>console</c>.
        /// </summary>
        /// <param name="console">Console object to set as the active console.</param>
        /// <returns>void.</returns>
        public static void SetCurrentConsole(Console console)
        {
            currentConsole = console;
        }

        /// <summary>
        /// public static method <c>GetCurrentConsole</c> returns the currently active console.
        /// </summary>
        /// <returns>Currently active console object.</returns>
        public static Console GetCurrentConsole()
        {
            return currentConsole;
        }

        /// <summary>
        /// private static method <c>checkConsoleListFileExists</c> will check if the file exists for the console listing, and will create it if it does not already exist.
        /// </summary>
        /// <returns>void.</returns>
        private static void checkConsoleListFileExists()
        {
            if (!File.Exists(pathToConsoleListing))
            {
                Directory.CreateDirectory(Path.GetDirectoryName(pathToConsoleListing));
                File.Create(pathToConsoleListing).Dispose();
            }
        }
    }
}

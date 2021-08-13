// This file contains the entire program for create-gp4 since it's relatively trivial.

package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"os"
	"strings"
	"time"
)

// errorExit function will print the given formatted error to stdout and exit immediately after.
func errorExit(format string, params ...interface{}) {
	fmt.Printf(format, params...)
	os.Exit(-1)
}

// parseFilesToTags takes a list of files as a space-deliminated string and parses it into a list of tags for the GP4 XML.
// Returns the list of XML tags for the files.
func parseFilesToTags(files []string) []string {
	var fileTags []string

	for _, file := range files {
		if file != "" {
			fileTags = append(fileTags, fmt.Sprintf("\t\t<file targ_path=\"%s\" orig_path=\"%s\" />", file, file))
		}
	}

	return fileTags
}

// createGP4 takes a set of values and constructs a .gp4 file and writes it to the given path. Returns an error if creation
// failed, nil otherwise.
func createGP4(path string, contentID string, files string) error {
	currentTime := time.Now().Format("2006-01-02 15:04:05")

	fileList := strings.Split(files, " ")
	fileTagList := parseFilesToTags(fileList)
	fileTags := strings.Join(fileTagList, "\n")

	gp4Contents := fmt.Sprintf("<?xml version=\"1.0\"?>\n"+
		"<psproject xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" fmt=\"gp4\" version=\"1000\">\n"+
		"\t<volume>\n"+
		"\t\t<volume_type>pkg_ps4_app</volume_type>\n"+
		"\t\t<volume_id>PS4VOLUME</volume_id>\n"+
		"\t\t<volume_ts>%s</volume_ts>\n"+
		"\t\t<package content_id=\"%s\" passcode=\"00000000000000000000000000000000\"\n"+
		"\t\t\tstorage_type=\"digital50\" app_type=\"full\" />\n"+
		"\t\t<chunk_info chunk_count=\"1\" scenario_count=\"1\">\n"+
		"\t\t\t<chunks>\n"+
		"\t\t\t\t<chunk id=\"0\" layer_no=\"0\" label=\"Chunk #0\" />\n"+
		"\t\t\t</chunks>\n"+
		"\t\t\t<scenarios default_id=\"0\">\n"+
		"\t\t\t\t<scenario id=\"0\" type=\"sp\" initial_chunk_count=\"1\" label=\"Scenario #0\">0</scenario>\n"+
		"\t\t\t</scenarios>\n"+
		"\t\t</chunk_info>\n"+
		"\t</volume>\n"+
		"\t<files img_no=\"0\">\n"+
		"%s"+
		"\t</files>\n"+
		"\t<rootdir>\n"+
		"\t\t<dir targ_name=\"sce_sys\">\n"+
		"\t\t\t<dir targ_name=\"about\" />\n"+
		"\t\t</dir>\n"+
		"\t\t<dir targ_name=\"sce_module\" />\n"+
		"\t\t<dir targ_name=\"assets\">\n"+
		"\t\t\t<dir targ_name=\"audio\" />\n"+
		"\t\t\t<dir targ_name=\"fonts\" />\n"+
		"\t\t\t<dir targ_name=\"images\" />\n"+
		"\t\t\t<dir targ_name=\"misc\" />\n"+
		"\t\t\t<dir targ_name=\"videos\" />\n"+
		"\t\t</dir>\n"+
		"\t</rootdir>\n"+
		"</psproject>", currentTime, contentID, fileTags)

	return ioutil.WriteFile(path, []byte(gp4Contents), 0644)
}

func main() {
	// Required flags
	outputFilePathPtr := flag.String("out", "homebrew.gp4", "`output gp4` to write to")
	contentIDPtr := flag.String("content-id", "", "content ID of the package")
	contentFilesPtr := flag.String("files", "", "list of files to pack into the package")

	flag.Parse()

	outputFilePath := *outputFilePathPtr
	contentID := *contentIDPtr
	contentFiles := *contentFilesPtr

	if contentID == "" {
		errorExit("Content ID not specified, try -content-id=[content ID]\n")
	}

	if contentFiles == "" {
		errorExit("Content files not specified, try -files=\"[files, separated by spaces]\"\n")
	}

	if err := createGP4(outputFilePath, contentID, contentFiles); err != nil {
		errorExit("Error writing GP4: %s\n", err.Error())
	}
}

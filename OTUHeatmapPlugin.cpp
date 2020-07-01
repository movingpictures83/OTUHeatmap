#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "OTUHeatmapPlugin.h"

void OTUHeatmapPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }

}

void OTUHeatmapPlugin::run() {
   
}

void OTUHeatmapPlugin::output(std::string file) {
//beta_diversity.py -i filtered_otu_table.biom -m euclidean,weighted_unifrac,unweighted_unifrac -t rep_set.tre -o beta_div
   std::string command = "export OLDPATH=${PYTHONPATH}; export PYTHONPATH=${PYTHON2_LIB_DIR}:${PYTHON2_DIST_PACKAGES}:${PYTHON2_SITE_PACKAGES}:${PYTHONPATH}; rm -rf "+file+"; make_otu_heatmap.py";
 command += " -i "+parameters["otutable"];
 if (parameters.count("mapping") != 0)
    command += " -m "+parameters["mapping"];
 if (parameters.count("tree") != 0)
    command += " -t "+parameters["tree"];
 command += " -o "+file+"; cp -r "+file+"/* "+file+"/..; export PYTHONPATH=OLDPATH"; 

   //std::string command = "export OLDPATH=${PYTHONPATH}; export PYTHONPATH=${PYTHON2_DIST_PACKAGES}:${PYTHON2_SITE_PACKAGES}:${PYTHONPATH}; make_otu_heatmap.py ";
 //command += "-i "+inputfile+" -o "+file;
 std::cout << command << std::endl;
 system(command.c_str());
}

PluginProxy<OTUHeatmapPlugin> OTUHeatmapPluginProxy = PluginProxy<OTUHeatmapPlugin>("OTUHeatmap", PluginManager::getInstance());

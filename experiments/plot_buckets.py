import csv
import glob
import os
import sys
import matplotlib.pyplot as plt

types = ['int32', 'int64', 'double', 'float']

def csv_dict_reader(file_obj, type_elemets):
    stats = {}
    stats['Method'] = ''
    stats['Type'] = ''
    stats['Sizes'] = []
    stats['Times'] = []
    reader = csv.DictReader(file_obj, delimiter=',')
    for line in reader:
        stats['Method'] = line['Method']
        stats['Type'] = type_elemets
        if(line['Type'] == type_elemets):
            stats['Sizes'].append(line['Size'])
            stats['Times'].append(line['Time'])
    return stats

def GetAllStats(csv_folder):
    source_files = sorted(glob.glob(os.path.join(csv_folder, '*.csv')))
    stats = []
    for file in source_files:
        for type_element in types:
            with open(file, 'r') as file_obj:
                stats.append(csv_dict_reader(file_obj, type_element))
    return stats

def add_lines(stats, type_element):
    for stat in stats:
        if (stat['Type'] == type_element):
            x = stat['Sizes']
            y = stat['Times']
            lable = stat['Method']
            plt.plot(x, y, 'o-', label = lable)

def plot_sorts(stats, csv_folder, filename_path):
    plot_count = 1;
    plt.figure(figsize=(14, 11), dpi=100)
    for type_element in types:
        ax = plt.subplot(2, 2, plot_count)
        #ax.set_xscale('log')
        for i in stats:
            add_lines(i, type_element)
        plt.legend()
        plt.xlabel('Size') 
        plt.ylabel('Time, s') 
        plt.title('Sorts ' + type_element)
        plt.grid(True)
        plot_count += 1
    plt.savefig(filename_path, dpi=300)
    plt.show()
    
def main():
    csv_folders = ['BucketInsertion', 'BucketStandart', 'BucketInsertionAdaptiv']
    filename = "OptimalBucket.png"
    filename_path = filename
    stats = []
    for folder in csv_folders:
    	stats.append(GetAllStats(folder))
    plot_sorts(stats, csv_folders, filename_path)

if __name__ == '__main__':
    main()

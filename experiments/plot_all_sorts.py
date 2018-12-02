import argparse
import csv
import glob
import os
import sys
import matplotlib.pyplot as plt

types = ['int32', 'int64', 'double', 'float']
metods = ['Bubble','BucketInsertion', 'BucketStandart', 'Heap', 'Merge', 'Quick', 'QuickLomuto', 'SearchTree', 'Standart']

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
    source_files = sorted(glob.glob(os.path.join(csv_folder, 'run.csv')))
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


def add_plot(stats):
    plot_count = 1;
    for type_element in types:
        ax = plt.subplot(2, 2, plot_count)
        #ax.set_xscale('log')
        add_lines(stats, type_element)
        plt.legend()
        plt.xlabel('Size') 
        plt.ylabel('Time, s') 
        plt.title('Sorts ' + type_element)
        plt.grid(True)
        plot_count += 1
    
def main():
    filename = "all_metods.png"
    plt.figure(figsize=(14, 11), dpi=100)
    for metod in metods:
        stats = GetAllStats(metod)
        add_plot(stats)
    plt.savefig(filename, dpi=300)
    plt.show()

if __name__ == '__main__':
    main()

    

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

struct FASTA_Seq {
	std::string name;
	std::string data;
};

int ParseArgs(int argc, char **argv, std::string &inPath, std::string &outPath, int &lettersPerLine) {
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-i") == 0) {
			if (i >= argc) {
				std::cerr << "Argument overflow\n";
				return -1;
			}
			inPath = argv[++i];
			continue;
		}
		if (strcmp(argv[i], "-o") == 0) {
			if (i >= argc) {
				std::cerr << "Argument overflow\n";
				return -1;
			}
			outPath = argv[++i];
			continue;
		}
		if (strcmp(argv[i], "-l") == 0) {
			if (i >= argc) {
				std::cerr << "Argument overflow\n";
				return -1;
			}
			lettersPerLine = std::stoi(std::string(argv[++i]));
			continue;
		}
	}
	return 0;
}

int GetSequences(const std::string &path, std::vector<FASTA_Seq> &sequences) {
	if (!std::filesystem::exists(path)) {
		std::cerr << "Input file does not exist\n";
		return -1;
	}
	std::ifstream inFile(path);
	if (!inFile.is_open()) {
		std::cout << "Failed to open input file " << path << "\n";
		return -1;
	}

	std::string lineBuff;
	FASTA_Seq currentSeq;
	while (std::getline(inFile, lineBuff)) {
		if (lineBuff.empty()) continue;
		if (lineBuff[0] == '>') {
			if (!currentSeq.name.empty()) {
				sequences.push_back(currentSeq);
				currentSeq = FASTA_Seq();
			}
			currentSeq.name = lineBuff.substr(1);
		} else {
			currentSeq.data.append(lineBuff);
		}
	}
	if (!currentSeq.name.empty()) { sequences.push_back(currentSeq); }
	return 0;
}

int WritePrettyPrint(const std::vector<FASTA_Seq> &sequences, const std::string &path, int lettersPerLine) {
	std::ofstream outFile(path);
	if (!outFile.is_open()) {
		std::cout << "Failed to open output file " << path << "\n";
		return -1;
	}

	for (const auto &seq : sequences) {

		outFile << seq.name << "\n";

		for (int i = 0; i < seq.data.size(); i += lettersPerLine) {
			outFile << std::setw(8) << i << "\t";
			for (int j = 0; j < lettersPerLine; j += 10) {
				for (int k = 0; k < 10; k++) {
					if (i + j + k >= seq.data.size()) { break; }
					outFile << seq.data[i + j + k];
				}
				outFile << " ";
			}
			outFile << "\n";
		}
		outFile << "\n";
	}
	return 0;
}

int main(int argc, char **argv) {
	std::string inPath;
	std::string outPath;
	int lettersPerLine = 100;
	if (ParseArgs(argc, argv, inPath, outPath, lettersPerLine) < 0) { return -1; }

	if (lettersPerLine % 10 != 0) {
		lettersPerLine = (lettersPerLine / 10) * 10;
		std::cerr << "lettersPerLine must be a multiple of 10. Adjusting to " << (lettersPerLine / 10) * 10 << "\n";
	}

	std::vector<FASTA_Seq> sequences;
	if (GetSequences(inPath, sequences) < 0) { return -1; };
	int res = WritePrettyPrint(sequences, outPath, lettersPerLine);
	if (res >= 0) { std::cout << "Successfully written pretty text to: " << outPath << "\n"; }
	return res;
}
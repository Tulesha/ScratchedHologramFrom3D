#pragma once

#include <fstream>
#include "IVectorGraphicsDataWriter.hpp"

namespace File2DProcessingTools {

    /**
     * Writes points to svg file
     * @author Nikita Novgorodtsev (github <https://github.com/paNoNi>)
     */
    class CSvgFileWriter : public IVectorGraphicsDataWriter {
    private:
        unsigned int _height = 0;
        unsigned int _width = 0;
        double scale = 1;

    public:

        CSvgFileWriter() noexcept = default;

        /**
         * Constructor for adjusting canvas size
         * @param height -canvas height
         * @param width - canvas width
         */
        CSvgFileWriter(unsigned int height, unsigned int width) noexcept;

        /**
         * The main method of writing points to a file
         * @param filepath - File Path (* .svg)
         * @param data - point storage
         * @param write_force - parameter that defines actions when there is a file on a given path (true - overwrite,
         * false - do not overwrite)
         */
        void write(std::string filepath, const CVectorGraphicsData &data, bool write_force) override;

        /**
        * The main method of writing points to a file
        * @param filepath - File Path (* .svg)
        * @param data - vector of point storage
        * @param write_force - parameter that defines actions when there is a file on a given path (true - overwrite,
        * false - do not overwrite)
        */
        void writeMul(std::string filepath, const std::vector<CVectorGraphicsData> &data, bool write_force) override;


    private:

        void writeBeginning(std::ofstream &svg_file);

        static void writeEnding(std::ofstream &svg_file);

        void writePoints(const File2DProcessingTools::CVectorGraphicsData &data,
                         std::ofstream &svg_file, std::pair<double, double> max, std::pair<double, double> min);

        static bool isFileExists(const std::string &filepath, bool write_force);

        double scaling(unsigned int height, unsigned int width);

        static void tryOpenFile(const std::string &filepath, std::ofstream &svg_file, bool write_force);

        void updateWidthHeight(std::pair<double, double> max, std::pair<double, double> min);

        static std::pair<double, double> getMaxXY(const std::vector<CVectorGraphicsData> &data);

        static std::pair<double, double> getMinXY(const std::vector<CVectorGraphicsData> &data);

    };

}
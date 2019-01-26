/* BOYER Johan, KOHLMULLER Amandine, 26/01/2019 */
#ifndef HISTO_H__
#define HISTO_H__

/// \brief create the histogramme in an array.
/// \param image: pointer on the Image.
/// \param histo: pointer on the histogram.
void createHisto(Image * image, int *histo);

/// \brief create the graph of the histogram and save in .ppm.
/// \param histo: pointer on the histogram.
/// \return EXIT_FAILURE in case of problem, else EXIT_SUCCESS.
int histoPPM(int *histo);

#endif
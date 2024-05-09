## AliceVision
## Pipeline softwares

# Software PROPERTY FOLDER is 'Software/Pipeline'
set(FOLDER_SOFTWARE_PIPELINE "Software/Pipeline")

alicevision_add_software(aliceVision_distortionCalibration
    SOURCE main_distortionCalibration.cpp
    FOLDER ${FOLDER_SOFTWARE_PIPELINE}
    LINKS aliceVision_dataio
            aliceVision_image
            aliceVision_calibration
            aliceVision_system
            aliceVision_cmdline
            aliceVision_sfmDataIO
            Boost::program_options
            Boost::boost
            Boost::json
)

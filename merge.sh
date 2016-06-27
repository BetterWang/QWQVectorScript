hadd -f txt/HIMB_1234_v1/output.root txt/HIMB2_v1/output.root txt/HIMB3_v1/output.root txt/HIMB4_v1/output.root
hadd -f txt/HIMB_1234_randq_v1/output.root txt/HIMB2_randq_v1/output.root txt/HIMB3_randq_v1/output.root txt/HIMB4_randq_v1/output.root

root -l -b -q "rebin.C(7)"
root -l -b -q "rebin.C(13)"

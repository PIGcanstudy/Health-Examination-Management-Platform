import {defineStore} from 'pinia'
import {ref} from 'vue'

import{
    ReportList,
    downloadReportDetail,
    modifyReportReview,
} from '@/apis/inspectionreport/index.js'

export const useinspectionreportStore = defineStore('inspectionreport',() => {
    //重写方法
    const getReportList = async (params) => {
        return await ReportList(params)
    }

    const getdownloadReportDetail = async (params) => {
        return await downloadReportDetail(params)
    }

    const putmodifyReportReview = async (params) => {
        return await modifyReportReview(params)
    }

    //暴露出的数据
    return{
        getReportList,
        getdownloadReportDetail,
        putmodifyReportReview
    }
})